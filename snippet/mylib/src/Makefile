PREFIX?=
CC?=gcc
LD?=ld
OUT?=all.o
CFLAGS?=
DEPS=../mylib.h

object: add.o
	$(LD) -r $(PREFIX)_*.o -o $(OUT)

%.o: %.c
	$(CC) -o $(PREFIX)_$@ -c $< $(CFLAGS)

.PHONY: clean
clean:
	@rm -rf *.o *.out *.a *.so *.dll