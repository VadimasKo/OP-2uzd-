#include <gtest/gtest.h>
#include "../Include/Classes.hpp"
#include <vector>


TEST(StudentClassTests, StudentConstructorWNames){
    Student a("Vardenis", "Pavardenis");
    EXPECT_EQ("Vardenis", a.getFName());
    EXPECT_EQ("Pavardenis", a.getLName());
}

TEST(StudentClassTests, StudentFinalGrades){
    Student a("Vardenis", "Pavardenis");
    std::vector<int> grades = {1,5,6,8,9,10};
    a.setFinalGrades(grades, 10.0);

    EXPECT_EQ(8.6, a.getFinalAvrg());
    EXPECT_EQ(8.8, a.getFinalMed());
}