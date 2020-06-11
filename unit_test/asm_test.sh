#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
RES="\033[0m"
err=0;

create_test_champ ()
{
	printf ".name		\"Test_champ\"\n.comment	\"I find bugs\"\n\n" > test_champ.s;
	printf "$1" >> test_champ.s;
}

check_diff ()
{
	$1 test_champ.s > /dev/null 2>&1 ;
	mv test_champ.cor output_ours.cor;
	./asm_official test_champ.s > /dev/null 2>&1 ;
	mv test_champ.cor output_of.cor;
	EX="$(cmp -s output_of.cor output_ours.cor; echo $?)"
        if [ $EX != 0 ]
        then
                printf "$RED$2 KO\n$RES";
                cmp -l output_of.cor output_ours.cor;
                cp test_champ.s "error"$err".s";
                let "err=err+1";
        else
                printf "$GREEN$2 OK\n$RES";
        fi
}

check_diff_inv ()
{
	EX_OURS="$($1 test_champ.s > /dev/null 2>&1 ; echo $?)"
	EX_OF="$(./asm_official test_champ.s > /dev/null 2>&1 ; echo $?)"
        if [ "$EX_OF" != "$EX_OURS" ]
        then
                printf "$RED$2 KO\n$RES";
                cp test_champ.s "error"$err".s";
                let "err=err+1";
        else
                printf "$GREEN$2 OK\n$RES";
        fi
}

check_valid ()
{
	cmd=( "live %%-1\n" "live %%:label\nlabel: live %%-1\n" 
		"st r1,r2\n" "st r1,-32\n" 
		"add r1,r2,r16\n" "sub r12,r23,r4\n" 
		"and r1,r2,r6\n" "and 2048, %%-15, r3\n" "and r6,-15,r1\n" 
		"or r1,r2,r6\n" "or 2048, %%-15, r3\n" "or r6,-15,r1\n" 
		"xor r1,r2,r6\n" "xor 2048, %%-15, r3\n" "xor r6,-15,r1\n" 
		"zjmp %%-15\n" "zjmp %%456\n" 
		"ldi %%4561, %%-89, r1\n" "ldi :label,r3,r4\nlabel: live %%-1\n" "ldi r1,r12,r4\n" 
		"sti r1, :label, %%-15\nlabel: live %%-1\n" "sti r5, %%47, r3\n" 
		"fork %%-14\n" 
		"lld %%0, r5\n" "lld :label,r5\nlabel: live %%-1\n" 
		"lldi %%789, %%-4, r1\n" "lldi 2048,r1,r3\n" "lldi r1,r2,r8\n" 
		"lfork %%:label\nlabel: live %%-1\n" 
		"aff r14\n" 
		)
	mess=( "live" "live with label" 
		"st reg reg" "st reg ind" 
		"add" "sub" 
		"and reg reg reg" "and ind dir reg" "and reg ind reg" 
		"or reg reg reg" "or ind dir reg" "or reg ind reg" 
		"xor reg reg reg" "xor ind dir reg" "xor reg ind reg" 
		"zjmp neg" "zjmp pos"  
		"ldi dir dir reg" "ldi ind (label) reg reg" "ldi reg reg reg" 
		"sti reg ind (label) dir" "sti reg ind reg" 
		"fork" 
		"lld dir reg" "lld ind (label) reg" 
		"lldi dir dir reg" "lldi ind reg reg" "lldi reg reg reg" 
		"lfork dir (label)" 
		"aff" 
		)
	printf ""$BLUE"\nTesting valid files\n\n"$RES"";
	for i in `seq 0 29`
	do
		create_test_champ "${cmd[i]}";
		check_diff "$1" "${mess[i]}";
	done
}

check_invalid ()
{
	cmd=( "and r1 r2 r3\n" "and r1;r2;r3\n" 
		"live %%-1"
		"and r1,r2,r3 live %%-1\n" "" 
		"live %%:label\n;label: live %%-1\n" 
		"live r1\n" 
		"st 23,%%23\n" 
		"add %%-1,%%78\n" 
		"and %%45,%%42,42\n" "and %%42,%%42,%%42\n" 
		"zjmp 12\n" 
		"ldi %%42, 42, r1\n" "ldir %%42, r1, %%42\n" 
		"sti r1, %%42, 42\n" "sti %%42, %%42, %%42\n" 
		"fork r1\n" "fork 42\n" 
		"lld r1, r2\n" 
		"lldi %%42, 42, r1\n" 
		"lfork 42\n" 
		"aff %%42\n" )
	mess=( "no separator between arguments" "wrong separator" 
		"no end of line" 
		"multiple instru per line" "no instruction" 
		"wrong label sign" 
		"live with reg" 
		"st ind dir" 
		"add dir dir" 
		"and dir dir ind" "and dir dir dir" 
		"zjmp ind" 
		"ldi dir ind reg" "ldi dir reg dir" 
		"sti reg dir ind" "sti dir dir dir" 
		"fork reg" "fork ind" 
		"lld reg reg" 
		"lldi dir ind reg" 
		"lfork ind" 
		"aff dir" )
	printf ""$BLUE"\nTesting invalid files\n\n"$RES"";
	for i in `seq 0 21`
	do
		create_test_champ "${cmd[i]}";
		check_diff_inv "$1" "${mess[i]}";
	done
}

if [ ! -e ./asm_official ]
then
	printf "Need official asm exec for comparison\n"
	exit
fi
if [ ! $1 ]
then
	printf "Usage : ./asm_test.sh asm_exec_to_test\n"
	exit
fi
check_valid $1;
check_invalid $1;
rm output_ours.cor output_of.cor test_champ.s
