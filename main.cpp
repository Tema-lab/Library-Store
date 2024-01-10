#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "person.h"
#include "book.h"
#include "librarian.h"
#include "member.h"


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

int main() {
    if(askToContinue()){
        std::string filename;

        std::cout << "Please enter the file that contains book data: " << std::endl;
        std::cin >> filename;

        std::ifstream input_file(filename);

        if(input_file.is_open()){

            char choice;
            std::cout << "File " << filename << " was found and can be read. " << std::endl;
            while(true){
                std::cout << "Please choose one of the available options below: " << std::endl;
                std::cout << "Add Member (1) " << std::endl;
                std::cout << "Manage Book (2)" << std::endl;
                std::cout << "Display All Books (3)" << std::endl;
                std::cout << "End Session (4)" << std::endl;
                std::cin >> choice;
                std::cin.ignore();

                switch (choice) {
                    case '4':
                        std::cout << "System Exiting" << std::endl;
                        exit(0);
                        break;
                    case '1':
                        librarian.add_member();
                        break;
                }
            }
        }else{
            std::cout << "Error! File " << filename << " was not found and can be read. " << std::endl;
        }
    }else{
        std::cout << "Program stopped. " << std::endl;
    }


    return 0;
}

