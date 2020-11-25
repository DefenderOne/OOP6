#include <iostream>
#include "../Headers/report.h";

int main() {
    std::cout << "Select which report list you would like to see\n";
    std::cout << "1. Full Report List\n2. Excellent Report List\n3. Satisfactory Report List\n4. Failure Report List\n";
    int choice;
    std::cin >> choice;
    BasicReport* base;
    std::string path = "Resources\\input.txt";
    switch (choice)
    {
        case 1: {
            base = new FullReport(path);
            break;
        }
        case 2: {
            base = new ExcellentReport(path);
            break;
        }
        case 3: {
            base = new SatisfactoryReport(path);
            break;
        }
        case 4: {
            base = new FailureReport(path);
            break;
        }
        default: {
            std::cout << "Selected wrong position\nEnd of the program";
            return 0;
        }
    }
    std::cout << base->getReportDescription() << std::endl;
    std::cout << base->getList() << std::endl;
    std::cout << "Size of the selected list: " << base->size() << std::endl;
    base->printToFile("Resources\\output.txt");
}