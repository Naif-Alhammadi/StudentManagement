#pragma once
struct students
{
    int studentId;
    std::string studentName;
    int studentBirthInfo [3];
    std::string studentGender;
    std::string studentSteetInfo;
    int studentPhoneNumber;
    int studentClassDegree;
};
void registrationOfStudents(students arrayinput[], int numbersOfStudents);