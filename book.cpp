#include "book.h"

Book::Book(int book_id, std::string book_name, std::string author_first_name, std::string author_last_name) {
    this->book_id = book_id;
    this->book_name = book_name;
    this->author_first_name = author_first_name;
    this->author_last_name = author_last_name;
};

std::string Book::get_book_id(){
    return std::to_string(book_id);
};

std::string Book::get_book_name(){
    return book_name;
};

std::string Book::get_author_first_name(){
    return author_first_name;
};

std::string Book::get_author_last_name(){
    return author_last_name;
};

std::time_t Book::get_due_date(){
    return due_date;
};

void Book::set_due_date(std::time_t new_due_date) {
    this->due_date = new_due_date;
};

void Book::return_book() {};

void Book::borrow_book(Member* borrower, std::time_t due_date) {
    this->borrower = borrower;
    set_due_date(due_date);
};


