#include <iostream>
#include <string>
#include <limits>
#include"../fileManager/fileManager.h"
#include "../include/student.h"
#include "student.h"

void registrationOfStudents(students arrayinput[], int &indexOfStudents)
{    
        int studentGender;
    int backStudentPhoneNumber;
    std::cout << "REQUIRED REGISTRATION INFO"<<'\n';
    std::cout<<"=================================\n";
    // Student Registration Info
    std::cout<<"enter Student id ";
    while (!(std::cin >> arrayinput[indexOfStudents].studentId) || !(studentIdCheck(arrayinput, indexOfStudents)) || (arrayinput[indexOfStudents].studentId <= 0))
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
        int holdindex=indexOfStudents;
        saveStudentsFile(arrayinput,holdindex);
        showStudentsFile(arrayinput,holdindex);
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
        for (int j = i ; j < indexOfStudents; j++)
        {
            if ((arrayinput[i].studentName == arrayinput[j+1].studentName))
            {
                checkOfStudent=false;
                break;
            }
            else
            checkOfStudent= true;
        }
        if(!checkOfStudent){
            break;
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
        for (int j = i ; j < indexOfStudents; j++)
        {
            if ((arrayinput[i].studentId == arrayinput[j+1].studentId))
            {
                checkOfStudent=false;
                break;
            }
            else
            checkOfStudent= true;
        }
        if (!checkOfStudent)
        {
            break;
        }
    }
    return checkOfStudent;
}
}
void studentShow(students arrayShow[],int indexShow)
{
    std::cout << "student id is " << arrayShow[indexShow].studentId << std::endl;
    std::cout << "student name is " << arrayShow[indexShow].studentName << std::endl;
    std::cout << "student  birth info day: " << arrayShow[indexShow].studentBirthInfo[0];
    std::cout << " / month: " << arrayShow[indexShow].studentBirthInfo[1];
    std::cout << " / year: " << arrayShow[indexShow].studentBirthInfo[2] << std::endl;
    std::cout << "student gender is " << arrayShow[indexShow].studentGender << std::endl;
    std::cout << "student phone number is " << arrayShow[indexShow].studentPhoneNumber << std::endl;
    std::cout << "student class degree is " << arrayShow[indexShow].studentClassDegree << std::endl;
}
void studentlist(students arrayprint[],int indexOfStudents,int iValue){
    for(int i=iValue;i<indexOfStudents;i++)
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
// Edit information
void editStudentInfromation(students arrayedit[],const int indexOfStudents){
    int editId;
    int studentSearch=0;
    bool studenIdFound=true;
    std::cout<<"enter student id you want to edit ";
    std::cin>>editId;
    for(int i=0;i<indexOfStudents;i++)
    {
        if(editId==arrayedit[i].studentId)
        {
            studentSearch=i;
            studentShow(arrayedit,i);
                studenIdFound = true;
            break;
        }
        else
            studenIdFound = false;
    }
    if(studenIdFound)
    {
        int editStudent;
        int backStart;
        backStart:
        std::cout<<"edit\n 1.name 2.id 3.gender 4.phonenumber 5.birthinfo 6.streetinfo 7.classgrade ";
        std::cin>>editStudent;
        switch(editStudent)
        {
            case 1:{
                        std::cin.ignore();
                        std::cout<<"enter the new name : ";
                        std::getline(std::cin,arrayedit[studentSearch].studentName);
                        while (!studentNameCheck(arrayedit, indexOfStudents))
                        {
                            std::cout << "sudent name is already exist try again\n";
                            std::getline(std::cin, arrayedit[studentSearch].studentName);
                        }
                        std::cout<<"name has been successfully edit thank you ;)\n";
                        std::cin.ignore();
                        break;
                    }
            case 2:{
                        std::cout<<"enter the new Id : ";
                        while (!(std::cin >> arrayedit[studentSearch].studentId) || !(studentIdCheck(arrayedit, indexOfStudents)) || (arrayedit[studentSearch].studentId <= 0))
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "ID number must be more than 0 and does not accpet @ & + try again \n";
                        }
                        std::cout<<"Id has been successfully edit thank you ;)\n";
                        break;
                    }
            case 3:{
                        std::cout<<"enter 1:male 2:famle ";
                        std::cin>>arrayedit[studentSearch].studentGender;
                        std::cout<<"gender has been successfully edit thank you ;)\n";
                        break;
                    }
            case 4:{
                        int studentPhone;
                        int backStudentPhoneNumber2;
                                std::cout
                            << "enter the new phonenumber : ";
                            backStudentPhoneNumber2:
                        std::cin>>studentPhone;
                        if ((studentPhone <= 779999999 && studentPhone >= 770000000) || (studentPhone <= 739999999 && studentPhone >= 730000000) || (studentPhone <= 719999999 && studentPhone >= 710000000))
                        {
                            arrayedit[studentSearch].studentPhoneNumber = studentPhone;
                        }
                        else
                        {
                            std::cin.clear();
                            std::cin.ignore();
                            std::cout << "phone number is not 9 digits. Phone Number must start with 77,73 or 71 and does not accpet @ & + try again \n";
                            goto backStudentPhoneNumber2;
                        }
                        std::cout<<"phoneNumber has been successfully edit thank you ;)\n";
                        break;
                    }
            case 5:{
                        std::cout<<"enter the new month : ";
                        std::cin>>arrayedit[studentSearch].studentBirthInfo[0];
                        std::cout << "enter the new day : ";
                        std::cin>>arrayedit[studentSearch].studentBirthInfo[1];
                        std::cout << "enter the new year : ";
                        std::cin>>arrayedit[studentSearch].studentBirthInfo[2];
                        std::cout<<"birth has been successfully edit thank you ;)\n";
                        break;
                    }
            case 6:{
                        std::cout<<"enter the new streetinfo : ";
                        std::cin>>arrayedit[studentSearch].studentStreetInfo;
                        std::cout<<"streetinfo has been successfully edit thank you ;)\n";
                        break;
                    }
            case 7:{
                        std::cout<<"enter the new classgrade : ";
                        std::cin>>arrayedit[studentSearch].studentClassDegree;
                        std::cout<<"classgrade has been successfully edit thank you ;)\n";
                        break;
                    }
             default:{
                    std::cout<<"your enter a wrong symbol\n";
                    goto backStart;
                        break;
                    }
                }
                saveStudentsFile(arrayedit, indexOfStudents,"edit");
                showStudentsFile(arrayedit, indexOfStudents,"edit");
        }
    else 
    {
        std::cout<<"user is not existing yet press 1 to added\n";
        return;
    }

}
// Delet an account
void deleteStudentAccount(students arrayDelet[], int &indexOfStudents){
    std::cout<<"enter Admin Password to start : ";
    int password;
    std::cin>>password;
    if(password==123)
    {
        bool isFound;
        int iValue;
        int idDeletSearch;
        std::cout<<"enter the id of student : "<<std::endl;
        std::cin>>idDeletSearch;
        for(int i=0;i<indexOfStudents;i++)
        {
        if(idDeletSearch==arrayDelet[i].studentId)
        {
            studentShow(arrayDelet, i);
            isFound=true;
            iValue=i;
            break;
        }
        else
        isFound=false;
        }
        if(isFound)
        {
            for(int i=iValue;i<indexOfStudents;i++){
                if(i+1==indexOfStudents)
                {
                    indexOfStudents--;
                    std::cout<<"YOU HAVE DELELTE THE ACCOUNT \n";
                    break;
                }
                arrayDelet[i].studentName=arrayDelet[i+1].studentName;
                arrayDelet[i].studentId=arrayDelet[i+1].studentId;
                arrayDelet[i].studentBirthInfo[0]=arrayDelet[i+1].studentBirthInfo[0];
                arrayDelet[i].studentBirthInfo[1]=arrayDelet[i+1].studentBirthInfo[1];
                arrayDelet[i].studentBirthInfo[2]=arrayDelet[i+1].studentBirthInfo[2];
                arrayDelet[i].studentClassDegree=arrayDelet[i+1].studentClassDegree;
                arrayDelet[i].studentGender=arrayDelet[i+1].studentGender;
                arrayDelet[i].studentPhoneNumber=arrayDelet[i+1].studentPhoneNumber;
                arrayDelet[i].studentStreetInfo=arrayDelet[i+1].studentStreetInfo;
            }
        }
        else{
            std::cout<<"you entered a wrong id please try again later"<<std::endl;
        }
    }
    else
    std::cout<<"password is incorrect try again later\n";

}