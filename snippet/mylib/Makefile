WIN-AMD64-CC=x86_64-w64-mingw32-gcc
WIN-X86-CC=i686-w64-mingw32-gcc
LINUX-AMD64-CC=clang -target x86_64-pc-linux
LINUX-X86-CC=clang -target i386-pc-linux
WIN-AMD64-LD=x86_64-w64-mingw32-ld
WIN-X86-LD=i686-w64-mingw32-ld
LINUX-AMD64-LD=ld
LINUX-X86-LD=ld -melf_i386

default: linux win32

linux: linux-amd64.so linux-x86.so
win32: win32-amd64.dll win32-x86.dll

linux-amd64.o:
	@make -C src object PREFIX=linux-amd64 CC="$(LINUX-AMD64-CC)" LD=$(LINUX-AMD64-LD) OUT=../$@
linux-x86.o:
	@make -C src object PREFIX=linux-x86 CC="$(LINUX-X86-CC)" LD="$(LINUX-X86-LD)" OUT=../$@
win32-amd64.o:
	@make -C src object CFLAGS="-DWIN32" PREFIX=win32-amd64 CC="$(WIN-AMD64-CC)" LD=$(WIN-AMD64-LD) OUT=../$@
win32-x86.o:
	@make -C src object CFLAGS="-DWIN32" PREFIX=win32-x86 CC="$(WIN-X86-CC)" LD=$(WIN-X86-LD) OUT=../$@

win32-x86.dll: win32-x86.o
	@$(WIN-X86-CC) -fPIC -shared win32-x86.o -o $@
win32-amd64.dll: win32-amd64.o
	@$(WIN-AMD64-CC) -fPIC -shared win32-amd64.o -o $@
linux-amd64.so: linux-amd64.o
	@$(LINUX-AMD64-CC) -fPIC -shared linux-amd64.o -o $@
linux-x86.so: linux-x86.o
	@$(LINUX-X86-CC) -L/usr/lib32 -fPIC -shared linux-x86.o -o $@

.PHONY: clean
clean:
	@rm -rf *.o *.out *.so *.dll test
	@make -C src clean
