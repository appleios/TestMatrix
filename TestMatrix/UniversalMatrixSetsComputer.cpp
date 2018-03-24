//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//
#include <cstdio>
#include "UniversalMatrixSetsComputer.h"

static int m[DIM][DIM] = {
    {11, 14,  3,  3,  8,  8,  2,  1,  13,  12,  15,  4,  0, 12, 12, 1 },
    {5,  14,   0, 12, 0,  3, 12,  11,  3,  12,  12,  9,  8,  7, 11, 3 },
    {5,  14,  6,  13, 6,  8, 14,  3,   4,  13,   8,  5,  9,  4,  6, 12},
    {11, 5,   8,  11, 9,  5,  6,  12,  1,   2,   5,  9,  9,  0, 12, 14},
    {14, 2,   12,  4, 10, 10, 8,  15,  8,   0,   4,  1,  4, 10, 13, 15},
    {15, 6,   11,  8, 11, 1,  4,  12,  4,   9,   6,  13, 9,  2, 12,  7},
    {5,  8,   12, 15, 2,  4, 14,  10,  4,   2,  12,  8,  12, 9,  7, 12},
    {15, 2,   4,  10, 4,  9,  7,  8,   2,  13,   5,  12, 15, 1,  3,  4},
    {9,  15,  4,  12, 3,  2,  6,  7,   5,   2,  15,  1,  12, 7, 13, 11},
    {9,  2,   6,  13, 11, 13, 5,  13,  10, 11,   9,  9,  12,13, 14,  6},
    {12, 2,   2,  0,  4,  8,  7,  9,   11,  7,   11, 7,  14, 8,  2,  7},
    {10, 8,   5,  5,  5,  10, 3,  15,  5,  12,   9,  2,  9,  7,  8,  6},
    {9,  10,  6,  13, 2,  13, 7,  13,  4,   2,   4,  2,  10, 7, 10,  5},
    {15, 15,  10, 5,  9,  13, 4,  15,  10, 13,   1,  3,  4,  9,  9, 13},
    {3,  15,  11, 5, 13,  2,  3,  1,   4,   7,   4,  14, 14, 14, 3, 14},
    {13, 14,  3,  6, 11,  7,  5,  5,   5,   6,   9,  9,  15, 2,  7,  2},
};


int UniversalMatrixSetsComputer::run() const
{
    int f1[3];
    int fail_count = 0;
    for (f1[0] = 0; f1[0] < DIM; f1[0]++) {
        for (f1[1] = 0; f1[1] < DIM; f1[1]++) {
            for (f1[2] = 0; f1[2] < DIM; f1[2]++) { // для каждой линейной функции f1

                // берем 3 точки ki = (x1, x2)
                int result_points[3];
                if (test_function(f1, result_points) == 1) {
                    printf("f1(%d*x1 + %d*x2 + %d) => [ ", f1[0], f1[1], f1[2]);
                    for (int i = 0; i < 3; i++) {
                        int point = result_points[i];
                        int x1 = X1(point), x2 = X2(point);
                        int y = m[x1][x2];
                        int y1 = (f1[0] * x1 + f1[1] * x2 + f1[2]) % DIM;
                        if (y == y1) {
                            printf("%d, ", point);
                        } else {
                            printf("main: ERROR\n\n\n");
                            return -1;
                        }
                    }
                    printf("]\n");
                } else {
                    printf("f1(a[0]: %d, a[1]: %d, a[2]: %d) => FAIL\n", f1[0], f1[1], f1[2]);
                    fail_count++;
                }

            }
        }
    }
    printf("fail count: %d\n", fail_count);
    return 0;
}

int UniversalMatrixSetsComputer::test_function(const int f1[3], int k_out[3]) const
{
    int k[3];
    for (k[0] = 0; k[0] < DIM2; k[0]++) {
        for (k[1] = 0; k[1] < DIM2; k[1]++) {
            for(k[2] = 0; k[2] < DIM2; k[2]++) {

                // составляем матрицу A[i,j] == 1 iff fj(ki) != f1(ki) = fu(ki)
                // i = 0,1,2 для k[i]
                // j = пробегаемся по всем функциям не равным f1
                int fits = check_f1_fits_points(f1, k, 3);

                if (fits == 1) {
                    k_out[0] = k[0]; k_out[1] = k[1]; k_out[2] = k[2];
                    return 1;
                }
            }
        }
    }

    return 0;
}

int UniversalMatrixSetsComputer::check_f1_fits_points(const int *f1, int k[], int pointsCount) const
{
    int A[DIM3] = {0};
    int s = 0;
    for (int i=0; i<pointsCount; i++) {
        int x1 = X1(k[i]), x2 = X2(k[i]);
        int y1 = (f1[0] * x1 + f1[1] * x2 + f1[2]) % DIM;
        int y = m[x1][x2];
        if (y1 == y) {
            s++;
            fulfill_row_with_f1_x1x2(A, f1, y, x1, x2);
        }
    }

    if (s > 0) {
        int fits = 1;
        for (int j = 0; j < DIM3; j++) {
            int y = A[j];
            if (y == 0) {
                fits = 0;
                break;
            }
        }
        return fits;
    }
    return -1;
}

void UniversalMatrixSetsComputer::fulfill_row_with_f1_x1x2(int A[DIM3], const int *f1, int y, int x1, int x2) const
{
    int f2[3];
    for (f2[0] = 0; f2[0] < DIM; f2[0] ++) {
        for (f2[1] = 0; f2[1] < DIM; f2[1]++) {
            for (f2[2] = 0; f2[2] < DIM; f2[2]++) {
                int y2 = (f2[0] * x1 + f2[1] * x2 + f2[2]) % DIM;
                int j = (f2[0] * DIM + f2[1]) * DIM + f2[2];
                if (y2 != y) {
                    A[j] = 1;
                } else {
                    if (f1[0] == f2[0] && f1[1] == f2[1] && f1[2] == f2[2]) {
                        A[j] = 1;
                    }
                }
            }
        }
    }
}

