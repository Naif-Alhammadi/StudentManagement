#include <iostream>
#include <string>
#include "../include/student.h"
#include "student.h"
const int arrayStudentsIndex = 100;

void input(students arrayinput[], int numbersOfStudents)
{
    std::cout << "enter how many students you want to add " << std::endl;
    std::cin >> numbersOfStudents;
    std::cout << "enter Students names";
    for (int i = 0; i < numbersOfStudents; i++)
    {
        std::cout << "enter the name of " << i + 1 << "student " << std::endl;
        std::cin>>arrayinput[i].studentsNames;
    }
}