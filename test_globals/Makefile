read:
	g++ -o test use_globals.cc populate.cc yen.cc globals.cc
	./test

valgrind: test
	valgrind ./test

clean:
	rm -rf test
