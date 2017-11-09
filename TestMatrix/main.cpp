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
    for (int k1 = 0; k1 < K; k1++) {
        for (int k2 = 0; k2 < K; k2++) {
            int fu = m[k1][k2];
            for (int a11 = 0; a11 < K; a11 ++) {
                for (int a12 = 0; a12 < K; a12++) {
                    for (int a13 = 0; a13 < K; a13++) {
                        int f1 = (a11 * k1 + a12 * k2 + a13) % K;
                        if (f1 == fu) {
                            int n = 0;
                            int k = 0;
                            for (int a21 = a11+1; a21 < K; a21 ++) {
                                for (int a22 = a12+1; a22 < K; a22++) {
                                    for (int a23 = a13+1; a23 < K; a23++) {
                                        int f2 = (a21 * k1 + a22 * k2 + a23) % K;
                                        if (f2 != f1) {
                                            n++;
                                        }
                                        k++;
                                    }
                                }
                            }
                            if (k > 0 && n == 0) {
                                printf("%d: x1 = %d, x2 = %d, fu = %d, f1(a1: %d, a2: %d, a3: %d) = %d, k = %d\n", k1*K+k2, k1, k2, fu, a11, a12, a13, f1, k);

                                int s = 0, sf = 0;
                                for (int a21 = 0; a21 < K; a21 ++) {
                                    for (int a22 = 0; a22 < K; a22++) {
                                        for (int a23 = 0; a23 < K; a23++) {
                                            if (a11 != a21 || a21 != a22 || a13 != a23) {
                                                int f2 = (a21 * k1 + a22 * k2 + a23) % K;
                                                if (f2 == f1) {
                                                    s++;
                                                }
                                                sf++;
                                            }
                                        }
                                    }
                                }
                                printf("s = %d, sf = %d\n", s, sf);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
