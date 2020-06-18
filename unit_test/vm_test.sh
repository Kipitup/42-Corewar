#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
RES="\033[0m"
err=0;

#arg1 = cmd to output to champ1, arg2 = cmd champ2

create_test_champ ()
{
	if [ ! -e test_champ1.s ]
	then
		touch test_champ1.s;
	fi
	if [ ! -e test_champ2.s ]
	then
		touch test_champ2.s
	fi
	printf ".name		\"Test_champ1\"\n.comment	\"I find bugs\"\n\n" > test_champ1.s;
	printf ".name		\"Test_champ2\"\n.comment	\"I find bugs\"\n\n" > test_champ2.s;
	printf "$1" >> test_champ1.s;
	printf "$2" >> test_champ2.s;
	./asm_official test_champ1.s > /dev/null;
	./asm_official test_champ2.s > /dev/null;
}

#arg1 = exec_name, arg2 = message, arg3 = cycle_to_dump

check_diff ()
{
	./corewar_official -d $3 test_champ1.cor test_champ2.cor | sed 1,3d | sed s/'0x.... : '// | xargs -n32 > output_of;
	$1 -dump $3 test_champ1.cor test_champ2.cor | sed 1,3d | sed s/'0x.... : '// > output_ours;
	EX="$(cmp -s output_of output_ours; echo $?)"
	if [ $EX != 0 ]
	then
		printf "$RED$2 KO\n$RES";
		cmp -l output_of output_ours;
		cp test_champ1.s "error"$err"a.s";
		cp test_champ2.s "error"$err"b.s";
		let "err=err+1";
	else
		printf "$GREEN$2 OK\n$RES";
	fi
}

#arg1 = exec_name

fork_fun ()
{
	cmd=( "fork %%:label\nst r1, 5\nst r1, 5\nlabel: st r1, 5\n" 
		"fork %%:label\nst r1, 5\nst r1, 5\nlabel: st r1, 5\n" 
		"fork %%2048\nst r1, 5\nst r1, 5\n" 
		"fork %%2048\nst r1, 5\nst r1, 5\n" 
		"lfork %%2048\nst r1, 5\nst r1, 5\n"
                "lfork %%2048\nst r1, 5\nst r1, 5\n" )
	cmd2=( "st r1, -5\n" "st r1, -5\n" "st r1, -5\n" 
	"st r1, -5\n" "st r1, -5\n" "st r1, -5\n" )
	mess=( "fork < IDX_MOD 1/2" "fork < IDX_MOD 2/2" "fork > IDX_MOD 1/2" "fork > IDX_MOD 2/2" "lfork 1/2" "lfork 2 /2" )
	dump=( "50" "820" "50" "820" "50" "1020" )
	printf ""$BLUE"\nTesting fork and long fork...\n\n$RES";
	for i in `seq 0 5`
	do
		create_test_champ "${cmd[i]}" "${cmd2[i]}";
		check_diff "$1" "${mess[i]}" "${dump[i]}";
	done
}

st_fun ()
{
	cmd=( "st r1, 20\n" "st r1, 500\n" "st r1, r2\nst r2, 20\n" "sti r1,r2,%%800\n" "sti r1,r2,r3\n" "sti r1,200,%%5\n" )
	mess=( "st reg, ind" "st reg, ind > IDX_MOD" "st reg reg" "sti reg reg dir" "sti reg reg reg" "sti reg ind dir" )
	printf ""$BLUE"\nTesting st, sti...\n\n$RES";
	for i in `seq 0 5`
	do
		create_test_champ "${cmd[i]}" "${cmd[i]}";
		check_diff "$1" "${mess[i]}" "150";
	done
}

ld_fun ()
{
        cmd=( "ld %%15263, r2\nst r2, 5\n" "ld 0, r3\nst r3, 50\n" "st r1, 511\nst r1, 511\nld 512, r4\nst r4, 50\n" "ld %%0, r5\nzjmp %%10\nst r1, 5\n" 
		"lld %%4578, r2\nst r2, 5\n" "lld %%0, r5\nzjmp %%10\nst r1, 5\n" 
		"ldi %%1, %%2, r2\n st r2, -20\n" "ldi 5, r2, r3\nst r3, -50\n" "ldi 600, %%852, r2\nst r2, 32\n" "ldi %%0, %%0, r2\nzjmp %%10\nst r1, -12\n" 
		"lldi %%1, %%2, r2\n st r2, -20\n" "lldi 5, r2, r3\nst r3, -50\n" "lldi 600, %%852, r2\nst r2, 32\n" "lldi %%0, %%0, r2\nzjmp %%10\nst r1, -12\n" )
        mess=( "ld dir reg" "ld ind < IDX_MOD reg" "ld ind > IDX_MOD reg" "ld check carry" "lld dir reg" "lld check carry" 
		"ldi dir dir reg" "ldi ind < IDX_MOD reg reg" "ldi ind > IDX_MOD dir reg" "ldi check carry" 
		"lldi dir dir reg" "lldi ind < IDX_MOD reg reg" "lldi ind > IDX_MOD dir reg" "lldi check carry" )
        printf ""$BLUE"\nTesting ld, lld, ldi, lldi...\n\n$RES";
        for i in `seq 0 13`
        do
                create_test_champ "${cmd[i]}" "${cmd[i]}";
                check_diff "$1" "${mess[i]}" "100";
        done
}

