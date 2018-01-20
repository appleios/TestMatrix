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


void generateSeed(Matrix seed, const int K);

int gradientSearchWithInitialMatrix(Matrix initialMatrix, const int K);
int matrixUniversalityQuality(Matrix m, const int K);

void copyMatrix(Matrix src, Matrix dst, const int K);
void printMatrixWithQuality(int bestQuality, Matrix matrix, const int K);


int main(int argc, const char *argv[])
{
    const int K = DIM;

    int seed[DIM][DIM] = {
        { 5, 4, 0, 4, 1, 4, },
        { 0, 2, 5, 5, 0, 0, },
        { 1, 5, 4, 3, 5, 0, },
        { 0, 5, 5, 1, 3, 2, },
        { 4, 1, 2, 1, 3, 1, },
        { 2, 4, 5, 2, 4, 5, },
    };

    int bestQualityTotal = matrixUniversalityQuality(reinterpret_cast<Matrix>(seed), DIM);


    int bestQuality = 1;
    int quality;
    int tryCount = 0;
    do {
        tryCount++;

//        generateSeed(seed, K);
        quality = gradientSearchWithInitialMatrix(seed, K);

        if (quality < bestQuality) {
            bestQuality = quality;
            printMatrixWithQuality(bestQuality, seed, K);
        }

        printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
    } while(bestQuality > 0);

    return 0;
}

void printMatrixWithQuality(int bestQuality, Matrix matrix, const int K)
{
    printf("bestQuality: %d\n", bestQuality);
    printf("seed: {\n");
    for (int i = 0; i< K; i++) {
        printf("\t{ ");
        for (int j = 0; j < K; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("},\n");
    }
    printf("}\n\n");
}

void generateSeed(Matrix seed, const int K)
{
    for (int i = 0; i< K; i++) {
        for (int j = 0; j < K; j++) {
            seed[i][j] = arc4random_uniform(DIM);
        }
    }
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

    printMatrixWithQuality(bestQuality, currentMatrix, K);
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
                printf("FAILED: for functions [%d,%d] f1:{%d * x1 + %d * x2 + %d}, f2: {%d * x1 + %d * x2 + %d}\n", i, j,
                f1[0], f1[1], f1[2],
                f2[0], f2[1], f2[2]);

                failedCount++;

                break;
            }
        }
    }

    return failedCount;
}