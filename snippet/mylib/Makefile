WIN-AMD64-CC=x86_64-w64-mingw32-gcc
WIN-X86-CC=i686-w64-mingw32-gcc
LINUX-AMD64-CC=gcc
LINUX-X86-CC=x86_64-pc-linux-gnu-gcc -m32
WIN-AMD64-LD=x86_64-w64-mingw32-ld
WIN-X86-LD=i686-w64-mingw32-ld
LINUX-AMD64-LD=ld
LINUX-X86-LD="ld -melf_i386"
linux-amd64.o:
	@make -C src object PREFIX=linux-amd64 CC=$(LINUX-AMD64-CC) LD=$(LINUX-AMD64-LD) OUT=../$@
linux-x86.o:
	@make -C src object PREFIX=linux-x86 CC=$(LINUX-X86-CC) LD=$(LINUX-X86-LD) OUT=../$@
win-amd64.o:
	@make -C src object PREFIX=win-amd64 CC=$(WIN-AMD64-CC) LD=$(WIN-AMD64-LD) OUT=../$@
win-x86.o:
	@make -C src object PREFIX=win-amd64 CC=$(WIN-X86-CC) LD=$(WIN-X86-LD) OUT=../$@

win-x86.dll: win-x86.o
	@$(WIN-X86-CC) -fPIC -shared win-x86.o -o $@
win-amd64.dll: win-amd64.o
	@$(WIN-AMD64-CC) -fPIC -shared win-amd64.o -o $@
linux-amd64.so: linux-amd64.o
	$(LINUX-X86-CC) -fPIC -shared linux-amd64.o -o $@
linux-x86.so: linux-x86.o
	$(LINUX-X86-CC) -fPIC -shared linux-x86.o -o $@
# install: libmy.so
# 	@sudo cp libmy.so /usr/lib
# uninstall:
# 	@sudo rm /usr/lib/libmy.so
# src/all.o:
# 	@make -C src all CC=$(CC) LD=$(LD)
# test: test.c libmy.so
# 	@gcc test.c -L. -lmy -o test
# run-test: test
# 	@./test
.PHONY: clean
clean:
	@rm -rf *.o *.out *.so test
	@make -C src clean
