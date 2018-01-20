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
        { 5, 4, 0, 4, 1, 4, },
        { 0, 2, 5, 5, 0, 0, },
        { 1, 5, 4, 3, 5, 0, },
        { 0, 5, 5, 1, 3, 2, },
        { 4, 1, 2, 1, 3, 1, },
        { 2, 4, 5, 2, 4, 5, },
    };


//    MatrixGenerator matrixGenerator;
//    Algorithm algorithm;
//    int bestQualityTotal = algorithm.matrixUniversalityQuality(reinterpret_cast<Matrix>(seed), DIM);

    UniversalMatrixSetsComputer universalMatrixSetsComputer;
    universalMatrixSetsComputer.run();

//    UniversalMatrixSetsComputerCustom universalMatrixSetsComputerCustom;
//
//    int f1[3] = { 1, 1, 3 };
//    int f2[3] = { 5, 1, 0 };
//    int fits1 = universalMatrixSetsComputerCustom.test_function2(f1);
//    int fits2 = universalMatrixSetsComputerCustom.test_function2(f2);

//    int bestQuality = 1;
//    int quality;
//    int tryCount = 0;
//    do {
//        tryCount++;
//
////        matrixGenerator.generateSeed(seed, K);
//        quality = algorithm.gradientSearchWithInitialMatrix(seed, K);
//
//        if (quality < bestQuality) {
//            bestQuality = quality;
//            Utils::printMatrixWithQuality(bestQuality, seed, K);
//        }
//
//        printf("iteration: %d, quality: %d, bestQuality: %d\n", tryCount, quality, bestQuality);
//    } while(bestQuality > 0);

    return 0;
}


