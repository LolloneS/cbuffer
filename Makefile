CXXFLAGS = -Wall

main.exe: main.o
	g++ $(CXXFLAGS) main.o -o main.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp -o main.o

.PHONY: clean

clean:
	rm *.exe *.o