#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "librarian.h"
#include "member.h"


int MEMBER_ID = 1000;

bool askToContinue() {
    char userInput;

    while (true) {
        std::cout << "Welcome to library management system." << std::endl;
        std::cout << "Press Y to continue or N to stop the program (Y/N): ";
        std::cin >> userInput;

        // Ignore any remaining characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userInput == 'Y' || userInput == 'y') {

            return true;
        } else if (userInput == 'N' || userInput == 'n') {
            return false;
        } else {
            std::cout << "Invalid input. Please enter 'Y' to continue or 'N' to stop." << std::endl;
        }
    }
}
void print_member_details(const Member& member) {
    std::cout << "Member ID: " << member.get_member_id() << std::endl;
    std::cout << "Name: " << member.getName() << std::endl;
    std::cout << "Address: " << member.getAddress() << std::endl;
    std::cout << "Email: " << member.getEmail() << std::endl;
}

int main() {
    if(askToContinue()){
        std::string filename;

        std::cout << "Please enter the file that contains book data: " << std::endl;
        std::cin >> filename;

        std::ifstream input_file(filename);

        if(input_file.is_open()){
            Librarian librarian(113,"temoid","portnall road","nowayamgs78@gmail.com",85000);
            char choice;
            std::cout << "File " << filename << " was found and can be read. " << std::endl;

            std::cout << "Please choose one of the available options below: " << std::endl;
            std::cout << "Add Member (1) " << std::endl;
            std::cout << "Manage Book (2)" << std::endl;
            std::cout << "Display All Books (3)" << std::endl;
            std::cout << "End Session (4)" << std::endl;
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case '1':
                    int id;
                    std::string name;
                    std::string address;
                    std::string email;

                    std::cout << "Add member option was chosen." << std::endl;
                    std::cout << "Please enter member's name: ";
                    std::getline(std::cin, name);
                    std::cout << "Please enter member's address: ";
                    std::getline(std::cin, address);
                    std::cout << "Please enter member's email: ";
                    std::getline(std::cin, email);

                    Member member(MEMBER_ID,name,address,email);
                    librarian.add_member(member);

                    std::cout << "New member was added: " << std::endl;
                    print_member_details(member);

                    MEMBER_ID += 1;

                    break;

            }


        }else{
            std::cout << "Error! File " << filename << " was not found and can be read. " << std::endl;
        }



    }else{
        std::cout << "Program stopped. " << std::endl;
    }


    return 0;
}

