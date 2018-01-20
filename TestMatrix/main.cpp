//
//  main.cpp
//  TestMatrix
//
//  Created by Aziz Latipov on 09.11.17.
//  Copyright © 2017 Aziz L. All rights reserved.
//

#include <iostream>

const int m6[6][6] = {
    {1, 4, 4, 4, 2, 1},
    {2, 0, 3, 3, 1, 5},
    {3, 1, 4, 0, 3, 2},
    {0, 4, 3, 2, 3, 5},
    {5, 1, 5, 1, 0, 4},
    {4, 0, 2, 2, 4, 3},
};

const int m15[15][15] = {
    {8, 11, 2, 9, 0, 3, 9, 2, 2, 10, 9, 10, 7, 7, 12},
    {12, 1, 1, 8, 5, 12, 14, 0, 3, 6, 4, 10, 2, 2, 13},
    {13, 2, 10, 7, 3, 2, 3, 5, 5, 5, 0, 14, 0, 8, 13},
    {12, 5, 0, 13, 5, 12, 2, 11, 12, 6, 2, 9, 1, 5, 3},
    {14, 10, 5, 1, 3, 1, 4, 6, 6, 1, 11, 6, 7, 4, 6},
    {5, 1, 3, 12, 7, 8, 10, 9, 4, 14, 0, 14, 8, 1, 11},
    {3, 8, 6, 1, 9, 9, 2, 5, 7, 0, 6, 4, 6, 5, 8},
    {5, 11, 1, 8, 8, 8, 2, 10, 10, 13, 10, 10, 4, 10, 4},
    {0, 14, 12, 7, 0, 6, 8, 9, 4, 1, 9, 10, 12, 7, 1},
    {12, 12, 4, 13, 6, 4, 14, 0, 0, 9, 5, 2, 11, 10, 4},
    { 0, 10, 3, 4, 9, 10, 3, 3, 4, 7, 4, 13, 9, 8, 6},
    { 10, 5, 10, 6, 3, 1, 11, 9, 1, 3, 10, 7, 12, 7, 2},
    { 1, 14, 4, 12, 4, 14, 14, 7, 2, 4, 6, 13, 9, 0, 13},
    { 7, 3, 3, 3, 9, 13, 4, 12, 8, 13, 0, 3, 12, 4, 2},
    { 6, 6, 2, 10, 10, 6, 1, 9, 5, 10, 5, 3, 0, 0, 3},
};

const int m16[16][16] = {
    {11, 14, 3, 3, 8, 8, 2, 1, 13, 12, 15, 4, 0, 12, 12, 1},
    {2, 7, 15, 12, 0, 3, 12, 11, 3, 12, 12, 9, 8, 7, 11, 3},
    {5, 14, 6, 13, 6, 8, 14, 3, 4, 13, 8, 5, 9, 4, 6, 12},
    {11, 5, 8, 11, 9, 5, 6, 12, 1, 2, 5, 9, 9, 0, 12, 14},
    {14, 2, 12, 4, 10, 10, 8, 15, 8, 0, 4, 1, 4, 10, 13, 15},
    {15, 6, 11, 8, 11, 1, 4, 12, 4, 9, 6, 13, 9, 2, 12, 7},
    {5, 8, 12, 15, 2, 4, 14, 10, 4, 2, 12, 8, 12, 9, 7, 12},
    {15, 2, 4, 10, 4, 9, 7, 8, 2, 13, 5, 12, 15, 1, 3, 4},
    {9, 15, 4, 12, 3, 2, 6, 7, 5, 2, 15, 1, 12, 7, 13, 11},
    {9, 2, 6, 13, 11, 13, 5, 13, 10, 11, 9, 9, 12, 13, 14, 6},
    { 12, 2, 2, 0, 4, 8, 7, 9, 11, 7, 11, 7, 14, 8, 2, 7},
    { 10, 8, 5, 5, 5, 10, 3, 15, 5, 12, 9, 2, 9, 7, 8, 6},
    { 9, 10, 6, 13, 2, 13, 7, 13, 4, 2, 4, 2, 10, 7, 10, 5},
    { 15, 15, 10, 5, 9, 13, 4, 15, 10, 13, 1, 3, 4, 9, 9, 13},
    { 3, 15, 11, 5, 13, 2, 3, 1, 4, 7, 4, 14, 14, 14, 3, 14},
    { 13, 14, 3, 6, 11, 7, 5, 5, 5, 6, 9, 9, 15, 2, 7, 2},
};

