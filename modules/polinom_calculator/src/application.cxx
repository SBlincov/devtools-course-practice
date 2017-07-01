// Copyright 2017 SBlincov

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "include/Head.h"
#include "include/Monom.h"
#include "include/Polinom.h"
#include "include/application.h"

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "Спасибо что выбрали калькулятор полиномов!\n\n";
}

bool IsBeginningOfName(const char* arg) {
    if (arg[0] == '<')
        return true;
    else
        return false;
}

bool IsEndOfName(const char* arg) {
    int i = 0;
    while (arg[i] != '\0')
        ++i;
    if (arg[i - 1] == '>')
        return true;
    else
        return false;
}

std::string GetName(int* cursor, int argc, const char** argv) {
    std::string result = "";

    if (!IsBeginningOfName(argv[*cursor]))
        throw std::string("Wrong arguments format!");

    if (IsEndOfName(argv[*cursor])) {
        return (argv[(*cursor)++]) + 1;
    } else {
        result += (argv[(*cursor)++]) + 1;
        result += ' ';
    }

    while (*cursor < argc) {
        if (IsBeginningOfName(argv[*cursor])) {
            throw std::string("Wrong arguments format!");
        } else if (IsEndOfName(argv[*cursor])) {
            result += argv[(*cursor)++];
            result.pop_back();
            break;
        } else {
            result += argv[*cursor];
            result += ' ';
        }
        ++(*cursor);
    }

    if (*cursor == argc && !IsEndOfName(argv[(*cursor) - 1]))
        throw std::string("Wrong arguments format!");

    return result;
}

std::vector<std::string>
Application::ParseArguments(int argc, const char** argv) {
    std::vector<std::string> args;
    int cur = 1;

    while (cur != argc) {
        args.push_back(GetName(&cur, argc, argv));
    }

    return args;
}

std::string Application::operator()(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return message_;
    }

    std::vector<std::string> args;

    try {
        args = ParseArguments(argc, argv);
    }
    catch(std::string& str) {
        return str;
    }

    int coeff1, indX, indY, indZ, number, coeff2, indX2, indY2, indZ2;
    number = args[0];
    coeff1 = args[1];
    indX = args[2];
    indY = args[3];
    indZ = args[4];
    coeff2 = args[5];
    indX2 = args[6];
    indY2 = args[7];
    indZ2 = args[8];

    int mon[][4] = { {coeff1 , indX, indY, indZ} ,
{ coeff2, indX2, indY2, indZ2} };

    Polinom Pol1(mon , 2);
    Polinom Res = Pol1 * number;

    Res = Res * 2;

    return args[0];
}
