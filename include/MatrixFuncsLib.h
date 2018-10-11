#include <vector>
#include <iostream>

#ifndef MATRIXFUNCSLIB_H
#define  MATRIXFUNCSLIB_H
using namespace std;

namespace MatrixFuncs {

typedef vector<double> Vec;
typedef vector<Vec> Mat;  // Self-define a type for Matrix as vector<vector<double> >
typedef vector<double>::size_type vec_sz;
/**
 * @brif Check the matrix to determin if every row has same number of elements
 * @param mat [Mat]
 */
void CheckMatrix(const Mat& mat);
/**
 * [operator] [Which takes two matrix (col number of first matrix should same as the row number of the second one)
 * and return their product. eg. A [n by m] *B (m by p) = C [n by p] ]
 * @param [*] [Mat, Mat]
 */
Mat operator*(const Mat& A, const Mat& B);
/**
 * @brif Calculate the transpose of a matrix
 * @param  A [Mat]
 * @return   [Mat]
 */
Mat transpose(const Mat& A);
/**
 * @brif Dispaly the matrix
 * @param mat [Mat]
 */
void displayMat(const Mat& mat);
/**
 * @brif Let user enter a user-defined matrix
 * @return [Mat]
 */
Mat EnterMat();

}
#endif
