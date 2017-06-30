// Copyright 2017 SBlincov

#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_APPLICATION_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_APPLICATION_H_

#include <string>
#include <fstream>
#include <vector>
#include "Head.h"
#include "Monom.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    std::vector<std::string> ParseArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_POLINOM_CALCULATOR_INCLUDE_APPLICATION_H_
