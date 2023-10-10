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

TEST(SQUARETest, no_roots) {
    double a = 1, b = 0, c = 1;
    int numRoots = 0;
    ASSERT_EQ(compareSquareResults(a, b, c, NULL, numRoots), 1);
}

TEST(SQUARETest, identical_roots) {
    double a = 1, b = -2, c = 1;
    double expected[] = {1.0, 1.0};
    int numRoots = 2;
    ASSERT_EQ(compareSquareResults(a, b, c, expected, numRoots), 1);
}

TEST(SQUARETest, complex_roots) {
    double a = 1, b = 1, c = 1;
    double expected[] = {-0.5, 0.5};
    int numRoots = 2;
    ASSERT_EQ(compareSquareResults(a, b, c, expected, numRoots), 1);
}

TEST(SQUARETest, large_coefficients) {
    double a = 1e6, b = 1e6, c = 1e6;
    double expected[] = {-1e6, -1e6};
    int numRoots = 2;
    ASSERT_EQ(compareSquareResults(a, b, c, expected, numRoots), 1);
}

TEST(SQUARETest, zero_coefficients) {
    double a = 0, b = 0, c = 0;
    int numRoots = 0;
    ASSERT_EQ(compareSquareResults(a, b, c, NULL, numRoots), 1);
}