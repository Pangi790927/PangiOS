all: 
	make -C ../../src x86_64-kernel
	mkdir -p isodir/boot/grub
	cp ../../src/platform/x86_64/kernel.bin isodir/boot/x86_64-kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o image.iso isodir

clean:
	rm -rf isodir
	rm -f image.iso
