hello: hello.run
	./hello.run


%.o: %.asm f.asm math.asm
	nasm -f elf64 $*.asm -o $*.o

%.run: %.o
	gcc $< -o $@  -g -no-pie

.PHONY=clean
clean:
	rm -rf *.o *.out *.run