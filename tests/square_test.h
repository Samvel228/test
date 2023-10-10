#ifndef SQUARE_H
#define SQUARE_H

#include <gtest/gtest.h>

extern "C" {
#include "myfunc.h"
}

int compareSquareResults(double a, double b, double c, double* expected, int numRoots) {
    double* test = square(a, b, c);

    if (test != NULL && numRoots == 0 || test == NULL && numRoots != 0) {
        return 0;
    }
    if (test == NULL && numRoots == 0){
	return 1;
	}

    if (numRoots == 1 && test[0] != test[1]) {
	return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (test[i] != expected[0] && test[i] != expected[1]) {
            free(test);
            return 0;
        }
    }

    free(test);
    return 1;
}

TEST(SQUARETest, discr_greater_0) {
    double a = 1, b = -3, c = 2;
    double expected[] = {2.0, 1.0};
    int numRoots = 2;
    ASSERT_EQ(compareSquareResults(a, b, c, expected, numRoots), 1);
}

TEST(SQUARETest, discr_less_0) {
    double a = 2, b = 2, c = 2;
    int numRoots = 0;
    ASSERT_EQ(compareSquareResults(a, b, c, NULL, numRoots), 1);
}

TEST(SQUARETest, discr_eq_0) {
    double a = 1, b = -2, c = 1;
    double expected[] = {1.0, 1.0};
    int numRoots = 1;
    ASSERT_EQ(compareSquareResults(a, b, c, expected, numRoots), 1);
}

TEST(SQUARETest, invalid_test_1) {
    double a = 0, b = 0, c = 0;
    int numRoots = 0;
    ASSERT_EQ(compareSquareResults(a, b, c, NULL, numRoots), 1);
}

TEST(SQUARETest, invalid_test_2) {
    double a = 0, b = 2, c = 3;
    double expected[] = {-1.5, -1.5};
    int numRoots = 1;
    ASSERT_EQ(compareSquareResults(a, b, c, NULL, numRoots), 1);
}
#endif // SQUARE_H