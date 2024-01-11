#include "person.h"
#include "member.h"
#include "book.h"
#include <algorithm>

Member::Member(int member_id, std::string name, std::string address, std::string email) {
    this->member_id = member_id;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
};

// Getter function for member ID
int Member::get_member_id() const{
    return member_id;
};

// Getter function for the vector of borrowed books
std::vector<Book *> &Member::get_books_borrowed(){
    return books_loaned;
}

// Function to add a borrowed book to the member's list
void Member::set_books_borrowed(Book *books) {
    books_loaned.push_back(books);
}
// Function to remove a borrowed book from the member's list
void Member::remove_borrowed_book(Book *book) {
    // Lambda function that checks if the book pointer is equal to the current book in the vector
    auto isMatchingBook = [book](const Book* b) {
        return b == book;
    };

    // rearranging elements in the vector, moving elements that satisfy the condition to the end
    auto newEnd = std::remove_if(books_loaned.begin(), books_loaned.end(), isMatchingBook);

    // removing elements from the vector
    books_loaned.erase(newEnd, books_loaned.end());
}

//function which returns a reference to the vector of member objects
std::vector<Member>& Member::get_list_of_members(){
    //create vector that holds all member objects
    static std::vector<Member> member_list;
    return member_list;
}