#include "../Include/Timer.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

void Timer::startClock() { start = highResClock::now();}
void Timer::calcInput(){ input = highResClock::now() - start; }
void Timer::calcSort(){ sort = highResClock::now() - start; }
void Timer::calcOutput(){ output = highResClock::now() - start;}

void Timer::printRes(bool showTitle, std::string name){
    using std::setw;

    if(showTitle) std::cout<<setw(20)<<" "<<"| Input dur. | Sort dur. | Output dur. | \n"
                           <<setw(20)<<" "<<"|:----------:|-----------|-------------| \n";

    std::cout.precision(2);
    std::cout<<std::fixed;
    std::cout<<setw(19)<<std::left<<name<<" | "<<setw(10)<<input.count()<<" | "<<setw(9)<<sort.count()<<" | "<<setw(11)<<output.count()<<" | "<<"\n";
}
double Timer::giveDuration(){ 
    durationDouble duration = highResClock::now() - start;
    return duration.count();
}

int main(){
    Timer time;
    time.printRes(1,"Strat1");
    time.printRes(0,"Strat1");
}