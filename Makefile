CXXFLAGS = -Wall -pedantic -Wextra -pedantic-errors -DNDEBUG
CXXFLAGS_DEBUG = -Wall -pedantic -Wextra -pedantic-errors -g


main.exe: main.o
	g++ $(CXXFLAGS) main.o -o main.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp -o main.o

.PHONY: clean release rebuild doc debug

clean:
	rm -f *.exe *.o

release:
	g++ $(CXXFLAGS) -c main.cpp -o main.o
	g++ $(CXXFLAGS) main.o -o main.exe

doc: 	
	doxygen Doxyfile

rebuild: clean release

debug: 
	g++ $(CXXFLAGS_DEBUG) -c main.cpp -o main.o
	g++ $(CXXFLAGS_DEBUG) main.o -o main.exe

