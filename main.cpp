#include <iostream>
#include "include/student.h"
const int arrayStudentsIndex = 50;
int main()
{
    int arrayIndex=0;
        students arrayinput[arrayStudentsIndex];

        int choseNumber=0;
        while (!(choseNumber == 6))
        {
            std::cout << "1. Add A New Student\n";
            std::cout << "2. Show Students list\n";
            std::cout << "3. Search for a specific student\n";
            std::cout << "4. Edit Student Info\n";
            std::cout << "5. To Delete a Student Account\n";
            std::cout << "6. exist program\n";
            std::cin >> choseNumber;
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
            case 4:
            {
                editStudentInfromation(arrayinput,arrayIndex);
                 break;
            }
            case 5:
                deleteStudentAccount(arrayinput,arrayIndex);
            case 6:
            {
                choseNumber = 6;
                std::cout<<"Thank You For Entering, We Hope to See You Again ;)"<<std::endl;
                break;
            }
            }
            std::cin.clear();
            std::cin.ignore();
        }
    }