obj: $(wildcard *.cpp)
	gcc -o $?.o $?
output $wildcard *.o:
	gcc -o main.exe $?