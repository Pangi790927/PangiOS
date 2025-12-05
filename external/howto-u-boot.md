# Compiling a bootloader:

TODO: this will be used for arm, maybe?

Clone u-boot https://github.com/u-boot/u-boot.git

Execute `make qemu-x86_64_defconfig` (change to specific target: efi-x86_app64_defconfig or
efi-x86_payload64_defconfig)

OBS: On Debian based systems the cross compiler packages are named gcc-<architecture>-linux-gnu.
     !!! Observe the -linux- part !!! 

Execute `make` to make the bootloader.

Execute `qemu-system-x86_64 -nographic -bios u-boot.rom -m 1024` to test it.
