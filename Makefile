all:
	gcc random_num.c -o random_num
	gcc -shared -fPIC unrandom.c -o unrandom.so
	gcc -shared -fPIC undlopen.c -o undlopen.so
