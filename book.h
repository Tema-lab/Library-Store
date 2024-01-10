#ifndef LIBRARY_STORE_BOOK_H
#define LIBRARY_STORE_BOOK_H

#include <ctime>
#include <string>

// Forward declaration to fix any circular dependencies, causing compiling errors.
class Member;

class Book {
private:
    int book_id;
    std::string book_name;
    std::string author_first_name;
    std::string author_last_name;
    std::string book_type;
    std::time_t due_date;
    Member* borrower;
public:
    Book(int book_id,std::string book_name, std::string author_first_name, std::string author_last_name);
    std::string get_book_id();
    std::string get_book_name();
    std::string get_author_first_name();
    std::string get_author_last_name();
    std::time_t get_due_date();

    void set_due_date(std::time_t due_date);
    void return_book();
    void borrow_book(Member* borrower,std::time_t due_date);
};


#endif //LIBRARY_STORE_BOOK_H
