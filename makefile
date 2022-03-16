
output: main.o libraryitem.o book.o audioCD.o dvd.o libraryitems.o patron.o loan.o patrons.o loans.o
	g++ main.o libraryitem.o book.o audioCD.o dvd.o libraryitems.o patron.o loan.o patrons.o loans.o -o output

main.o: main.cpp
	g++ -c main.cpp

libraryitem.o: libraryitem.h libraryitem.cpp
	g++ -c libraryitem.cpp

book.o: book.h book.cpp
	g++ -c book.cpp

audioCD.o: audioCD.h audioCD.cpp
	g++ -c audioCD.cpp

dvd.o: dvd.h dvd.cpp
	g++ -c dvd.cpp

libraryitems.o: libraryitems.h libraryitems.cpp
	g++ -c libraryitems.cpp

patron.o: patron.h patron.cpp
	g++ -c patron.cpp

loan.o: loan.h loan.cpp
	g++ -c loan.cpp

patrons.o: patrons.h patrons.cpp
	g++ -c patrons.cpp

loans.o: loans.h loans.cpp
	g++ -c loans.cpp

clean:
	rm *.o output
