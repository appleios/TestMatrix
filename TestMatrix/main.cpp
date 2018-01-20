//
//  main.cpp
//  TestMatrix
//
//  Created by Aziz Latipov on 09.11.17.
//  Copyright © 2017 Aziz L. All rights reserved.
//

#include <iostream>


#define DIM 6

typedef int (*Matrix)[DIM];

static inline int X1(int k) { return k / DIM; }
static inline int X2(int k) { return k % DIM; }


int matrixUniversalityQuality(Matrix m, const int K);


void copyMatrix(Matrix src, Matrix dst, const int K);

int gradientSearchWithInitialMatrix(Matrix initialMatrix, const int K);

int main(int argc, const char *argv[])
{
    const int K = DIM;

    int initialMatrix[DIM][DIM] = {
        {1, 4, 4, 4, 2, 1},
        {2, 0, 3, 3, 1, 5},
        {3, 1, 4, 0, 3, 2},
        {0, 4, 3, 2, 3, 5},
        {5, 1, 5, 1, 0, 4},
        {4, 0, 2, 2, 4, 3},
    };

    int bestQuality = gradientSearchWithInitialMatrix(initialMatrix, K);

    return 0;
}

int gradientSearchWithInitialMatrix(Matrix initialMatrix, const int K)
{
    const int K1 = K - 1;

    int currentMatrix[DIM][DIM];
    copyMatrix(initialMatrix, currentMatrix, K);

    int bestQuality = matrixUniversalityQuality(reinterpret_cast<Matrix>(currentMatrix), DIM);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {

            int bestValue = currentMatrix[i][j];
            for (int s = 0; s < K1; s++) {
                currentMatrix[i][j] = (currentMatrix[i][j] + 1) % K;

                int quality = matrixUniversalityQuality(reinterpret_cast<Matrix>(currentMatrix), DIM);
                if (quality < bestQuality) {
                    bestQuality = quality;
                    bestValue = currentMatrix[i][j];
                }
            }
            currentMatrix[i][j] = bestValue;

        }
    }

    return bestQuality;
}

void copyMatrix(Matrix src, Matrix dst, const int K)
{
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

int matrixUniversalityQuality(Matrix m, const int K)
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
//                f1[0], f1[1], f1[2],
//                f2[0], f2[1], f2[2]);

                failedCount++;

                break;
            }
        }
    }

    return failedCount;
}