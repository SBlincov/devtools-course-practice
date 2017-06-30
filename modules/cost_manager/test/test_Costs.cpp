// Copyright 2017 SBlincov

#include <gtest/gtest.h>
#include "include/Costs.h"

TEST(Costs, can_create_costs list) {
    ASSERT_NO_THROW(Costs example(1000));
}