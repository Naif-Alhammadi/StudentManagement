#include <iostream>
#include "include/student.h"
#include"fileManager/fileManager.h"
const int arrayStudentsIndex = 50;
void studentPrint(students arrayinput[], int arrayIndex) ;
int main()
{
    int arrayIndex=0;
        students arrayinput[arrayStudentsIndex];
        readStudentsFile(arrayinput,arrayIndex);
        int choseNumber = 0;
        std::cout << "1. ADMIN\n";
        std::cout << "2. TEACHER\n";
        std::cin >> choseNumber;
        switch (choseNumber)
        {
        case 1:
        {
            int choose2;
            std::cout << "1. TEACHERS FILE\n";
            std::cout << "2. STUDENTS FILE\n";
            std::cin>>choose2;
            if(choose2==1)
            std::cout<<"ahmed's functions\n";
            else if(choose2==2)
            studentPrint(arrayinput,arrayIndex);
            else 
            std::cout<<"wrong symbols\n";
             break;

        }
        case 2:
           studentPrint(arrayinput,arrayIndex);
            break;
        
        default:
            std::cout<<"wrong symbol"<<std::endl;
        }
       
}
    void studentPrint(students arrayinput[],int arrayIndex)
    {
        int choseNumber = 0;
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
                editStudentInfromation(arrayinput, arrayIndex);
                break;
            }
            case 5:
                deleteStudentAccount(arrayinput, arrayIndex);
            case 6:
            {
                choseNumber = 6;
                std::cout << "Thank You For Entering, We Hope to See You Again ;)" << std::endl;
                break;
            }
            }
            std::cin.clear();
            std::cin.ignore();
        }
    }