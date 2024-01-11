#include "book.h"
#include <iostream>
#include <vector>


std::vector<Book> Book::books;

Book::Book(int book_id, std::string book_name, std::string author_first_name, std::string author_last_name) {
    this->book_id = book_id;
    this->book_name = book_name;
    this->author_first_name = author_first_name;
    this->author_last_name = author_last_name;
};

std::string Book::get_book_id() const{
    return std::to_string(book_id);
};

std::string Book::get_book_name() const{
    return book_name;
};

std::string Book::get_author_first_name() const{
    return author_first_name;
};

std::string Book::get_author_last_name() const{
    return author_last_name;
};

std::vector<Book>& Book::get_list_of_books(){
    return books;
}
void Book::print_all_books() {
    std::cout << "List of Books:\n";
    for (const auto& book : get_list_of_books()) {
        std::cout << "Book ID: " << book.get_book_id() << "\n";
        std::cout << "Book Name: " << book.get_book_name() << "\n";
        std::cout << "Author: " << book.get_author_first_name() << " " << book.get_author_last_name() << "\n";
        std::cout << "\n";
    }
}

std::time_t Book::get_due_date(){
    return due_date;
};

void Book::set_due_date(std::time_t new_due_date){
    this->due_date = new_due_date;
};

void Book::return_book() {};

void Book::borrow_book(Member* borrower, std::time_t due_date) {
    this->borrower = borrower;
    set_due_date(due_date);
};