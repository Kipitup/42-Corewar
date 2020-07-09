# 42-Corewar
This project consists of concepting a VM (recognising instructions, registeries...), a compiler that turns code written into redcode assembly to a binary code that is understood by the VM, and a program that will fight against others inside the same memory space of the VM. 

Subject: [English](https://github.com/ssfar/42-Subjects.pdf/blob/master/corewar.en.pdf) - [Français](https://github.com/ssfar/42-Subjects.pdf/blob/master/corewar.fr.pdf)

Grade 100/100  
Bonus 25/25:  
 :heavy_check_mark: Graphic interface (Ncurses) | :heavy_check_mark: Decompiler | :heavy_check_mark: Advanced error handeling | :heavy_check_mark: Tester

#### Objectives:
• Compilation   
• Simplistic virtual machine  
• Simplistic assembly type language  
• Visual render  

#### Skills:
• Adaptation & creativity  
• Organization  
• Group & interpersonal  
• Algorithms & AI  

## How to use

#### Pre required : Make, GCC and Ncurses

First of all, open a terminal, go into the project and build it:   
```  
make
```

### Input

To start a game you need at least a compiled champion file (.cor), you can create one from a redcode assembly file (.s) with the compiler:
```  
./asm champion.s
```
Valid exemples .s files are given into the exemples_s folder.  

Once you have your champion, you can make him play alone or compete with a maximum of 3 other champions (maximum number of players along many other variables can be changed inside op.h).
```  
./corewar champion.cor other_champion.cor
```
You can also use a few options:

• -n followed by a number to set the number of the next player. 
This number impacts the turn order (biggest to smallest):
```  
./corewar a.cor -n 3 b.cor c.cor
```
Here 'a' will be set to 1, 'b' to 3 and 'c' to 2, 'b' will play first then 'c', then 'b' (consult the subject for more informations).  

• -dump followed by a number to stop the game at the beginning of the given cycle and print out the memory in hexadecimal (0 being the first cycle):
```  
./corewar champion.cor -dump 42
```
• -v to activate the visualizer:
```  
./corewar champion.cor -v
```

### Output

#### If all the inputs are valid, the VM will start the game by presenting the champions:  
![contestant](https://user-images.githubusercontent.com/45463065/86416877-a3295780-bccb-11ea-8b14-2a79db1eaf83.png)  
#### During the game, each time a processus reports a player as alive, the VM prints a message (option -v disables this behaviour):  
![alive](https://user-images.githubusercontent.com/45463065/86417455-5777ad80-bccd-11ea-8fc2-725ce6e3c485.png)
#### At the end, the winner is displayed:
![won](https://user-images.githubusercontent.com/45463065/86417512-8726b580-bccd-11ea-835f-08f4b6473bbc.png)

Hard to understand what happened without the visualizer or the dump option, here are how they render:

#### Visualizer (-v):
![visu](https://user-images.githubusercontent.com/45463065/86418741-737d4e00-bcd1-11ea-9215-9f59af2b423e.png)

#### Dump option (-dump):
![arena](https://user-images.githubusercontent.com/45463065/86418186-a292c000-bccf-11ea-962a-f2c2e391c106.png)

### Bonus

.cor files can be decompile into .s file with the revams:
```  
./revasm champion.cor
```

Two scripts of test can be found inside the unit_test folder, you need to give them the executable you want to test as argument:
```  
./asm_test the_executable_to_test
```
#### The tester will then compare your executable with the one given by 42:  
![unit_test_ok](https://user-images.githubusercontent.com/45463065/86419708-539b5980-bcd4-11ea-8e6d-1679507de87b.png)  
![ko](https://user-images.githubusercontent.com/45463065/86419710-572ee080-bcd4-11ea-947f-67717ad72376.png)  


#### Any different result will cause the script to create a file containing the instructions of the failed test (labeled as error):  
![errors s](https://user-images.githubusercontent.com/45463065/86419729-6f066480-bcd4-11ea-9e0d-0c46605a6645.png)




