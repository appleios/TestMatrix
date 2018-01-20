//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#pragma once


#include "Matrix.h"

#define DIM2 (DIM*DIM)
#define DIM3 (DIM*DIM*DIM)


struct UniversalMatrixSetsComputer
{
    int run() const;

protected:
    int check_f1_fits_points(const int *f1, int k[], int pointsCount) const;
    void fulfill_row_with_f1_x1x2(int A[DIM3], const int *f1, int y, int x1, int x2) const;
    int test_function(const int f1[3], int k_out[3]) const;
};
