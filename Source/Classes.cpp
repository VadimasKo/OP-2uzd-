#include "../Include/Classes.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

// functions ======================
double getAverage(std::vector<int> &grades){
    double sum = 0;

    for(int i=0; i<grades.size(); i++) sum += grades[i];

    if(sum == 0) return 0;
    return sum/grades.size();
}

double getMedian(std::vector<int> &grades){
    std::sort(grades.begin(),grades.end());

    if(grades.size() == 0) return 0;
    if(grades.size()%2 == 1) return grades[grades.size()/2];
    else return (grades[grades.size()/2 -1] + grades[grades.size()/2])/2;
}

// class methods ==================
//                  Person
std::string Person::getFName(){ return this->fName;};
std::string Person::getLName(){ return this->lName;};

//                  Student
Student::Student(std::string fName, std::string lName){
    this->fName = fName;
    this->lName = lName;
    this->finalAvrg = 0;
    this->finalMed = 0;
}

Student Student::operator=(const Student& other){
    this->fName = other.fName;
    this->lName = other.lName;
    this->finalAvrg = other.finalAvrg;
    this->finalMed = other.finalMed;

    return *this;
}

Student::Student(const Student &other){
    // std::memcpy(this, &other, sizeof(Student)); // dont use memcpy undefined behavior inside vector
    this->fName = other.fName;
    this->lName = other.lName;
    this->finalAvrg = other.finalAvrg;
    this->finalMed = other.finalMed;
}

void Student::setFinalGrades(std::vector<int> &grades,double examRes){
    examRes *=0.6;
    this->finalAvrg =((getAverage(grades)*0.4) + examRes);
    this->finalMed =((getMedian(grades)*0.4)+ examRes);
}
double Student::getFinalAvrg(){ return this->finalAvrg;}
double Student::getFinalMed(){ return this->finalMed;}
bool Student::operator < (Student &obj) const {
    return(finalAvrg < obj.finalAvrg);
}

