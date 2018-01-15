IN=maskgen.cpp
OUT=maskgen
RARGS=3 7

make: $(OUT)
	

run: $(OUT)
	./$(OUT) $(RARGS)

debug:
	gcc -ggdb3 $(IN) -o $(OUT) && gdb --args ./$(OUT) $(RARGS)

a.out: $(IN)
	gcc $(IN) -o $(OUT)

