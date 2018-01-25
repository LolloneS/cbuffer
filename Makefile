CXXFLAGS = -Wall

main.exe: main.o
	g++ $(CXXFLAGS) main.o -o main.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp -o main.o

.PHONY: clean release rebuild
clean:
	rm -f *.exe *.o

release:
	g++ $(CXXFLAGS) -c main.cpp -o main.o
	g++ $(CXXFLAGS) main.o -o main.exe


rebuild: clean release