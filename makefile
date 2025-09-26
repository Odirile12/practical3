all:
	rm -f TestingMain
	g++ -std=c++11 -g *.cpp -o TestingMain
	./TestingMain

build:
	rm -f TestingMain
	g++ -std=c++11 -g *.cpp -o TestingMain

clean:
	rm -f TestingMain

run:
	./TestingMain

debug:
	gdb ./TestingMain

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all ./TestingMain