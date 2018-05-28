//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#pragma once
#include "Matrix.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int N = 2+1;
const int K = DIM;


struct SubMatrix {
    int rowMin, rowMax;
    int colMin, colMax;
};


struct Algorithm
{
    bool shouldApplyAlgorithm(Matrix m, const int K) const;
    bool shouldFinalizeAlgorithm(Matrix m, const int K) const;
    void incMatrix(Matrix m, const int K) const;
    void incSubMatrix(Matrix m, SubMatrix &subMatrix, const int K) const;

    int matrixUniversalityQuality(Matrix m, const int K) const;
};
