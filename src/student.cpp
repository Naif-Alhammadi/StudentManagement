#include <iostream>
#include <string>
#include <limits>
#include "../include/student.h"
#include "student.h"

const int arrayStudentsIndex = 100;

void registrationOfStudents(students arrayinput[], int indexOfStudents=1)
{
    int studentGender;
    int backStudentPhoneNumber;
    int backStudentId;
    std::cout << "enter how many students you want to add " << std::endl;
    std::cout << "REQUIRED REGISTRATION INFO"<<'\n';
    std::cout<<"=================================\n";
    // Student Registration Info
        std::cout<<"enter Student id ";
        backStudentId:
         if (!(std::cin >> arrayinput[indexOfStudents].studentId) || arrayinput[indexOfStudents].studentId >= 100000)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ID number must be less than 100000 and does not accpet @ & + try again \n";
            goto backStudentId;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "enter the name of the student ";
        std::getline(std::cin,arrayinput[indexOfStudents].studentName);
        std::cout << "enter the student birth info "<<std::endl;
        std::cout<<"Month : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[0];
        std::cout<<"Day : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[1];
        std::cout<<"Year : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[2];
        std::cout << "student gender\n1: Male 2: Female ";
        std::cin>>studentGender;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(studentGender==1)
        {
            arrayinput[indexOfStudents].studentGender="Male";
        }
        else 
        arrayinput[indexOfStudents].studentGender="Female";
        std::cout << "enter "<<arrayinput[indexOfStudents].studentSteetInfo<<" street Infromation ";
        std::getline(std::cin,arrayinput[indexOfStudents].studentSteetInfo);
        std::cout << "enter student phone number ";
        backStudentPhoneNumber:

        // logic error
        if(!(std::cin>>arrayinput[indexOfStudents].studentPhoneNumber)||arrayinput[indexOfStudents].studentPhoneNumber>=779999999||arrayinput[indexOfStudents].studentPhoneNumber<0)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "phone number is not 9 digits. Phone Number must start with 77 and does not accpet @ & + try again \n";
            goto backStudentPhoneNumber;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "enter student Class Degree ";
        std::cin>>arrayinput[indexOfStudents].studentClassDegree;
    std::cout << "REGISTRATION OF " <<arrayinput[indexOfStudents].studentName<<" HAS BEEN SUCCESSFULLY ENTERD THANK YOU ;)"<<std::endl;
}