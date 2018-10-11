/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-10-10T16:47:18-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: Transpose_Test.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-10-11T14:53:03-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */

#include <gtest/gtest.h>
#include "MatrixFuncsLib.h"

using namespace MatrixFuncs;
/**
 * @brif This test will verify if the input matrix is not acutally a mtrix that each
 * row has same number of elements, if not, it will throw an exception
 */
TEST(CheckMatrixTEST, invalidMatrix) {
        // Create a mtrix that the second ros missing one element
        Mat invalid_mat = {{1,2,3},
                           {3,2}};
        // Since the row size doesn't match, it throw a char exception
        EXPECT_THROW(CheckMatrix(invalid_mat),const char*);
}

/**
 * @brif This test will verify if the input matrix is empty
 */
TEST(TransposeTEST, emptyMatrix) {
        // Create a mtrix that is empty
        Mat empty_mat;
        // Since input is empty, output should be empty as well
        EXPECT_TRUE(transpose(empty_mat).empty());
}



/**
 * [TEST This test will verify if the transpose is calculated correctly]
 */
TEST(TransposeTEST, valueTest_1){
        // Create a row matrix
        Mat row_mat = {{1,2,3,4,5}};
        // Get its transpose
        Mat vec_mat = transpose(row_mat);
        // Verify if the elements are transposed correctly, which should match the
        // requirement A[i][j] = A^t [j][i]
        EXPECT_DOUBLE_EQ(row_mat[0][0],vec_mat[0][0]);
        EXPECT_DOUBLE_EQ(row_mat[0][1],vec_mat[1][0]);
        EXPECT_DOUBLE_EQ(row_mat[0][2],vec_mat[2][0]);
        EXPECT_DOUBLE_EQ(row_mat[0][3],vec_mat[3][0]);
        EXPECT_DOUBLE_EQ(row_mat[0][4],vec_mat[4][0]);

}
/**
 * [TEST This test will verify if the transpose is calculated correctly]
 */
TEST(TransposeTEST, valueTest_2){
        // Create a 3-by-3 matrix
        Mat origi_mat = {{1.3,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
        Mat trans_mat;
        // Make sure on fatal failure occurs when get its tanspose
        EXPECT_NO_THROW({trans_mat = transpose(origi_mat); });
        // Verify if the elements are transposed correctly, which should match the
        // requirement A[i][j] = A^t [j][i]
        EXPECT_DOUBLE_EQ(origi_mat[0][0],trans_mat[0][0]);
        EXPECT_DOUBLE_EQ(origi_mat[0][1],trans_mat[1][0]);
        EXPECT_DOUBLE_EQ(origi_mat[0][2],trans_mat[2][0]);
        EXPECT_DOUBLE_EQ(origi_mat[1][0],trans_mat[0][1]);
        EXPECT_DOUBLE_EQ(origi_mat[1][1],trans_mat[1][1]);
        EXPECT_DOUBLE_EQ(origi_mat[1][2],trans_mat[2][1]);
        EXPECT_DOUBLE_EQ(origi_mat[2][0],trans_mat[0][2]);
        EXPECT_DOUBLE_EQ(origi_mat[2][1],trans_mat[1][2]);
        EXPECT_DOUBLE_EQ(origi_mat[2][2],trans_mat[2][2]);

}
