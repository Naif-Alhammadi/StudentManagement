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
void studentlist(students arrayprint[],int indexOfStudents);
void specificStudent(students arrayprint[],int indexOfStudents);