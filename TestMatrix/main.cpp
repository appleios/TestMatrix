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
#include "UniversalMatrixSetsComputer.h"
#include "UniversalMatrixSetsComputerCustom.h"


int main(int argc, const char *argv[])
{
    const int K = DIM;

    int seed[DIM][DIM] = {
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

    MatrixGenerator matrixGenerator;
    Algorithm algorithm;
    int bestQualityTotal = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(seed), DIM);

//    UniversalMatrixSetsComputer universalMatrixSetsComputer;
//    universalMatrixSetsComputer.run();

//    UniversalMatrixSetsComputerCustom universalMatrixSetsComputerCustom;
//
//    int f1[3] = { 1, 1, 3 };
//    int f2[3] = { 5, 1, 0 };
//    int fits1 = universalMatrixSetsComputerCustom.test_function2(f1);
//    int fits2 = universalMatrixSetsComputerCustom.test_function2(f2);

    int bestQuality = 100;
    int quality;
    int tryCount = 0;
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


