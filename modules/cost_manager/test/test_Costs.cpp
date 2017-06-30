// Copyright 2017 SBlincov

#include <gtest/gtest.h>

#include "include/credit_calculator.h"

TEST(Costs,
    Set_length_list_less_1) {
    // Arrange
    // Act+Assert
    ASSERT_ANY_THROW(Costs test(0));
}