const int m18[18][18] = {
    {17, 1, 9, 11, 17, 1, 9, 5, 8, 17, 4, 12, 3, 12, 2, 0, 3, 1},
    {15, 4, 2, 10, 4, 13, 3, 3, 17, 13, 9, 5, 7, 9, 5, 16, 2, 4},
    {15, 9, 7, 5, 8, 12, 15, 11, 6, 0, 9, 7, 17, 4, 9, 1, 12, 14},
    {12, 15, 15, 12, 8, 7, 15, 15, 16, 2, 11, 16, 5, 8, 7, 12, 11, 13},
    {4, 9, 4, 8, 7, 13, 15, 6, 15, 5, 6, 9, 1, 0, 4, 14, 10, 12},
    {3, 8, 10, 17, 8, 3, 15, 13, 10, 2, 6, 3, 15, 10, 10, 1, 1, 17},
    {12, 14, 6, 7, 1, 10, 16, 0, 10, 2, 15, 3, 13, 16, 9, 5, 14, 17},
    {6, 11, 11, 14, 12, 17, 0, 7, 9, 8, 9, 8, 8, 1, 5, 12, 9, 4},
    {4, 5, 5, 14, 6, 0, 15, 1, 14, 6, 4, 10, 4, 8, 2, 15, 5, 14},
    {12, 3, 3, 1, 11, 10, 10, 1, 12, 13, 11, 1, 15, 15, 4, 2, 10, 8},
    { 0, 7, 7, 15, 12, 11, 7, 14, 0, 9, 9, 3, 3, 3, 6, 7, 4, 15},
    { 15, 12, 15, 7, 5, 8, 8, 3, 4, 11, 3, 14, 1, 4, 1, 9, 17, 11},
    { 0, 4, 7, 16, 14, 16, 1, 15, 1, 7, 4, 4, 5, 0, 16, 0, 7, 2},
    { 8, 14, 5, 12, 7, 8, 6, 6, 10, 8, 15, 7, 1, 14, 12, 9, 12, 8},
    { 5, 14, 3, 7, 1, 6, 9, 4, 6, 5, 4, 13, 7, 13, 9, 12, 5, 14},
    { 1, 12, 3, 9, 0, 0, 17, 17, 12, 11, 6, 7, 17, 12, 1, 2, 17, 2},
    { 8, 8, 7, 14, 13, 9, 8, 3, 2, 17, 13, 8, 14, 12, 0, 17, 4, 0},
    { 15, 1, 17, 10, 12, 6, 15, 9, 16, 16, 11, 15, 0, 0, 5, 5, 12, 16},
};


#define DIMENSION 6

static inline int X1(int k) { return k / DIMENSION; }
static inline int X2(int k) { return k % DIMENSION; }


void checkMatrix(const int (*m)[DIMENSION], const int K);

int main(int argc, const char * argv[])
{
    checkMatrix(m6, DIMENSION);
    return 0;
}

void checkMatrix(const int (*m)[DIMENSION], const int K)
{
    const int K2 = K * K;
    const int K3 = K2 * K;
    int f1[3];
    int f2[3];

    // int A[K3][K3];
    int **A = static_cast<int **>(calloc(K3, sizeof(int *)));
    for (int i = 0; i < K3; i++) {
        A[i] = static_cast<int *>(calloc(K3, sizeof(int)));
    }

    for (int i = 0; i < K3; i++) {
        A[i][i] = 1;
    }

    for (f1[0] = 0; f1[0] < K; f1[0]++) {
        for (f1[1] = 0; f1[1] < K; f1[1]++) {
            for (f1[2] = 0; f1[2] < K; f1[2]++) {

                int i = (f1[0] * K + f1[1]) * K + f1[2];

                for (f2[0] = 0; f2[0] < K; f2[0] ++) {
                    for (f2[1] = 0; f2[1] < K; f2[1]++) {
                        for (f2[2] = 0; f2[2] < K; f2[2]++) {

                            int j = (f2[0] * K + f2[1]) * K + f2[2];
                            if (i == j) {
                                continue;
                            }

                            for (int x = 0; x < K2; x++) {
                                int x1 = X1(x), x2 = X2(x);
                                int y = m[x1][x2];
                                int y1 = (f1[0] * x1 + f1[1] * x2 + f1[2]) % K;
                                int y2 = (f2[0] * x1 + f2[1] * x2 + f2[2]) % K;
                                if (y1 == y && y2 != y) {
                                    A[i][j] = 1;
                                }
                            }

                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < K3; i++) {
        for (int j = 0; j < K3; j++) {
            if (A[i][j] != 1) {
                f1[0] = i / K / K; f1[1] = (i / K) % K; f1[2] = i % K;
                f2[0] = j / K / K; f2[1] = (j / K) % K; f2[2] = j % K;
                printf("FAILED: for functions [%d,%d] f1:{%d * x1 + %d * x2 + %d}, f2: {%d * x1 + %d * x2 + %d}\n", i, j,
                f1[0], f1[1], f1[2],
                f2[0], f2[1], f2[2]);
                break;
            }
        }
    }
}