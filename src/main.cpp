#include <iostream>
#include "MatrixFuncsLib.h"

using namespace MatrixFuncs;

int main() {
        Mat A = {{1,2},{3,4},{2.6}};
        Mat B = {{3,4,5},{7,8,9}};
        Mat C = {{45},{12},{3}};

        try {
                /*      std::cout << "Enter first matrix A" << '\n';
                      Mat A = EnterMat();
                      std::cout << "Enter second matrix B" << '\n';
                      Mat B = EnterMat();
                      std::cout << "Matrix A is " << '\n';
                      displayMat(A);
                      std::cout << "Matrix B is" << '\n';
                      displayMat(B); */
                Mat D = A*B*C;
                Mat C_transpose = transpose(A);
                if (D.empty())
                {
                        std::cout<<"Invalid Multiplication"<<"\n";
                        return -1;
                }
                else{
                        std::cout << "The product of A and B is " << '\n';
                        displayMat(D);
                        std::cout << "The transpose of A is " << '\n';
                        displayMat(C_transpose);
                }
        }catch (char const* e) {
                cout << e << '\n';
        }
        return 0;
}
