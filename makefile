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

#  clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping *.cpp -o TestingMain
# LLVM_PROFILE_FILE="TestingMain.profraw" ./TestingMain
# rm -f *.o *.gcno *.gcda TestingMain coverage.info
# g++ -std=c++11 -fprofile-arcs -ftest-coverage *.cpp -o TestingMain
# ./TestingMain
# lcov --capture --directory . --output-file coverage.info
# genhtml coverage.info --output-directory out
# xdg-open out/index.html
# lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch