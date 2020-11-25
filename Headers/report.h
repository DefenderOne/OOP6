#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <string>
#include "student.h"

struct Node {
    Student* obj;
    Node* next;
    Node(Student* obj = nullptr, Node* next = nullptr); // +
};

class BasicReport {
    protected:
    Node* head;
    Node* tail;
    void pushAfter(Node* node, Student* obj); // +
    int _size;

    public:
    BasicReport(); // +
    ~BasicReport(); // +
    virtual std::string getList() = 0;
    virtual std::string getReportDescription() = 0;
    void printToFile(std::string path);
    int size(); // +
};

class FullReport : public BasicReport {
    public:
    FullReport(std::string path); // +
    std::string getList(); // !
    std::string getReportDescription(); // +
};

class ExcellentReport : public BasicReport {
    private:
    bool hasAllExcellentMarks(Student& student); // +

    public:
    ExcellentReport(std::string path); // +
    std::string getList(); // !
    std::string getReportDescription(); // +
};

class SatisfactoryReport : public BasicReport {
    private:
    bool hasSatisfactoryMarks(Student& student); // +

    public:
    SatisfactoryReport(std::string path); // +
    std::string getList(); // !
    std::string getReportDescription(); // +
};

class FailureReport : public BasicReport {
    private:
    bool hasFailureMarks(Student& student); // +
    bool hasAllFailureMarks(Student& student); // +

    public:
    FailureReport(std::string path); // +
    std::string getList(); // +
    std::string getReportDescription(); // +
};

#endif