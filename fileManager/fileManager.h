#pragma once
#include<string>
#include "../include/student.h"

struct studentFiles
{
    int studentIndexFile;
    int studentIdFile;
    std::string studentNameFile;
    int studentBirthInfoFile[3];
    std::string studentGenderFile;
    std::string studentStreetInfoFile;
    int studentPhoneNumberFile;
    int studentClassDegreeFile;
};

void showStudentsFile(students arrayFile[], int arrayFileIndex,std::string message = "creat");
void saveStudentsFile(students arrayFile[], int arrayFileIndex,std::string message = "creat");
void readStudentsFile(students arrayFileInput[], int &arrayFileIndex);
void updateStudentsFile(students arrayFile[], int &arrayFileIndex);