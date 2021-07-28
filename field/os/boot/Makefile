.PHONY: clean
default:
	make mboot.bin
disk.img:
	bximage -mode=create -fd=1.44M disk.img -q	
write-boot: disk.img mboot.bin
	dd
mboot.bin: mboot.asm
	nasm mboot.asm -o mboot.bin

hw.bin: helloworld.asm
	nasm helloworld.asm -o hw.bin

runhw: hw.bin
	@qemu-system-i386 hw.bin

clean:
	@rm *.bin *.img
