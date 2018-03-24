//
// Created by Aziz Latipov on 24.03.2018.
// Copyright (c) 2018 Aziz L. All rights reserved.
//

#pragma once

#include "Algorithm.h"


class AlgorithmTests
{
    const Algorithm &algorithm;
public:
    AlgorithmTests(const Algorithm &algorithm);

    void test() const;

    void testInc1() const;

    void testInc2() const;
};
