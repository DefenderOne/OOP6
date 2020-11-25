#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/report.h"

Node::Node(Student* obj, Node* next) {
    this->obj = obj;
    this->next = next;
}

// done
#pragma region Basic Report Model

BasicReport::BasicReport() {
    head = new Node();
    tail = head;
    _size = 0;
}

BasicReport::~BasicReport() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
}

int BasicReport::size() {
    return _size;
}

void BasicReport::pushAfter(Node* node, Student* obj) {
    Node* newNode = new Node(obj, node->next);
    node->next = newNode;
    _size++;
    if (tail == node) {
        tail = node->next;
    }
}

void BasicReport::printToFile(std::string path) {
    std::ofstream stream(path);
    stream << getList();
    stream.close();
}

#pragma endregion

// done
#pragma region Full Report Model

FullReport::FullReport(std::string path) {
    std::ifstream stream(path);
    while (stream) {
        Student* student = new Student();
        std::string temp;
        for (int i = 0; i < 3; i++) {
            stream >> temp;
            student->fullname.append(temp + ' ');
        }
        stream >> student->grade >> student->group;
        for (int i = 0; i < 4; i++) {
            stream >> student->marks[i]; 
        }
        pushAfter(tail, student);
        stream.get();
    }
    stream.close();
}

std::string FullReport::getList() {
    Node* temp = head->next;
    std::string result;
    result.append(getReportDescription() + '\n');
    while (temp != nullptr) {
        result += temp->obj->getInfo() + ((temp->next != nullptr) ? '\n' : ' ');
        temp = temp->next;
    }
    if (_size == 0) { result = "List has no students matching the list parameters"; }
    return result;
}

std::string FullReport::getReportDescription() {
    return "This list displays everyone presented in a given file";
}

#pragma endregion

// done
#pragma region Excellent Report Model

bool ExcellentReport::hasAllExcellentMarks(Student& student) {
    bool result = true;
    for (int i = 0; i < 4; i++) {
        result &= student.marks[i] == 5;
    }
    return result;
}

ExcellentReport::ExcellentReport(std::string path) {
    std::ifstream stream(path);
    while (stream) {
        std::string temp;
        Student* student = new Student();
        for (int i = 0; i < 3; i++) {
            stream >> temp;
            student->fullname.append(temp + ' ');
        }
        stream >> student->grade >> student->group;
        for (int i = 0; i < 4; i++) {
            stream >> student->marks[i]; 
        }
        if (hasAllExcellentMarks(*student))
            pushAfter(tail, student);
        stream.get();
    }
    stream.close();
}

std::string ExcellentReport::getList() {
    Node* temp = head->next;
    std::string result;
    result.append(getReportDescription() + '\n');
    while (temp != nullptr) {
        result += temp->obj->getInfo() + ((temp->next != nullptr) ? '\n' : ' ');
        temp = temp->next;
    }
    if (_size == 0) { result = "List has no students matching the list parameters"; }
    return result;
}

std::string ExcellentReport::getReportDescription() {
    return "This list displays displays students that have all excellent marks";
}

#pragma endregion

// done
#pragma region Satisfactory Report Model

bool SatisfactoryReport::hasSatisfactoryMarks(Student& student) {
    bool result = false;
    for (int i = 0; i < 4; i++) {
        result = result || student.marks[i] == 3;
    }
    return result;
}

SatisfactoryReport::SatisfactoryReport(std::string path) {
    std::ifstream stream(path);
    while (stream) {
        std::string temp;
        Student* student = new Student();
        for (int i = 0; i < 3; i++) {
            stream >> temp;
            student->fullname.append(temp + ' ');
        }
        stream >> student->grade >> student->group;
        for (int i = 0; i < 4; i++) {
            stream >> student->marks[i]; 
        }
        if (hasSatisfactoryMarks(*student))
            pushAfter(tail, student);
        stream.get();
    }
    stream.close();
}

std::string SatisfactoryReport::getList() {
    Node* temp = head->next;
    std::string result;
    result.append(getReportDescription() + '\n');
    while (temp != nullptr) {
        result += temp->obj->getInfo() + ((temp->next != nullptr) ? '\n' : ' ');
        temp = temp->next;
    }
    if (_size == 0) { result = "List has no students matching the list parameters"; }
    return result;
}

std::string SatisfactoryReport::getReportDescription() {
    return "This list displays all students that have at least one satisfactory mark";
}

#pragma endregion

// done
#pragma region Failure Report Model

bool FailureReport::hasFailureMarks(Student& student) {
    bool result = false;
    for (int i = 0; i < 4; i++) {
        result = result || student.marks[i] == 2;
    }
    return result;
}

bool FailureReport::hasAllFailureMarks(Student& student) {
    bool result = true;
    for (int i = 0; i < 4; i++) {
        result &= student.marks[i] == 2;
    }
    return result;
}

FailureReport::FailureReport(std::string path) {
    std::ifstream stream(path);
    while (stream) {
        std::string temp;
        Student* student = new Student();
        for (int i = 0; i < 3; i++) {
            stream >> temp;
            student->fullname.append(temp + ' ');
        }
        stream >> student->grade >> student->group;
        for (int i = 0; i < 4; i++) {
            stream >> student->marks[i]; 
        }
        if (hasFailureMarks(*student) && !hasAllFailureMarks(*student))
            pushAfter(tail, student);
        stream.get();
    }
    stream.close();
}

std::string FailureReport::getList() {
    Node* temp = head->next;
    std::string result;
    result.append(getReportDescription() + '\n');
    while (temp != nullptr) {
        result += temp->obj->getInfo() + ((temp->next != nullptr) ? '\n' : ' ');
        temp = temp->next;
    }
    if (_size == 0) { result = "List has no students matching the list parameters"; }
    return result;
}

std::string FailureReport::getReportDescription() {
    return "This list displays all students that have at least one Failure Mark";
}

#pragma endregion