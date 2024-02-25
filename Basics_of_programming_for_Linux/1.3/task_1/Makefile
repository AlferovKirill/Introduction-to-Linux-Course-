all: exe
exe: solution.c
	gcc solution.c -ldl -Wl,-rpath=. -o solution
clean:
	-rm solution libShared.so 2>/dev/null
