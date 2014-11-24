all:
	gcc random_num.c -o random_num
	gcc test_dlopen.c -o test_dlopen -ldl
	gcc -shared -fPIC unrandom.c -o unrandom.so
	gcc -shared -fPIC unfork.c -o unfork.so
	gcc -shared -fPIC undlopen.c -o undlopen.so
