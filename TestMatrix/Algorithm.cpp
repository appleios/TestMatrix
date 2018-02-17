//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include "Algorithm.h"


int Algorithm::gradientSearchWithInitialMatrix(Matrix initialMatrix, const int K) const
{
    const int K1 = K - 1;

    int currentMatrix[DIM][DIM];
    Utils::copyMatrix(initialMatrix, currentMatrix, K);

    int bestQuality = matrixUniversalityQuality(reinterpret_cast<Matrix>(currentMatrix), DIM);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {

            int bestValue = currentMatrix[i][j];
            for (int s = -1; s < K1; s++) {
                currentMatrix[i][j] = s;

                int quality = matrixUniversalityQuality(reinterpret_cast<Matrix>(currentMatrix), DIM);
                if (quality < bestQuality) {
                    bestQuality = quality;
                    bestValue = currentMatrix[i][j];
                }
            }
            currentMatrix[i][j] = bestValue;

        }
    }

//    Utils::printMatrixWithQuality(bestQuality, currentMatrix, K);
    return bestQuality;
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
//                printf("FAILED: for functions [%d,%d] f1:{%d * x1 + %d * x2 + %d}, f2: {%d * x1 + %d * x2 + %d}\n", i, j,
//                    f1[0], f1[1], f1[2],
//                    f2[0], f2[1], f2[2]);

                failedCount++;

                break;
            }
        }
    }

    return failedCount;
}