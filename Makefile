CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -MMD -MP -Iinclude
SRCDIR = src
BUILDDIR = build
BINDIR = bin

all: $(BINDIR)/ManagementSystem $(BINDIR)/Catch2tests

$(BINDIR)/Catch2tests: $(BUILDDIR)/test.o $(BUILDDIR)/person.o $(BUILDDIR)/book.o $(BUILDDIR)/member.o $(BUILDDIR)/librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BINDIR)/ManagementSystem: $(BUILDDIR)/main.o $(BUILDDIR)/person.o $(BUILDDIR)/book.o $(BUILDDIR)/member.o $(BUILDDIR)/librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Object file rules
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/test.o: $(SRCDIR)/test.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Other dependencies
$(BUILDDIR)/person.o: $(SRCDIR)/person.cpp include/person.h
$(BUILDDIR)/book.o: $(SRCDIR)/book.cpp include/book.h
$(BUILDDIR)/member.o: $(SRCDIR)/member.cpp include/member.h
$(BUILDDIR)/librarian.o: $(SRCDIR)/librarian.cpp include/librarian.h

.PHONY: clean
clean:
	$(RM) $(BUILDDIR)/*.o $(BINDIR)/ManagementSystem $(BINDIR)/Catch2tests
