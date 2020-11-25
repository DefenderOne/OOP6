#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    std::string fullname;
    int grade, group;
    int marks[4];
    Student();
    Student(std::string fullName, int grade, int group, int* marks);  
    std::string getInfo();
};

#endif


