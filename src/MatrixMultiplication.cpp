/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-10-10T17:10:22-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: MatrixMultiplication.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-10-11T14:51:31-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */
#include <iostream>
#include "MatrixFuncsLib.h"

using namespace MatrixFuncs;

int main() {
        try {
                std::cout << "Enter first matrix A" << '\n';
                Mat A = EnterMat();
                std::cout << "Enter second matrix B" << '\n';
                Mat B = EnterMat();
                std::cout << "Matrix A is " << '\n';
                displayMat(A);
                std::cout << "Matrix B is" << '\n';
                displayMat(B);
                Mat C = A*B;
                if (C.empty())
                {
                        std::cout<<"Invalid Multiplication"<<"\n";
                        return -1;
                }
                else{
                        std::cout << "The product of A and B is " << '\n';
                        displayMat(C);
                }
        }catch (char const* e) {
                cout << e << '\n';
        }
        return 0;
}
