PROGS=sequential binary

BINS=$(addprefix build/, $(PROGS))

all: $(BINS)

obj/%.o: bin/%.c
	cc -c $(CFLAGS) $^ -o $@

$(BINS): $(addprefix obj/, $(addsuffix .o, $(PROGS)))
	cc $(CFLAGS) $(patsubst build/%, obj/%, $(addsuffix .o, $@)) -o $@

.PHONY: clean
clean:
	rm -rf build/* obj/*
