#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"../include/student.h"
#include"fileManager.h"
studentFiles arrayUpdateFile[100];
int callfun=0;
// SAVE STUDENTS RECORED
void showStudentsFile(students arrayFile[], int arrayFileIndex,std::string message)
{
    int holdStudentIndex=arrayFileIndex;
    std::ofstream studentsFileSave;
    // studentsFileSave.open("SchoolM.txt",std::ios::out | std::ios::app);
    if (message == "edit")
        studentsFileSave.open("SchoolData.txt", std::ios::out);
    else
        studentsFileSave.open("SchoolData.txt", std::ios::out | std::ios::app);
    arrayFileIndex=0;
    studentsFileSave << std::left << std::setw(6) <<"id"<< std::setw(6) << "name" << std::setw(12) << "birth" << std::setw(6) << "gender" <<std::setw(6)<<"street"<< std::setw(12) << "phone" << std::setw(6) << "degree" <<std::endl<<std::string(56,'-')<<std::endl;
    while(!(arrayFileIndex==holdStudentIndex)){
        studentsFileSave << std::left << std::setw(6) << arrayFile[arrayFileIndex].studentId;
        studentsFileSave << std::setw(6)<<arrayFile[arrayFileIndex].studentName;
        studentsFileSave << arrayFile[arrayFileIndex].studentBirthInfo[0]<<'/';
        studentsFileSave << arrayFile[arrayFileIndex].studentBirthInfo[1]<<'/';
        studentsFileSave << std::setw(12) <<arrayFile[arrayFileIndex].studentBirthInfo[2];
        studentsFileSave <<std::setw(6)<< arrayFile[arrayFileIndex].studentGender;
        studentsFileSave <<std::setw(6) << arrayFile[arrayFileIndex].studentStreetInfo ;
        studentsFileSave <<std::setw(12) << arrayFile[arrayFileIndex].studentPhoneNumber ;
        studentsFileSave << std::setw(6) << arrayFile[arrayFileIndex].studentClassDegree << std::setw(6);
        studentsFileSave<<std::endl;
        arrayFileIndex++;
    }
    studentsFileSave.close();
}
void saveStudentsFile(students arrayFile[], int arrayFileIndex, std::string message)
{
    int holdStudentIndex=arrayFileIndex;
    std::ofstream studentsFileSave;
    // studentsFileSave.open("SchoolData.txt",std::ios::out);
    if(message=="edit")
    studentsFileSave.open("SchoolData.txt",std::ios::out);
    else
    studentsFileSave.open("SchoolData.txt",std::ios::out | std::ios::app);

    arrayFileIndex=0;
     while (!(arrayFileIndex == holdStudentIndex))
    {
        studentsFileSave << arrayFile[arrayFileIndex].studentId<<' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentName << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentBirthInfo[0] << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentBirthInfo[1] << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentBirthInfo[2] << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentGender << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentStreetInfo << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentPhoneNumber << ' ';
        studentsFileSave << arrayFile[arrayFileIndex].studentClassDegree << ' ';
        studentsFileSave<<std::endl;
        arrayFileIndex++;
    }
    studentsFileSave.close();
}
// READ STUDENTS RECORED
void readStudentsFile(students arrayFileInput[], int &arrayFileIndex)
{
    arrayFileIndex=0;
    std::ifstream studentsFileRead;
    studentsFileRead.open("SchoolData.txt",std::ios::in);
    if(!studentsFileRead.is_open())
    {
        std::cout<<"file could not be opened\n";
        return;
    }
    while (studentsFileRead >> arrayFileInput[arrayFileIndex].studentId)
    {
     studentsFileRead >> arrayFileInput[arrayFileIndex].studentName >> arrayFileInput[arrayFileIndex].studentBirthInfo[0] >> arrayFileInput[arrayFileIndex].studentBirthInfo[1] >> arrayFileInput[arrayFileIndex].studentBirthInfo[2] >> arrayFileInput[arrayFileIndex].studentGender >> arrayFileInput[arrayFileIndex].studentStreetInfo >> arrayFileInput[arrayFileIndex].studentPhoneNumber >> arrayFileInput[arrayFileIndex].studentClassDegree;
        arrayFileIndex++;
    }
    studentsFileRead.close();
}
// UPDATE STUDENTS RECORED
// void updateStudentsFile(students arrayFile[], int &arrayFileIndex){
// std::ofstream tempUpdate;
// std::ifstream intempUpdate;
// tempUpdate.open("SchoolData2.txt",std::ios::out);
// intempUpdate.open("temp",std::ios::in);
// int holdStudentIndex = arrayFileIndex;
// arrayFileIndex = 0;
// while (!(arrayFileIndex == holdStudentIndex))
// {
//     tempUpdate << arrayFile[arrayFileIndex].studentId << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentName << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentBirthInfo[0] << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentBirthInfo[1] << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentBirthInfo[2] << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentGender << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentStreetInfo << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentPhoneNumber << ' ';
//     tempUpdate << arrayFile[arrayFileIndex].studentClassDegree << ' ';
//     tempUpdate << std::endl;
//     arrayFileIndex++;
// }
// arrayFileIndex=0;
// if (!tempUpdate.is_open())
// {
//     std::cout << "file could not be opened\n";
//     return;
// }
// while (intempUpdate >> arrayUpdateFile[arrayFileIndex].studentIdFile)
// {
//     intempUpdate >> arrayUpdateFile[arrayFileIndex].studentNameFile >> arrayUpdateFile[arrayFileIndex].studentBirthInfoFile[0] >> arrayUpdateFile[arrayFileIndex].studentBirthInfoFile[1] >> arrayUpdateFile[arrayFileIndex].studentBirthInfoFile[2] >> arrayUpdateFile[arrayFileIndex].studentGenderFile >> arrayUpdateFile[arrayFileIndex].studentStreetInfoFile >> arrayUpdateFile[arrayFileIndex].studentPhoneNumberFile >> arrayUpdateFile[arrayFileIndex].studentClassDegreeFile;
//     arrayFileIndex++;
// }

// }