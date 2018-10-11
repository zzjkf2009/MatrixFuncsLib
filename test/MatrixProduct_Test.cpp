/**
 * @Author: Zejiang Zeng <yzy>
 * @Date:   2018-10-10T18:18:12-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: MatrixProduct_Test.cpp
 * @Last modified by:   yzy
 * @Last modified time: 2018-10-11T14:52:48-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */



#include <gtest/gtest.h>
#include "MatrixFuncsLib.h"

using namespace MatrixFuncs;

/**
 * @brif This test will verify if any of the input matrix is not acutally a mtrix that each
 * row has same number of elements
 */
TEST(ProductTEST,invalidMatrix) {
        // Create a mtrix that the second ros missing one element
        Mat invalid_mat_A = {{1,2,3},
                             {3,2}};
        Mat valid_mat_B = {{1,2,3},{3,2,1}};
        // Since the row size doesn't match, it throw a char exception
        EXPECT_THROW(invalid_mat_A*valid_mat_B,const char*);
        EXPECT_THROW(valid_mat_B*invalid_mat_A,const char*);
}

/**
 * @brif This test will verify if any of the input matrix is empty, it will throw an exception
 */
TEST(ProductTEST,emptyMatrix) {
        Mat empty_A;
        Mat valid_mat_B = {{1,2,3},{3,2,1}};
        EXPECT_NO_THROW(CheckMatrix(valid_mat_B));
        EXPECT_THROW(empty_A*valid_mat_B,const char*);
}

/**
 * @brif This test will verify the column of first matrix equals the rows of the second
 * matrix, if not, it will throw an exception
 */
TEST(ProductTEST,sizeMatch) {
        Mat A = {{1.2,3.5,1.3},{4.5,7.0,1.7}};
        Mat B = {{0.34,1.21},{4.98,1.2}};
        Mat C;
        EXPECT_NO_THROW(CheckMatrix(A));
        EXPECT_NO_THROW(CheckMatrix(B));
        EXPECT_THROW(C = A*B,const char*);
}
/**
 * @brif This test will verify if the product get the correct reuslt for two matrix
 */
TEST(ProductTEST,TwoMatProductReusltTest) {
        Mat A = {{1,2,3},{4,5,6}};
        Mat B = {{3,2},{10,5},{6,6}};
        Mat C;
        EXPECT_NO_THROW(CheckMatrix(A));
        EXPECT_NO_THROW(CheckMatrix(B));
        EXPECT_NO_THROW({C =A*B; });
        EXPECT_DOUBLE_EQ (41,C[0][0]);
        EXPECT_DOUBLE_EQ (30,C[0][1]);
        EXPECT_DOUBLE_EQ (98,C[1][0]);
        EXPECT_DOUBLE_EQ (69,C[1][1]);
}

/**
 * @brif This test will verify if the product get the correct reuslt for three matrix
 */
TEST(ProductTEST,ThreeMatProductReusltTest) {
        Mat A = {{1,2,3},{4,5,6}};
        Mat B = {{3,2},{10,5},{6,6}};
        Mat C = {{3},{1}};
        Mat D;
        EXPECT_NO_THROW(CheckMatrix(A));
        EXPECT_NO_THROW(CheckMatrix(B));
        EXPECT_NO_THROW(CheckMatrix(C));
        EXPECT_NO_THROW({ D = A*B*C; });
        EXPECT_DOUBLE_EQ (153,D[0][0]);
        EXPECT_DOUBLE_EQ (363,D[1][0]);

}
