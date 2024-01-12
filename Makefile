CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

all: ManagementSystem Catch2tests

Catch2tests: test.cpp person.o book.o member.o librarian.o
		$(CXX) $(CXXFLAGS) -o $@ $^

ManagementSystem: main.o person.o book.o member.o librarian.o
		$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
		$(CXX) $(CXXFLAGS) -c $<

person.o: person.cpp person.h
		$(CXX) $(CXXFLAGS) -c $<

book.o: book.cpp book.h
		$(CXX) $(CXXFLAGS) -c $<

member.o: member.cpp member.h
		$(CXX) $(CXXFLAGS) -c $<

librarian.o: librarian.cpp librarian.h
		$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
		$(RM) *.o ManagementSystem Catch2tests






