#pragma once
#include "Classes.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <vector>

template<class T>
void readData(T &students, std::string fileName){
    class StringToIntError{};
    class GradeValueError{};

    std::stringstream fileStream;
    try{
        std::ifstream data;
        data.open(fileName);

        if(data.fail()) throw std::exception();
        fileStream<<data.rdbuf();
        
        data.close();
    }
    catch(const std::exception &e){
        exit(1);
    }
    std::string line;
    getline(fileStream, line); //getting rid of first line
    
     while(!fileStream.eof()){

        getline(fileStream, line);
        if(fileStream.eof()) break;  //stream.eof() ==1 only after reading past end

        std::stringstream lineStream(line);
        std::string fName, lName;
        std::vector<int> grades;
        int examRes;

        lineStream>>fName>>lName;
        
        while(!lineStream.eof()){
            try{
                int buffInt;
                lineStream>>buffInt;

                if(lineStream.fail()) throw StringToIntError();
                if(buffInt < 0 || buffInt > 10) throw GradeValueError();

                if(lineStream.eof()) examRes = buffInt;
                else grades.push_back(buffInt);
            }
            catch (StringToIntError& e){
                std::cout<<"Exception: Wrong input type in grades, line:"<<students.size()+2<<std::endl;
                grades.clear();
                continue;
            }
            catch (GradeValueError& e){
                std::cout<<"Exception: Wrong input grade value, line:"<<students.size()+2<<std::endl;
                grades.clear();
                continue;
            }
        }
        
        Student buffStud(fName,lName);
        buffStud.setFinalGrades(grades,examRes*1.0);
        grades.clear();

        students.push_back(buffStud);
    }
}

template<class T>
void print(T &students, std::string file){
   
   using std::setw;


    std::stringstream outputStream;
    outputStream<<setw(25); outputStream<<std::left<<"vardas ";
    outputStream<<setw(25); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    std::string line(100, '-');
    outputStream<<line<<'\n';
    
    for(auto& stud : students){
        outputStream<<setw(25); outputStream<<std::left<<stud.getFName();  //https://www.cplusplus.com/reference/ios/left/
        outputStream<<setw(25); outputStream<<std::right<<stud.getLName();
        outputStream.precision(2);
        outputStream<<std::fixed;
        outputStream<<setw(25); outputStream<<std::right<<stud.getFinalMed();
        outputStream<<setw(25); outputStream<<std::right<<stud.getFinalAvrg()<<'\n';      
    }

    line = outputStream.str();

    std::ofstream rez;
    file.insert(0,"Results/");
    rez.open(file);
    rez<<line;
    rez.close();
}