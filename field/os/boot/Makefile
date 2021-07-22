.PHONY=clean
default:
	make mboot.bin
	
mboot.bin: mboot.asm
	@nasm mboot.asm -o mboot.bin

hw.bin: helloworld.asm
	@nasm helloworld.asm -o hw.bin

runhw: hw.bin
	@qemu-system-i386 hw.bin

clean:
	rm *.bin
