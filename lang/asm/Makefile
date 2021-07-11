hello: hello.run
	./hello.run

hello.run: hello.asm
	nasm -felf64 hello.asm && ld hello.o -o hello.run

.PHONY=clean
clean:
	rm -rf *.o *.out *.run