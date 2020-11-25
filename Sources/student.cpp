#include <iostream>
#include <string>
#include "../Headers/student.h"

Student::Student() { }

Student::Student(std::string fullName, int grade, int group, int* marks) {
    this->fullname = fullName;
    this->grade = grade;
    this->group = group;
    for (int i = 0; i < 4; i++) {
        this->marks[i] = marks[i];
    }
}

std::string Student::getInfo() {
    return  fullname + "Grade: " + std::to_string(grade) + ". Group: " + std::to_string(group) + " Exam Marks: " 
            + std::to_string(marks[0]) + ' ' + std::to_string(marks[1]) + ' '
            + std::to_string(marks[2]) + ' ' + std::to_string(marks[3]);
}