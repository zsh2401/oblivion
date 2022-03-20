%.s: %.c
	gcc -S $^ 
%.i: %.c
	gcc -E $^ > $@
%.o: %.c
	gcc -c $^ -o $^
%:%.c
	gcc $^ -o $@.bin && ./$@.bin
.PHONY=clean
clean:
	rm -rf *.s *.i *.o *.bin *.out