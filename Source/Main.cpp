#include "../Include/Classes.hpp"
#include "../Include/GenerateRecords.hpp"
#include "../Include/InputOutput.hpp"

#include <vector>
#include <string>
#include <iostream>



int main(){
    generateRecords(100);
    std::vector<Student> students;
    readData(students,"Results/studentai.txt");
     print(students,"rezultatas.txt");

}