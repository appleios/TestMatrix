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
        { 3, 1, 0, 2, },
        { 0, 3, 2, 1, },
        { 0, 3, 3, 0, },
        { 1, 2, 3, 0, },
    };

    while (!algorithm.shouldFinalizeAlgorithm(m, K)) {
        if (algorithm.shouldApplyAlgorithm(m, K)) {
            tryCount++;
            quality = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(m), DIM);
            if (quality < bestQuality) {
                bestQuality = quality;
                Utils::printMatrixWithQuality(bestQuality, m, K);
                printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
            }
        }
        algorithm.incMatrix(m, K);
    }

    return 0;
}


