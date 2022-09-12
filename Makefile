GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L

CFLAGS = -lm

PROGS = bench_project_int bench_project_int_rmd bench_project_double bench_project_double_rmd

all: $(PROGS)

bench_project_int:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) bench_functions.c -c
	$(GCC) $(FLAGS) -o $@ $@.o bench_functions.o $(CFLAGS)

bench_project_int_rmd:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) bench_functions.c -c
	$(GCC) $(FLAGS) -o $@ $@.o bench_functions.o $(CFLAGS)

bench_project_double:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) bench_functions.c -c
	$(GCC) $(FLAGS) -o $@ $@.o bench_functions.o $(CFLAGS)

bench_project_double_rmd:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) bench_functions.c -c
	$(GCC) $(FLAGS) -o $@ $@.o bench_functions.o $(CFLAGS)

clean:
	$(RM) *.o $(PROGS)