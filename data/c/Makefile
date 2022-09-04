CFLAGS+=-Wall -Wextra -Werror
PROGS=$(subst bin/, build/, $(basename $(wildcard bin/*.c)))

.PHONY: all
all: $(PROGS)

build/%: obj/%.o
	cc $(CFLAGS) $< -o $@
	size $@

obj/%.o: bin/%.c
	cc $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build/* obj/*

.SECONDARY:
