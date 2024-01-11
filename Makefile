output: main.o person.o member.o librarian.o book.o
	g++ $^ -o $@

main.o: main.cpp person.h member.h librarian.h book.h
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

member.o: member.cpp member.h person.h
	g++ -c member.cpp

librarian.o: librarian.cpp librarian.h person.h member.h
	g++ -c librarian.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

clean:
	rm *.o output
