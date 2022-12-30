obj: $(wildcard *.cpp)
	gcc -Isrc/include -std=c++11 -o $?.exe $?