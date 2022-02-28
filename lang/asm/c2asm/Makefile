%.o: %.c
	gcc -c $*.c
%.nasm: %.o
	objconv -fnasm $< $@
PHONY=clean
clean:
	rm -rf *.asm *.s *.S *.nasm *.o
