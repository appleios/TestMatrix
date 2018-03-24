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
#include "MatrixGenerator.h"


int main(int argc, const char *argv[])
{
    const int K = DIM;

    int seed[DIM][DIM] = {
        { 2, 9, 14, -1, 2, 11, 2, 6, 13, 5, 0, 1, -1, 16, 9, 15, 10, 16 },
        { -1, 1, 0, 6, 0, 16, 14, 15, 4, 17, -1, 7, 0, 7, 14, 4, 14, -1 },
        { 9, 2, 14, 6, 5, 5, 5, 4, 10, 12, 3, 9, 7, 11, 5, 1, 6, 14 },
        { 16, 10, 10, 10, 1, 2, 7, 9, 6, 1, 17, 6, 15, 11, 2, 8, 10, 12 },
        { 3, 14, 10, 11, 12, 0, 2, 4, 11, 4, 16, 15, 7, 6, 3, 17, 11, 15 },
        { 6, 12, 11, 1, 11, 13, 13, 17, 7, 13, 14, 7, 0, 13, 0, 9, 0, 10 },
        { 9, 9, 14, 11, 17, 9, 5, 11, 11, -1, 17, 16, 4, 15, 15, 1, 2, 1 },
        { 15, 6, 7, 6, 17, 4, -1, 9, 5, 4, 3, 6, 4, 11, 0, 10, 5, 17 },
        { 11, 13, 10, 13, 0, 10, 2, 6, 15, 11, 11, 6, 17, 15, 16, 15, 4, 3 },
        { 4, 8, 14, 7, 2, 0, 0, 15, 5, 15, 11, 7, 9, 3, 6, 11, 4, 9 },
        { -1, 11, 12, 12, 7, 4, 8, 15, 6, 9, -1, 10, 12, 11, 17, 7, 17, 2 },
        { 12, 3, 7, 10, 6, 6, 3, 16, 9, 9, 12, 5, 13, 13, 8, 17, -1, 17 },
        { 11, 0, 4, 17, 14, 12, -1, 16, 17, -1, 12, 2, 1, 13, 12, 13, 11, 1 },
        { 7, 6, 1, 16, -1, -1, 17, 9, 12, 8, 7, 14, 12, 6, 7, 16, 2, 13 },
        { 15, 14, 6, 17, 2, 6, 9, 7, 8, 12, 7, 1, 17, 9, 7, 4, 2, 12 },
        { 14, -1, 15, 17, 1, 15, 2, 13, 4, -1, 2, -1, 2, 12, 2, 1, 13, 2 },
        { 4, 1, 5, 17, 5, 11, 10, 1, 5, 7, 9, 13, 10, 7, 13, 13, -1, -1 },
        { 4, 15, 15, 10, -1, -1, 14, 17, 16, -1, 0, 8, 6, 1, 12, 7, 8, 14 },
    };

    MatrixGenerator matrixGenerator;
    Algorithm algorithm;

    int bestQuality = 100;
    int quality;
    int tryCount = 0;

    bestQuality = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(seed), DIM);

    do {
        tryCount++;

        matrixGenerator.generateSeed(seed, K);
        quality = algorithm.gradientSearchWithInitialMatrix(seed, K);

        if (quality < bestQuality) {
            bestQuality = quality;
            Utils::printMatrixWithQuality(bestQuality, seed, K);
        }

        printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
    } while(bestQuality > 0);

    return 0;
}


