//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include "Algorithm.h"


#define PRINT_FAILING


bool Algorithm::shouldApplyAlgorithm(Matrix m, const int K) const
{
    int values[DIM] = {0};
    int i, j, count;
    for (i = 0; i < K; i++) {
        for (j = 0; j < K; j++) {
            if (m[i][j] >= 0) {
                values[m[i][j]] += 1;
            }
        }
    }

    count = 0;
    for (i = 0; i < DIM; i++) {
        count += MIN(values[i], N);
    }
    return count >= N * K;
}

bool Algorithm::shouldFinalizeAlgorithm(Matrix m, const int K) const
{
    int i,j, count = 0;
    for (i = 0; i < K; i++) {
        for (j = 0; j < K; j++) {
            if (m[i][j] + 1 == K) {
                count++;
            }
        }
    }
    return count >= K * K;
}

void Algorithm::incMatrix(Matrix m, const int K) const
{
    int i = 0, j = 0;
    do {
        if (m[i][j] <= 0) {
            m[i][j] = 1;
            return;
        }

        if (m[i][j] + 1 < K) {
            m[i][j] += 1;
            return;
        }

        m[i][j] = 0;
        if (j + 1 == K) {
            i = (i + 1) % K;
            j = 0;
        } else {
            j++;
        }
    } while (1);
}

void Algorithm::incSubMatrix(Matrix m, SubMatrix &subMatrix, const int K) const
{
    int i = subMatrix.rowMin, j = subMatrix.colMin;
    do {
        if (m[i][j] <= 0) {
            m[i][j] = 1;
            return;
        }

        if (m[i][j] + 1 < K) {
            m[i][j] += 1;
            return;
        }

        m[i][j] = 0;
        if (j == subMatrix.colMax) {
            i = subMatrix.rowMin + ((i + 1) % (1 + subMatrix.rowMax - subMatrix.rowMin));
            j = subMatrix.colMin;
        } else {
            j++;
        }
    } while (1);
}

int Algorithm::matrixUniversalityQuality(Matrix m, const int K) const
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

    int failedCount = 0;
    for (int i = 0; i < K3; i++) {
        for (int j = 0; j < K3; j++) {
            if (A[i][j] != 1) {

                f1[0] = i / K / K; f1[1] = (i / K) % K; f1[2] = i % K;
                f2[0] = j / K / K; f2[1] = (j / K) % K; f2[2] = j % K;
#ifdef PRINT_FAILING
                printf("FAILED: for functions [%d,%d] f1:{%d * x1 + %d * x2 + %d}, f2: {%d * x1 + %d * x2 + %d}\n", i, j,
                    f1[0], f1[1], f1[2],
                    f2[0], f2[1], f2[2]);
#endif
                failedCount++;

                break;
            }
        }
    }

    return failedCount;
}