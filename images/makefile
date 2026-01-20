# GDB_SETUP :=  -S -gdb tcp::1234
GDB_SETUP := 

# GRAPHICS := -vga std -serial stdio
GRAPHICS := -nographic

SERIAL := 

QUEMU_OPTS := ${GDB_SETUP} ${GRAPHICS} ${SERIAL}

x86-image:
	make -C x86

x86-test: x86-image
	echo "will require a gdb connection to port 1234"
	qemu-system-x86_64 ${QUEMU_OPTS} -cdrom x86/image.iso

x86-test-gdb:
	../compiler/x86_64-unknown-elf/bin/x86_64-unknown-elf-gdb -x x86/gdbinit
