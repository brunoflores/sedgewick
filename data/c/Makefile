LIBS=-lm
CFLAGS+=-Wall -Wextra -Werror
PROGS=$(subst bin/, build/, $(basename $(wildcard bin/*.c)))

.PHONY: all
all: $(PROGS)

build/%: obj/%.o
	cc $(CFLAGS) $< -o $@ $(LIBS)
	size $@

obj/%.o: bin/%.c
	cc $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build/* obj/*

.SECONDARY:
