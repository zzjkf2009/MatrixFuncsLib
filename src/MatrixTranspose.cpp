/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-10-10T17:11:38-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: MatrixTranspose.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-10-11T14:52:07-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */


#include <iostream>
#include "MatrixFuncsLib.h"

using namespace MatrixFuncs;

int main() {
        try {
                std::cout << "Enter matrix " << '\n';
                Mat A = EnterMat();
                std::cout << "The matrix is " << '\n';
                displayMat(A);
                Mat A_transpose = transpose(A);
                std::cout << "The transpose of this matrix is " << '\n';
                displayMat(A_transpose);
        }catch (char const* e) {
                cout << e << '\n';
        }
        return 0;
}
