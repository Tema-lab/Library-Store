#ifndef LIBRARY_STORE_BOOK_H
#define LIBRARY_STORE_BOOK_H

#include <ctime>
#include <string>
#include <vector>

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

    static std::vector<Book> books;// variable to store all books

public:
    Book(int book_id,std::string book_name, std::string author_first_name, std::string author_last_name);
    std::string get_book_id() const;
    std::string get_book_name() const;
    std::string get_author_first_name() const;
    std::string get_author_last_name() const;
    std::time_t get_due_date();

    void set_due_date(std::time_t due_date);
    void return_book(int,int);
    void borrow_book(Member* borrower,std::time_t due_date);
    static void print_all_books();
    static std::vector<Book>& get_list_of_books();
};


#endif //LIBRARY_STORE_BOOK_H
