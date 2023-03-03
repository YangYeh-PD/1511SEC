1511SEC: 1511SEC.o Data.o
	g++ -o 1511SEC 1511SEC.o Data.o

1511SEC.o: 1511SEC.cpp Data.h
	g++ -c 1511SEC.cpp Data.h

Data.o: Data.cpp Data.h
	g++ -c Data.cpp Data.h

clean:
	rm 1511SEC *.o *.h.gch