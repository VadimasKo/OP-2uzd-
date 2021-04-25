#pragma once

#include "Classes.hpp"

#include <iterator>
#include <algorithm>
#include <list>

template<class T>
void sortStrat1(T &students, T &islaike, T &skolininkai){
    for(typename T::iterator it = students.begin(); it != students.end(); advance(it,1)){
        if(it->getFinalAvg() <5) skolininkai.push_back(*it);
        else islaike.push_back(*it);
    }
}

template<class T>
void sortStrat2(T &students, T &islaike){

    auto it = students.begin();
    while (it != students.end()){
        if(it->getFinalAvg() >= 5){
            islaike.push_back(*it);
            it = students.erase(it);
        } else{
            ++it;  // go to next
    }
    }
}

bool havePassed(Student stud){
    return stud.getFinalAvrg() >= 5;
}

template<class T>
void  sortStrat3(T &students, T &islaike){
    std::sort(students.begin(),students.end());
    typename T::iterator it = find_if(students.begin(), students.end(), havePassed);
    std::copy(it,students.end(), back_inserter(islaike));
    students.resize(students.size()-islaike.size());
}

void sortStrat3(std::list<Student> &students, std::list<Student> &islaike){
    students.sort();
    std::list<Student>::iterator it = students.begin();
    for(auto& stud : students){
        if(stud.getFinalAvrg() >= 5) break;
        advance(it,1);
    }
    islaike.splice(islaike.begin(), students, it, students.end());
}