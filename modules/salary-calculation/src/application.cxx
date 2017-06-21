// Copyright 2017 Kiselev Ivan

#include <string>
#include <iostream>
#include "../include/Application.h"

Application::Application(int salary_per_hour, int needed_hours,
    int work_hours, int workday, int overtime_bonus) {
    worker_salary_ = new Salary(salary_per_hour, needed_hours, work_hours,
        workday);
    worker_salary_->SetOvertimeBonus(overtime_bonus);
    worker_salary_->CalculateSalary();
}

Application::Application(const Application& pApp) {
    worker_salary_ = new Salary(pApp.worker_salary_->GetSalaryPerHour(),
        pApp.worker_salary_->GetNeededHours(),
        pApp.worker_salary_->GetWorkHours(),
        pApp.worker_salary_->GetWorkDay());
    worker_salary_->SetOvertimeBonus(pApp.worker_salary_->GetOvertimeBonus());
    worker_salary_->CalculateSalary();
}

int Application::operator()(int argv, char** argc) {
    if (argv == 0) {
        PrintHelp();
        return 0;
    }
    int val = ToInt(argc);
    switch (argv) {
        case 1: {
            worker_salary_->SetSalaryPerHour(val);
            break;
        }
        case 2 : {
            worker_salary_->SetWorkHours(val);
            break;
        }
        case 3 : {
            worker_salary_->SetOvertimeBonus(val);
            break;
        }
        case 4 : {
            worker_salary_->SetAdminRest(val);
            break;
        }
        case 5 : {
            worker_salary_->SetNeededHours(val);
            break;
        }
        case 6 : {
            worker_salary_->SetWorkHours(val);
            break;
        }
        case 7 : {
            worker_salary_->CalculateSalary();
            return worker_salary_->GetSalary();
        }
        default: {
            PrintHelp();
            break;
        }
    }
    return argv;
}

void Application::PrintHelp() {
    std::cout << "1 - Set salary per hour , Value \n";
    std::cout << "2 - Set work hours , Value \n";
    std::cout << "3 - Set overtime bonus , Value \n";
    std::cout << "4 - Set admin rest , Value \n";
    std::cout << "5 - Set needed hours\n";
    std::cout << "6 - Set How many hours in workday , Value \n";
    std::cout << "7 - Get Salary\n";
}

int Application::ToInt(char** argc) {
    return 100;
}
