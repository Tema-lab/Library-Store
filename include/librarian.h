#ifndef LIBRARY_STORE_LIBRARIAN_H
#define LIBRARY_STORE_LIBRARIAN_H

#include "person.h"
#include "member.h"

class Member;

class Librarian : public Person{
private:
    int staff_id;
    int salary;
public:
    Librarian(int staff_id,std::string name,std::string address,std::string email,int salary);
    void add_member();
    void issue_book(int member_id, int book_id);
    void return_book(int member_id,int book_id);
    void display_borrowed_books(int member_id);
    void calc_fine(int member_id);
    int get_staff_id();
    int get_salary();
    void set_staff_id(int staff_id);
    void set_salary(int salary);
    void print_member_details(int member_id);
    void manageBook();
    Member* find_member(int member_id);
    Book* find_book(int book_id);
};

extern Librarian librarian;

#endif //LIBRARY_STORE_LIBRARIAN_H
