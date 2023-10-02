#ifndef SQUARE_H
#define SQUARE_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "myfunc.h"
}

TEST(SQUARETest, num0) {
    ASSERT_EQ(square(2, -5, 2)[0], 2);
    ASSERT_EQ(square(2, -5, 2)[1], 0.5);
}

#endif // FIBONACHI_H
