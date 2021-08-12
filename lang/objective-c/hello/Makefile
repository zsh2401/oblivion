.PHONY: clean
run: hello.run
	@./hello.run

ff/ff.a: 
	@make -C ff
hello.o: hello.m
	@g++ -c hello.m -o hello.o -fconstant-string-class=NSConstantString

hello.run: hello.o ff/ff.a
	@g++ -lobjc -lgnustep-base hello.o ff/ff.a -o hello.run
clean:
	@rm -rf *.bin *.run *.o *.a *.out
	@make -C ff clean