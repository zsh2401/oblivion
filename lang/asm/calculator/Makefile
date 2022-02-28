default: calculator.run
	./calculator.run

calculator.o: calculator.asm f.asm math.asm
	nasm -f elf64 $*.asm -o $*.o

calculator.run: calculator.o
	gcc $< -o $@  -g -no-pie

.PHONY=clean
clean:
	rm -rf *.o *.out *.run