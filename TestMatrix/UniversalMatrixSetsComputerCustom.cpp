//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//
#include "UniversalMatrixSetsComputerCustom.h"


int UniversalMatrixSetsComputerCustom::test_function2(const int f1[3]) const
{
    int k[DIM2] = { -1 };
    for (int i = 0; i < DIM2; i++) k[i] = i;

    // составляем матрицу A[i,j] == 1 iff fj(ki) != f1(ki) = fu(ki)
    // i = 0,1,2 для k[i]
    // j = пробегаемся по всем функциям не равным f1
    int fits = check_f1_fits_points(f1, k, DIM2);

    if (fits == 1) {
        return 1;
    }

    return 0;
}
