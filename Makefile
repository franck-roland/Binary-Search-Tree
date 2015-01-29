C_SRC = bs_tree.c test/test.c


all: $(C_SRC)
	$(CC) -o test_c $(C_SRC) -I . -Wall