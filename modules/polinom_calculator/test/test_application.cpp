// Copyright 2017 SBlincov

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ApplicationTest, Application_Indicates_Incorrect_Beginning) {
    vector<string> args = {"number", "polinom>"};

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Application_Indicates_Incorrect_End) {
    vector<string> args = {"<number", "polinom"};

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Application_Indicates_Help) {
    vector<string> args = {};
    
    Act(args);
    
    Assert("Спасибо что выбрали калькулятор полиномов!");
}

TEST_F(ApplicationTest, Application_can_multiply_number_and_polinom) {
    vector<string> args = {"2", "1", "5", "4", "1", "1", "4", "3", "2"};
    
    Act(args);
    
    Assert("Result:");
}

TEST_F(ApplicationTest, Application_Indicates_Incorrect_make_polinom) {
    vector<string> args = {"lol", "1", "5", "4", "1", "1", "4", "3", "2"};
    
    Act(args);
    
    Assert("Wrong arguments format!");
}
