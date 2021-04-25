#pragma once 
#include <string>
#include <vector>

class Person{
    protected:
        std::string fName;
        std::string lName;
    public:
        std::string getFName();
        std::string getLName();
        virtual void printJob() = 0;

};

class Student : public Person {
    private:
        double finalAvrg;
        double finalMed;
    public:
        Student();
        Student(std::string fName, std::string lName);
        Student(const Student &other);  //copy constructor
        // ~Student(){};                  //destructor
        Student operator =(const Student &other); //assigment operator

        double getFinalAvrg();
        double getFinalMed();
        void setFinalGrades(std::vector<int> &grades,double examRes);
        bool operator < (Student &obj) const;
        void printJob() override{};      
};