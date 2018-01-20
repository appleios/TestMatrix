//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#include <stdlib.h>
#include "MatrixGenerator.h"


void MatrixGenerator::generateSeed(Matrix seed, const int K) const
{
    for (int i = 0; i< K; i++) {
        for (int j = 0; j < K; j++) {
            seed[i][j] = arc4random_uniform(DIM);
        }
    }
}
