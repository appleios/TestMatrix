//
// Created by Aziz Latipov on 24.03.2018.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#include <assert.h>
#include "AlgorithmTests.h"

AlgorithmTests::AlgorithmTests(const Algorithm &algorithm) : algorithm(algorithm)
{
}

void AlgorithmTests::test() const
{
    testInc1();
    testInc2();
}

void AlgorithmTests::testInc1() const
{
    int m1[DIM][DIM] = {
        { K-1, -1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };

    algorithm.incMatrix(m1, K);

    int m2[DIM][DIM] = {
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };

    assert(Utils::isMatrixEqual(m1, m2, K));
}

void AlgorithmTests::testInc2() const
{
    int m1[DIM][DIM] = {
        { K-1, K-1, -1, -1 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };

    algorithm.incMatrix(m1, K);

    int m2[DIM][DIM] = {
        { 0, 0, 1, -1 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };

    assert(Utils::isMatrixEqual(m1, m2, K));
}
