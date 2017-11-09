//
//  main.cpp
//  TestMatrix
//
//  Created by Aziz Latipov on 09.11.17.
//  Copyright © 2017 Aziz L. All rights reserved.
//

#include <iostream>

int m8[8][8] = {
    { 0, 0,  1,  1,  2,  2,  3,  3},
    { 0, 5,  1,  6,  2,  7,  3,  4},
    { 1, 2,  2,  1,  2,  3,  6,  4},
    { 2, 3,  3,  1,  3,  4, -1, -1},
    { 3, 6,  0,  3,  5,  0, -1, -1},
    { 1, 4,  4,  3, -1,  2,  7,  1},
    { 4, 7, -1,  7,  3, -1,  0,  0},
    {-1, 2,  4, -1,  5,  1,  0, -1},
};


int m9[9][9] = {
    { 0,  0,  0,  1,  1,  2,  2,  2,  1},
    { 8,  1,  7,  4,  2,  5,  6,  0,  6},
    { 8,  0, -1,  7, -1,  7, -1,  7,  3},
    { 0,  3,  4,  1, -1,  8, -1,  8,  5},
    { 8,  8,  4, -1,  7,  7,  4,  3,  1},
    { 2,  4,  1, -1, -1, -1, -1,  6,  3},
    {-1,  8,  6,  5, -1,  7,  5,  1,  0},
    { 0,  7,  6, -1,  7,  8, -1,  6,  6},
    { 0, -1, -1, -1,  8, -1, -1, -1, -1},
};


int main(int argc, const char * argv[])
{
#define K 9
#define m m9
    for (int a11 = 0; a11 < K; a11 ++) {
        for (int a12 = 0; a12 < K; a12++) {
            for (int a13 = 0; a13 < K; a13++) {
                int s = 0; // количество точек где f1 единственная функция такая что f1(x1,x2) == fu(x1, x2)
                for (int k1 = 0; k1 < K; k1++) {
                    for (int k2 = 0; k2 < K; k2++) {
                        int f1 = (a11 * k1 + a12 * k2 + a13) % K;
                        int fu = m[k1][k2];
                        if (f1 == fu) {
                            int f2_different_count = 0;
                            int f2_count = 0;
                            for (int a21 = a11+1; a21 < K; a21 ++) {
                                for (int a22 = a12+1; a22 < K; a22++) {
                                    for (int a23 = a13+1; a23 < K; a23++) {
                                        int f2 = (a21 * k1 + a22 * k2 + a23) % K;
                                        if (f2 != fu) {
                                            f2_different_count++;
                                        }
                                        f2_count++;
                                    }
                                }
                            }
                            if (f2_count == f2_different_count) {
                                s++;
                            }
                        }
                    }
                }
                std::cout << s << std::endl;
            }
        }
    }
    return 0;
}
