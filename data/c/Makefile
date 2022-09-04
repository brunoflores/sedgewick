LIBS=-lm
INCLUDE=-I include
CFLAGS+=-Wall -Wextra -Werror
PROGS=$(subst bin/, build/, $(basename $(wildcard bin/*.c)))

.PHONY: all
all: $(PROGS)

build/%: obj/%.o
	cc $(CFLAGS) $^ -o $@ $(LIBS)
	size $@

build/3_2: obj/int.o

obj/%.o: bin/%.c
	cc $(CFLAGS) $(INCLUDE) -c $^ -o $@

obj/int.o: lib/int.c include/Num.h
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build/* obj/*

.SECONDARY:
