.PHONY: run debug
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -Wno-unused-function

# One program per .c file, wherever it lives: `make bin/dynamic_arrays` builds
# dynamic_arrays/dynamic_arrays.c. This is what a save builds (watcher.sh's
# prod line). ./main is then symlinked to it, so it's always the last build.
vpath %.c . $(wildcard */)
bin/%: %.c | bin
	gcc $(CFLAGS) -o $@ $<
	ln -sfn $@ main
bin:
	mkdir -p bin

debug:
	gdb -tui ./main
run:
	./main
