#ifndef LIBRARY_STORE_MEMBER_H
#define LIBRARY_STORE_MEMBER_H

#include "person.h"
#include "book.h"
#include <vector>

class Member : public Person{
private:
    int member_id;
    std::vector<Book> books_loaned;
public:
    Member(int member_id, std::string name, std::string address,std::string email);
    int get_member_id() const;
    std::vector<Book> get_books_borrowed();
    void set_books_borrowed(const std::vector<Book>& books);
    static std::vector<Member>& get_list_of_members();
};



#endif //LIBRARY_STORE_MEMBER_H
