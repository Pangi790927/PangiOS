CROSS := ../../../compiler/x86_64-unknown-elf
TOOLCHAIN_PREFIX := ${CROSS}/bin/x86_64-unknown-elf-

MAIN_SRC := ../..

AS  := ${TOOLCHAIN_PREFIX}as
CXX := ${TOOLCHAIN_PREFIX}g++
LD  := ${TOOLCHAIN_PREFIX}ld

CXX_FLAGS := -O3 -g
# CXX_FLAGS += -ffreestanding
CXX_FLAGS += -mno-sse -mno-sse2 -mno-mmx # we don't want those at the start of the kernel atm
# CXX_FLAGS += -Wall -Wextra -Wno-format-security

INCLUDES := -I.

LD_FLAGS := -O3 -g

SRCS :=
SRCS += serial.cpp

OBJS := ${SRCS:.cpp=.o}
DEPS := $(SRCS:.cpp=.d)

all: kernel

boot.o: boot.asm
	${AS} boot.asm -o boot.o

kernel_main.o: ${MAIN_SRC}/kernel_main.cpp makefile 
	${CXX} -c ${MAIN_SRC}/kernel_main.cpp ${INCLUDES} ${CXX_FLAGS} -o kernel_main.o

${DEPS}: makefile
${OBJS}: makefile

${DEPS}:%.d:%.cpp
	${CXX} -c ${INCLCUDES} ${CXX_FLAGS} -MM $< -MF $@

include ${DEPS}

${OBJS}:%.o:%.cpp
	${CXX} -c ${CXX_FLAGS} ${INCLCUDES} $< -o $@

kernel.bin: ${OBJS} ${DEPS} boot.o kernel_main.o makefile
	${LD} ${LD_FLAGS} -T linker.ld -o kernel.bin boot.o kernel_main.o ${OBJS}

clean:
	rm -f boot.o
	rm -f kernel_main.o
	rm -f ${OBJS}
	rm -f ${DEPS}
	rm -f kernel.bin
