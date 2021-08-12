ff.a: add.o sub.o mul.o
	@ar cr ff.a mul.o add.o sub.o

rust-dist/*.o: xdiv.rs rust-dist
	@rustc xdiv.rs --crate-type=staticlib
	@ar x --output rust-dist libxdiv.a

add.o: add.cxx
	@g++ -c add.cxx
rust-dist:
	@mkdir rust-dist &

sub.o: sub.c
	@gcc -c sub.c
mul.o: mul.swift
	@swiftc -parse-as-library -emit-object mul.swift -o mul.o
clean:
	@rm -rf *.bin *.run *.o *.a *.out *dist