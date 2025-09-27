all:
	rm -f Main
	g++ -std=c++11 -g *.cpp -o Main
	./Main

build:
	rm -f Main
	g++ -std=c++11 -g *.cpp -o Main

clean:
	rm -f Main

run:
	./Main

debug:
	gdb ./Main

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all ./Main

#  clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping *.cpp -o TestingMain
# LLVM_PROFILE_FILE="TestingMain.profraw" ./TestingMain
# rm -f *.o *.gcno *.gcda TestingMain coverage.info
# g++ -std=c++11 -fprofile-arcs -ftest-coverage *.cpp -o TestingMain
# ./TestingMain
# lcov --capture --directory . --output-file coverage.info
# genhtml coverage.info --output-directory out
# xdg-open out/index.html
# lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch