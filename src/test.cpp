#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/person.h"
#include "../include/member.h"
#include "../include/librarian.h"
#include "../include/book.h"

// Test case for the Book class
TEST_CASE("Book Class Tests", "[Book]") {
    SECTION("Get Book ID") {
        Book book(1, "The Great Gatsby", "F. Scott", "Fitzgerald");
        REQUIRE(book.get_book_id() == "1");
    }

    SECTION("Get Book Name") {
        Book book(2, "To Kill a Mockingbird", "Harper", "Lee");
        REQUIRE(book.get_book_name() == "To Kill a Mockingbird");
    }

    SECTION("Get Author's First Name") {
        Book book(3, "1984", "George", "Orwell");
        REQUIRE(book.get_author_first_name() == "George");
    }

    SECTION("Get Author's Last Name") {
        Book book(4, "Pride and Prejudice", "Jane", "Austen");
        REQUIRE(book.get_author_last_name() == "Austen");
    }
}
// Test case for the Person class
TEST_CASE("Person Class Tests", "[Person]") {
    SECTION("Get and Set Name") {
        Person person;
        person.setName("Artem Halis");
        REQUIRE(person.getName() == "Artem Halis");
    }
    SECTION("Get and Set Address") {
        Person person;
        person.setAddress("Portnall Road 190");
        REQUIRE(person.getAddress() == "Portnall Road 190");
    }
    SECTION("Get and Set Email") {
        Person person;
        person.setEmail("nowayamgs63@gmail.com");
        REQUIRE(person.getEmail() == "nowayamgs63@gmail.com");
    }
}
// Test case for the Librarian class
TEST_CASE("Librarian Class Tests", "[Librarian]") {
    SECTION("Add Member") {
        Librarian librarian(190, "Artem", "Portnall Road 87", "artem78@gmail.com", 83000);
        librarian.add_member();
    }

    SECTION("Print Member Details") {
        Librarian librarian(113, "Kate", "Portnall Road 11", "kate79@gmail.com", 82000);
        librarian.print_member_details(1000);
    }

    SECTION("Display Borrowed Books") {
        Librarian librarian(12, "Stanislav", "Portnall Road 199", "stan667@gmail.com", 69000);
        librarian.display_borrowed_books(1000);
    }

    SECTION("Calculate Fine") {
        Librarian librarian(32, "Olga", "Portnall Road 18", "olga78@gmail.com", 8000);
        librarian.calc_fine(1000);
    }
}
TEST_CASE("Member Class Tests", "[Member]") {
    SECTION("Get Member ID") {
        Member member(1001, "Alice Smith", "456 Oak St", "alice.smith@example.com");
        REQUIRE(member.get_member_id() == 1001);
    }

    SECTION("Get Books Borrowed") {
        Member member(1002, "Bob Johnson", "789 Pine St", "bob.johnson@example.com");
        std::vector<Book*>& borrowedBooks = member.get_books_borrowed();
        REQUIRE(borrowedBooks.empty());
    }

    SECTION("Set Books Borrowed") {
        Member member(1003, "Charlie Brown", "321 Elm St", "charlie.brown@example.com");
        Book* book = new Book(2, "The Great Gatsby", "F. Scott", "Fitzgerald");
        member.set_books_borrowed(book);
        REQUIRE(member.get_books_borrowed().size() == 1);
    }

    SECTION("Remove Borrowed Book") {
        Member member(1004, "Diana Miller", "654 Birch St", "diana.miller@example.com");
        Book* book = new Book(3, "To Kill a Mockingbird", "Harper", "Lee");
        member.set_books_borrowed(book);
        member.remove_borrowed_book(book);
        REQUIRE(member.get_books_borrowed().empty());
    }
}







