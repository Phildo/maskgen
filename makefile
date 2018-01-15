make: a.out
	

run: a.out
	./a.out

debug:
	gcc -ggdb3 maskgen.cpp && gdb ./a.out

a.out: maskgen.cpp
	gcc maskgen.cpp

