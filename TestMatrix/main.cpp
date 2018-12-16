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
#include "AlgorithmTests.h"


int main(int argc, const char *argv[])
{
    Algorithm algorithm;
    AlgorithmTests algorithmTests(algorithm);
    algorithmTests.test();


    int bestQuality = 100;
    int quality;
    int tryCount = 0;

    int m[DIM][DIM] = {
        { 0, 0, 1, 3, },
        { 0, 3, 1, 2, },
        { 1, 1, 2, 2, },
        { 3, 2, 2, 1, },
    };

    SubMatrix subMatrix = {
        .rowMin = 2, .rowMax = 3, .colMin = 2, .colMax = 3
    };


    const int K4 = K*K*K*K;
    while (!algorithm.shouldFinalizeAlgorithm(m, K) && tryCount <= K4) {
        if (algorithm.shouldApplyAlgorithm(m, K)) {
            tryCount++;
            quality = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(m), DIM);
            if (quality < bestQuality) {
                bestQuality = quality;
                Utils::printMatrixWithQuality(bestQuality, m, K);
                printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
            }
        }
        algorithm.incSubMatrix(m, subMatrix, K);
        //Utils::printMatrixWithQuality(-1, m, K);
    }

    return 0;
}


