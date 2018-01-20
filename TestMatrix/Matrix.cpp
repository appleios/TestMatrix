//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#include <cstdio>
#include "Matrix.h"


void Utils::copyMatrix(Matrix src, Matrix dst, const int K)
{
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

void Utils::printMatrixWithQuality(int bestQuality, Matrix matrix, const int K)
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
