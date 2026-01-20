#include <iostream>
#include <string>
#include <limits>
#include "../include/student.h"
#include "student.h"

const int arrayStudentsIndex = 100;

void registrationOfStudents(students arrayinput[], int &indexOfStudents)
{
     int studentGender;
    int backStudentPhoneNumber;
    std::cout << "REQUIRED REGISTRATION INFO"<<'\n';
    std::cout<<"=================================\n";
    // Student Registration Info
    // there is a bug when adding the second student
    std::cout<<"enter Student id ";
    while (!(std::cin >> arrayinput[indexOfStudents].studentId) || !(studentIdCheck(arrayinput, indexOfStudents)) || (arrayinput[indexOfStudents].studentId <=0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "ID number must be more than 0 and does not accpet @ & + try again \n";
    }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "enter the name of the student ";
        std::getline(std::cin,arrayinput[indexOfStudents].studentName);
        while (!studentNameCheck(arrayinput,indexOfStudents))
        {
            std::cout<<"sudent name is already exist try again\n";
            std::getline(std::cin,arrayinput[indexOfStudents].studentName);
        }

        std::cout << "enter the student birth info "<<std::endl;
        std::cout<<"Month : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[0];
        std::cout<<"Day : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[1];
        std::cout<<"Year : ";
        std::cin>>arrayinput[indexOfStudents].studentBirthInfo[2];
        std::cout << "student gender\n1: Male 2: Female ";
        std::cin>>studentGender;
        if(studentGender==1)
        {
            arrayinput[indexOfStudents].studentGender="Male";
        }
        else if(studentGender==2)
        {
            arrayinput[indexOfStudents].studentGender="Female";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "enter student street Infromation ";
        std::getline(std::cin,arrayinput[indexOfStudents].studentStreetInfo);
        std::cout << "enter student phone number ";
        
        backStudentPhoneNumber:
        int studentPhone;
        std::cin >> studentPhone;
        if ((studentPhone <= 779999999 && studentPhone >= 770000000) || (studentPhone <= 739999999 && studentPhone >= 730000000) || (studentPhone <= 719999999 && studentPhone >= 710000000))
        {
            arrayinput[indexOfStudents].studentPhoneNumber=studentPhone;
        }
        else{
            std::cin.clear();
            std::cin.ignore();
            std::cout << "phone number is not 9 digits. Phone Number must start with 77,73 or 71 and does not accpet @ & + try again \n";
            goto backStudentPhoneNumber;
        }
        std::cout << "enter student Class Degree ";
        std::cin>>arrayinput[indexOfStudents].studentClassDegree;
    std::cout << "REGISTRATION OF " <<arrayinput[indexOfStudents].studentName<<" HAS BEEN SUCCESSFULLY ENTERD THANK YOU ;)"<<std::endl;
    indexOfStudents++;
}
bool studentNameCheck(students arrayinput[],const int indexOfStudents)
{
    if(indexOfStudents<1)
    {
        return true;
    }
    else
    {
    bool checkOfStudent;
    for (int i = 0; i < indexOfStudents; i++)
    {
        for (int j = i + 1; j < indexOfStudents; i++)
        {
            if ((arrayinput[i].studentName == arrayinput[j].studentName))
            checkOfStudent=false;
            else
            checkOfStudent= true;
        }
    }
    return checkOfStudent;
        }
}
bool studentIdCheck(students arrayinput[],const int indexOfStudents)
{
    bool checkOfStudent;
    if(indexOfStudents<1)
    {
        return true;
    }
    else
    {
    for (int i = 0; i < indexOfStudents; i++)
    {
        for (int j = i + 1; j < indexOfStudents+1; i++)
        {
            if ((arrayinput[i].studentId == arrayinput[j].studentId))
            checkOfStudent=true;
            else
            checkOfStudent= false;
        }
    }
}
return checkOfStudent;
}
void studentlist(students arrayprint[],int indexOfStudents){
    for(int i=0;i<indexOfStudents;i++)
    {
        std::cout << "student id is " << arrayprint[i].studentId<<std::endl;
        std::cout << "student name is " << arrayprint[i].studentName<<std::endl;
        std::cout << "student  birth info day: " << arrayprint[i].studentBirthInfo[0];
        std::cout << " / month: " << arrayprint[i].studentBirthInfo[1];
        std::cout << " / year: " << arrayprint[i].studentBirthInfo[2]<<std::endl;
        std::cout << "student gender is " << arrayprint[i].studentGender<<std::endl;
        std::cout << "student phone number is " << arrayprint[i].studentPhoneNumber<<std::endl;
        std::cout << "student class degree is " << arrayprint[i].studentClassDegree<<std::endl;
    }
}
void specificStudent(students arrayprint[], int indexOfStudents)
{
    int searchForSpecificStudent;
    bool found;
    std::cout<<"enter the methode of searching"<<'\n';
    std::cout<<"==============================\n";
    std::cout<<"1. By Student Name 2. By Student Id\n";
    std::cin>>searchForSpecificStudent;
    switch(searchForSpecificStudent)
    {
    case 1:
    {
        std::string studentNameSearch;
        int searchByName;
        std::cout<<"enter student name ";
        std::cin>>studentNameSearch;
        for(int i=0;i<indexOfStudents;i++)
        {

            if(arrayprint[i].studentName==studentNameSearch)
            {
                searchByName=i;
                found=true;

            }
            else
            found =false;
        }
        if(found)
        {
        std::cout << arrayprint[searchByName].studentName << " id is " << arrayprint[searchByName].studentId << std::endl;
        std::cout << arrayprint[searchByName].studentName << " birth info day: " << arrayprint[searchByName].studentBirthInfo[0];
        std::cout << " / month: " << arrayprint[searchByName].studentBirthInfo[1];
        std::cout << " / year: " << arrayprint[searchByName].studentBirthInfo[2] << std::endl;
        std::cout << arrayprint[searchByName].studentName << " gender is " << arrayprint[searchByName].studentGender << std::endl;
        std::cout << arrayprint[searchByName].studentName << " phone number is " << arrayprint[searchByName].studentPhoneNumber << std::endl;
        std::cout << arrayprint[searchByName].studentName << " class degree is " << arrayprint[searchByName].studentClassDegree << std::endl;
    }
    else
        std::cout << "student name is not in the list\n";
    break;}
    case 2:
    {
         int studentIdSearch;
        int searchById;
        std::cout << "enter student ID ";
        while (!(std::cin >> studentIdSearch) || (studentIdSearch <= 0))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ID number must be more than 0 and does not accpet @ & + try again \n";
        }
        for (int i = 0; i < indexOfStudents; i++)
        {

            if (arrayprint[i].studentId == studentIdSearch)
            {
                searchById = i;
            found = true;
            }
            else 
            found = false;
        }
        if(found)
        {
        std::cout << arrayprint[searchById].studentId << " name is " << arrayprint[searchById].studentId << std::endl;
        std::cout << arrayprint[searchById].studentName << " birth info day: " << arrayprint[searchById].studentBirthInfo[0];
        std::cout << " / month: " << arrayprint[searchById].studentBirthInfo[1];
        std::cout << " / year: " << arrayprint[searchById].studentBirthInfo[2] << std::endl;
        std::cout << arrayprint[searchById].studentName << " gender is " << arrayprint[searchById].studentGender << std::endl;
        std::cout << arrayprint[searchById].studentName << " phone number is " << arrayprint[searchById].studentPhoneNumber << std::endl;
        std::cout << arrayprint[searchById].studentName << " class degree is " << arrayprint[searchById].studentClassDegree << std::endl;
        }
        else std::cout << "student Id is not in the list\n";
        break;}
}
}