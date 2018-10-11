/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-10-10T19:21:26-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: MatrixFuncsLib.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-10-11T13:07:34-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */

#include <iostream>
#include <sstream>
#include "MatrixFuncsLib.h"

namespace MatrixFuncs {
/**
 * @brif Check the matrix to determine if every row has same number of elements
 * @param mat [Mat]
 */
void CheckMatrix(const Mat& mat) {
        vec_sz col_size = mat[0].size();
        for(vec_sz i=0; i<mat.size(); ++i) {
                if(col_size == mat[i].size())
                        continue;
                else
                        throw "Matrix row size doesn't match";
        }
        return;
}
/**
 * @brif Which takes two matrix (col number of first matrix should same as the row number of the second one)
 * and return their product. eg. A [n by m] *B (m by p) = C [n by p] ]
 * @param [*] [Mat, Mat]
 */
Mat operator*(const Mat& A, const Mat& B) {
        // Check if the input variable matrix are empty
        Mat C;
        if(A.empty() || B.empty())
                throw "Input matrix is empty";
        CheckMatrix(A);
        CheckMatrix(B);
        // Read the row and col number for each matrix
        vec_sz r1 = A.size(); vec_sz r2 = B.size();
        vec_sz c1 = A[0].size();  vec_sz c2 = B[0].size();
        // Check if the col of A is euqal to row of B
        if (c1 != r2) {
                throw "col of first atrix is not euqal to row of second matrix ";
        }
        else {
                Vec row(c2,0);
                for(vec_sz num =0; num<r1; ++num)
                        C.push_back(row);
                for(vec_sz i=0; i< r1; ++i) {
                        for(vec_sz j=0; j< c2; ++j) {
                                for(vec_sz k =0; k< c1; ++k) {
                                        C[i][j] += A[i][k]*B[k][j];
                                }
                        }
                }
        }
        return C;
}
/**
 * @brif Calculate the transpose of a matrix
 * @param  A [Mat]
 * @return   [Mat]
 */
Mat transpose(const Mat& A) {
        Mat trans;
        if(A.empty()) {
                std::cout << "Input matrix is empty" << '\n';
                return trans;
        }
        CheckMatrix(A);
        vec_sz row = A.size();
        vec_sz col = A[0].size();
        Vec row_vector(row,0);
        for(vec_sz num =0; num<col; ++num)
                trans.push_back(row_vector);
        for(vec_sz i=0; i<row; ++i) {
                for(vec_sz j=0; j<col; ++j)
                        trans[j][i] = A[i][j];
        }
        return trans;
}
/**
 * @brif Dispaly the matrix
 * @param mat [Mat]
 */
void displayMat(const Mat& mat) {
        CheckMatrix(mat);
        for(vec_sz i=0; i< mat.size(); ++i) {
                for(vec_sz j=0; j<mat[i].size(); ++j)
                        cout<<mat[i][j]<<" ";
                cout<<"\n";
        }
}
/**
 * @brif Let user enter a user-defined matrix
 * @return [Mat]
 */
Mat EnterMat() {
        int r, c;
        std::cout<<"Please enter the row and column numbers for this matrix: "<<"\n";
        cin>> r >> c;
        if(r <= 0 || c <= 0)
                throw "Matrix size should be numbers and not smaller or euqal to Zero";
        std::cin.ignore();
        Mat Output_mat;
        double element;
        for(int i = 0; i< r; ++i) {
                Vec row_numbers;
                std::string row_numbers_string;
                std::cout<<"Enter numbers for a new row, which has "<< c<< " elements :";
                std::getline(std::cin,row_numbers_string);
                std::istringstream stream(row_numbers_string);
                while(stream >> element) {
                        row_numbers.push_back(element);
                }
                if(row_numbers.size() == c)
                        Output_mat.push_back(row_numbers);
                else {
                        std::cout << "Wrong number of elements for this row, please re-enter those elements again" << '\n';
                        r++;
                }

        }
        return Output_mat;
}

}