binary_fun ()
{
        cmd=( "ld %%456123, r2\nand r1,r2,r3\nst r3, 20\n" "and %%1024, 2, r2\nst r2, 23\n" "and r1, 2048, r2\nst r2, 26\n" "and %%0, %%0, r2\nzjmp %%-11\nst r1, -13\n" "and %%1, %%1, r2\nzjmp %%-11\nst r1, -13\n" 
	"ld %%456123, r2\nor r1,r2,r3\nst r3, 20\n" "or %%1024, 2, r2\nst r2, 23\n" "or r1, 2048, r2\nst r2, 26\n" "or %%0, %%0, r2\nzjmp %%-11\nst r1, -13\n" "or %%1, %%1, r2\nzjmp %%-11\nst r1, -13\n" 
	"ld %%456123, r2\nxor r1,r2,r3\nst r3, 20\n" "xor %%1024, 2, r2\nst r2, 23\n" "xor r1, 2048, r2\nst r2, 26\n" "xor %%0, %%0, r2\nzjmp %%-11\nst r1, -13\n" "xor %%0, %%1, r2\nzjmp %%-11\nst r1, -13\n" )
        mess=( "and reg reg reg" "and dir ind reg" "and reg ind > IDX_MOD reg" "and check carry 1" "check carry 0" 
	"or reg reg reg" "or dir ind reg" "or reg ind > IDX_MOD reg" "or check carry 1" "check carry 0" 
	"xor reg reg reg" "xor dir ind reg" "xor reg ind > IDX_MOD reg" "xor check carry 1" "check carry 0" )
        printf ""$BLUE"\nTesting and, or, xor...\n\n$RES";
        for i in `seq 0 14`
        do
                create_test_champ "${cmd[i]}" "${cmd[i]}";
                check_diff "$1" "${mess[i]}" "100";
        done
}

jump_fun ()
{
        cmd=( "ld %%33640451,r2\nst r2, -7\nand %%0,%%0,r3\nzjmp %%-23\n" "and %%0, %%0, r3\nzjmp %%8\nst r1, 5\n" "and %%0, %%0, r3\nzjmp %%8\nst r1, 5\n" )
        mess=( "jump backwards" "jump forward" "no jump" )
        printf ""$BLUE"\nTesting jump...\n\n$RES";
        for i in `seq 0 2`
        do
                create_test_champ "${cmd[i]}" "${cmd[i]}";
                check_diff "$1" "${mess[i]}" "100";
        done
}

add_sub_fun ()
{
        cmd=( "ld %%789, r5\nld %%789456, r6\nadd r5,r6,r10\nst r10, 13\n" "ld %%789, r5\nld %%-789456, r6\nadd r5,r6,r10\nst r10, 13\n" 
	"ld %%5, r5\nld %%-5, r6\nadd r5,r6,r10\nst r10, 13\nzjmp %%-24\nst r1, -29\n" "ld %%5, r5\nld %%-18, r6\nadd r5,r6,r10\nst r10, 13\nzjmp %%-24\nst r1, -29\n" 
	"ld %%789, r5\nld %%789456, r6\nsub r5,r6,r10\nst r10, 13\n" "ld %%789, r5\nld %%-789456, r6\nsub r5,r6,r10\nst r10, 13\n"
        "ld %%5, r5\nld %%5, r6\nsub r5,r6,r10\nst r10, 13\nzjmp %%-24\nst r1, -29\n" "ld %%5, r5\nld %%-18, r6\nsub r5,r6,r10\nst r10, 13\nzjmp %%-24\nst r1, -29\n" )
        mess=( "add simple" "add neg" "add check carry 1" "add check carry 0" 
		"sub simple" "sub neg" "sub check carry 1" "sub check carry 0" )
        printf ""$BLUE"\nTesting add, sub...\n\n$RES";
        for i in `seq 0 7`
        do
                create_test_champ "${cmd[i]}" "${cmd[i]}";
                check_diff "$1" "${mess[i]}" "100";
        done
}

live_aff ()
{
	create_test_champ "live %%-2\nand %%0, %%0, r2\nzjmp %%-16\n" "st r1, 5\n";
	LIVE=$($1 test_champ1.cor test_champ2.cor | sed 1,3d | sed /'^A process'/d);
	if [ "$LIVE" == "Player 2 (Test_champ2) won" ]
	then
		printf ""$GREEN"live 1/2 OK"$RES"\n"
	else
		printf ""$RED"live 1/2 KO"$RES"\n"
	fi
	create_test_champ "st r1, 5\n" "live %%-1\nand %%0, %%0, r2\nzjmp %%-16\n";
        LIVE=$($1 test_champ1.cor test_champ2.cor | sed 1,3d | sed /'^A process'/d);
        if [ "$LIVE" == "Player 1 (Test_champ1) won" ]
        then
                printf ""$GREEN"live 2/2 OK"$RES"\n"
        else
                printf ""$RED"live 2/2 KO"$RES"\n"
        fi
	create_test_champ "aff r1\n" "aff r1\n";
	OURS=$($1 test_champ1.cor test_champ2.cor | grep --binary-files=text '^Aff');
	OF=$(./corewar_official -a test_champ1.cor test_champ2.cor | grep --binary-files=text '^Aff');
	if [ "$OURS" == "$OF" ]
	then
		printf ""$GREEN"aff OK\n"$RES"";
	else
		printf ""$RED"aff KO\n"$RES"";
	fi
}

if [ ! $1 ]
then
	printf "usage ./vm_test.sh ./corewar_exec\n";
	exit ;
fi
if [ ! -e ./corewar_official ]
then
	printf "Need official corewar executable for comparison\n"
	exit
fi
if [ ! -e ./asm_official ]
then
	printf "Asm executable missing\n"
	exit
fi
st_fun $1;
ld_fun $1;
jump_fun $1;
fork_fun $1;
binary_fun $1;
add_sub_fun $1;
live_aff $1;
rm test_champ1.s test_champ1.cor test_champ2.s test_champ2.cor output_of output_ours;
