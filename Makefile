
output: main.o person.o member.o librarian.o book.o
	g++ main.o person.o member.o librarian.o book.o -o output


main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

member.o: member.cpp member.h
	g++ -c member.cpp

librarian.o: librarian.cpp librarian.h
	g++ -c librarian.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

clean:
	rm *.o output