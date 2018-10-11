
# Matrix Functions library
## Overview

This is a sample code for creating a high-performance, portable linear algebra library in C++, so far, two main functions are created for this library, which are matrix multiplication and matrix transpose. A shared library (MatrixfuncShareLib.so) will be created, and can be used as an external library for other projects involved matrix calculation. Unit tests are also made using [google test](https://github.com/google/googletest) to test the matrix multiplication and transpose module. Finally, two executables are built by linking to this library and they will provide a console user interface for user to type their own input matrix and do the calculations.

## Prerequisite
Cmake, a cross-platform Makefile generator, which will automatically generates the Makefiles for the project. If don't have it, do:
```
sudo apt-get install cmake
cmake -version
```
## Build and run via command-line
### Build
```
git clone --recursive https://github.com/zzjkf2009/MatrixFuncsLib.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
```
###  Run
Run executable  UI:
```
./src/MatrixMultiplication
./src/MatrixTranspose
```
Run tests:
```
./test/libtest
```

## Library API
A namespace is created for this MatrixfuncShareLib library, and all the methods are listed below, more methods related to the matrix manipulation can be added under this namespace.

|     Return type    |  Member Functions           |
| ------------- |:-------------:|
| void      | CheckMatrix(const Mat& mat) <br/> `Check the matrix to determine if every row has same number of elements` |
| Mat     |  operator*(const Mat& A, const Mat& B) <br/> `Which takes two matrix (col number of first matrix should same as the row number of the second one) and return their product.`      |
| Mat |  transpose(const Mat& A) <br/> `Calculate the transpose of a matrix`> |
| Void | displayMat(const Mat& mat) <br/> `Show the matrix`|
| Void | EnterMat() <br/> `Let user enter a user-defined matrix `|
## Unit tests
The unit tests are performed by using google test ([gtest](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md)).  The test files are instored in the test folder.  There are nine tests in total to test the matrix multiplication and transpose. The result is show as figure below:

![Test reuslt](https://github.com/zzjkf2009/MatrixFuncsLib/blob/master/TestResult.png)



## Contributor:
Zejiang Zeng (zzeng@terpmail.umd.edu)

## Thanks For
Thanks for my instructor [dpiet](https://github.com/dpiet), providing the original framework.
