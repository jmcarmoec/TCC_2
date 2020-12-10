###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = LPC1114FN28/102
COMPILER = "GCC for ARM"
TARGET = Debug

## Tools general options
CCFLAGS=-gdwarf-2 -fomit-frame-pointer -Wall -fverbose-asm -MD -MP -fsigned-char -O0 -mcpu=cortex-m0 -mthumb -I../cmsis/core -I../cmsis/device
LDFLAGS=-mcpu=cortex-m0 -mthumb -nostartfiles

## Processing Tools
CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
ASM=arm-none-eabi-gcc
BIN2HEX=arm-none-eabi-objcopy

all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o core_cm0.o crt.o vtable.o SYSTEM~1.o ../LPC111X_32_4_flash.ld 
	$(LD) $(LDFLAGS)  -Wl,-Map,Debug.map,--cref,--no-warn-mismatch,--start-group,--end-group,--gc-sections -o "Debug.elf" "main.o" "core_cm0.o" "crt.o" "vtable.o" "SYSTEM~1.o" -T "../LPC111X_32_4_flash.ld" 

main.o:	../main.c 
	$(CC) -c $(CCFLAGS)   "../main.c" -o "main.o" 

core_cm0.o:	../cmsis/core/core_cm0.c 
	$(CC) -c $(CCFLAGS)   "../cmsis/core/core_cm0.c" -o "core_cm0.o" 

crt.o:	../crt.c 
	$(CC) -c $(CCFLAGS)   "../crt.c" -o "crt.o" 

vtable.o:	../vtable.c 
	$(CC) -c $(CCFLAGS)   "../vtable.c" -o "vtable.o" 

SYSTEM~1.o:	../cmsis/device/system_LPC11xx.c 
	$(CC) -c $(CCFLAGS)   "../cmsis/device/system_LPC11xx.c" -o "SYSTEM~1.o" 

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./main.d
	rm -rf ./core_cm0.d
	rm -rf ./crt.d
	rm -rf ./vtable.d
	rm -rf ./SYSTEM~1.d

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf core_cm0.o
	rm -rf crt.o
	rm -rf vtable.o
	rm -rf SYSTEM~1.o
