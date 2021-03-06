//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#pragma once


#define DIM 4

typedef int (*Matrix)[DIM];

static inline int X1(int k) { return k / DIM; }
static inline int X2(int k) { return k % DIM; }

struct Utils
{
    static bool isMatrixEqual(Matrix m1, Matrix m2, const int K);
    static void copyMatrix(Matrix src, Matrix dst, const int K);
    static void printMatrixWithQuality(int bestQuality, Matrix matrix, const int K);
};