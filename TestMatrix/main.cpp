//
//  main.cpp
//  TestMatrix
//
//  Created by Aziz Latipov on 09.11.17.
//  Copyright © 2017 Aziz L. All rights reserved.
//

#include <iostream>
#include "Matrix.h"
#include "Algorithm.h"


const int N = 2+1;

bool shouldApplyAlgorithm(Matrix m, const int K)
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
        count += values[i];
    }
    return count >= N * K;
}

bool shouldFinalizeAlgorithm(Matrix m, const int K)
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

void incMatrix(Matrix m, const int K, int &i, int &j)
{
    if (m[i][j] < 0) {
        m[i][j] = 0;
        return;
    }
    if (m[i][j] + 1 < K) {
        m[i][j] += 1;
        return;
    }

    m[i][j] = -1;
    if (j + 1 == K) {
        i = (i + 1) % K;
        j = 0;
    } else {
        j++;
    }
}

int main(int argc, const char *argv[])
{
    const int K = DIM;

    Algorithm algorithm;
    int bestQuality = 100;
    int quality;
    int tryCount = 0;

    int m[DIM][DIM] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
    };

    int i = 0, j = 0;
    while (!shouldFinalizeAlgorithm(m, K)) {
        if (shouldApplyAlgorithm(m, K)) {
            tryCount++;
            quality = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(m), DIM);
            if (quality < bestQuality) {
                bestQuality = quality;
                Utils::printMatrixWithQuality(bestQuality, m, K);
            }
            printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
        }
        incMatrix(m, K, i, j);
    }

    return 0;
}


