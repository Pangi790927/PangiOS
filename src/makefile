all:
	echo "builds only available for specific arch"

x86_64-kernel:
	make -C platform/x86_64 kernel.bin

arm-kernel:
	make -C platform/arm kernel.bin

arm64-kernel:
	make -C platform/arm64 kernel.bin

clean:
	make -C platform/x86_64 clean
	make -C platform/arm clean
	make -C platform/arm64 clean
