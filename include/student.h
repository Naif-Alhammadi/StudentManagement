#pragma once
struct students
{
    int studentId;
    std::string studentName;
    int studentBirthInfo [3];
    std::string studentGender;
    std::string studentStreetInfo;
    int studentPhoneNumber;
    int studentClassDegree;
};
void registrationOfStudents(students arrayinput[], int & numbersOfStudents);
bool studentNameCheck(students arrayinput[], int indexOfStudents);
bool studentIdCheck(students arrayinput[], int indexOfStudents);
void studentShow(students arrayShow[], int indexShow);
void studentlist(students arrayprint[], int indexOfStudents, int iValue = 0);
void specificStudent(students arrayprint[],int indexOfStudents);
void editStudentInfromation(students arrayedit[],const int indexOfStudents);
void deleteStudentAccount(students arrayDelet[],int & indexOfStudents);