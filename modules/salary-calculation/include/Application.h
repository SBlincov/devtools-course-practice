// Copyright 2017 Kiselev Ivan

#ifndef MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
#define MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_

#include <string>
#include "include/salary_calculation.h"

class Application {
 public:
    Application(int salary_per_hour = 20, int needed_hours = 160,
        int work_hours = 160, int workday = 9, int overtime_bonus = 25);
    Application(const Application & pApp);
    int operator()(int argv = 0, int args = 0);
    void PrintHelp();

 private:
     Salary* worker_salary_;
};

#endif  // MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
