//
// Created by Aziz Latipov on 20.01.18.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#pragma once


#include "Matrix.h"


struct Algorithm
{
    int gradientSearchWithInitialMatrix(Matrix initialMatrix, const int K) const;
    int matrixUniversalityQuality(Matrix m, const int K) const;
};
