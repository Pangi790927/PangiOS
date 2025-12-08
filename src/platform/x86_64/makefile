CROSS := ../../../compiler/x86_64-unknown-elf
TOOLCHAIN_PREFIX := ${CROSS}/bin/x86_64-unknown-elf-

MAIN_SRC := ../..

AS  := ${TOOLCHAIN_PREFIX}as
CXX := ${TOOLCHAIN_PREFIX}g++
LD  := ${TOOLCHAIN_PREFIX}ld

CXX_FLAGS := -O3 -g
CXX_FLAGS += -mno-sse -mno-sse2 -mno-mmx # we don't want those at the start of the kernel atm

INCLUDES := -I.

LD_FLAGS := -O3 -g

all: kernel

boot.o: boot.asm
	${AS} boot.asm -o boot.o

kernel_main.o: ${MAIN_SRC}/kernel_main.cpp makefile
	${CXX} -c ${MAIN_SRC}/kernel_main.cpp ${INCLUDES} ${CXX_FLAGS} -o kernel_main.o

kernel.bin: boot.o kernel_main.o makefile
	${LD} ${LD_FLAGS} -T linker.ld -o kernel.bin boot.o kernel_main.o

clear:
	rm -f boot.o
