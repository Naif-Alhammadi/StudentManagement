#include <iostream>
#include "include/student.h"
const int arrayStudentsIndex = 100;
int main()
{
    int backChoise;
    int arrayIndex=0;
        students arrayinput[arrayStudentsIndex];

        // choise
        int choseNumber;
        std::cout << "1. Add A New Student\n";
        std::cout << "2. Show A Student Status\n";
        std::cout << "3. Show Students list\n";
        std::cout << "4. Search for a specific student\n";
        // needs to work and the while prints more than once
        // backChoise:
        // if(!std::cin>>choseNumber){
        // std::cout<<"you entered invalid symbol\n"; 
        // goto backChoise;
        // }
        // else
        std::cin >> choseNumber;
        std::cin.clear();
        std::cin.ignore();
        while (!(choseNumber == 8))
        {
            switch (choseNumber)
            {
            case 1:
            {
                registrationOfStudents(arrayinput, arrayIndex);
                break;
            }
            case 2:
            {
            studentlist(arrayinput, arrayIndex);
            break;
            }
            case 3:
            {
                specificStudent(arrayinput, arrayIndex);
                break;
            }
            // case 4:
            //     registrationOfStudents(arrayinput,arrayIndex);
            case 8:
            {
                choseNumber = 8;
            }
            }
            std::cout << "1. Add A New Student\n";
            std::cout << "2. Show A Student Status\n";
            std::cout << "3. Show Students list\n";
            std::cout << "4. Search for a specific student\n";
            std::cin >> choseNumber;
            std::cin.clear();
            std::cin.ignore();
        }
    }