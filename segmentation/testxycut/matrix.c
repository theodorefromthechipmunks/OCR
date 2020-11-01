#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

Matrix newMatrix(int H, int W){
/*
description :

initialization of a new matrix

parameters :

int H : the height of the matrix
int W : the width of the matrix

dates/authors :
12/10
geoffroy du mesnil du buisson

*/
  Matrix M;

  M.height = H;
  M.width = W;

  M.matrix = malloc(H*W*sizeof(double));

  for (int i = 0 ; i < H*W ; i++){

      M.matrix[i] = 0.0;
  }
  return M;
}

Matrix andLogicMartix(Matrix m1,Matrix m2){
  /*
  description :

  multiplie each value of a matrix full of 1 and 0 by an
  other matrix full of 1 and 0 for the same index and
  return the result in a new matrix of the same size

  parameters :

  Matrix m1 : the first matrix full of 1 and 0
  Matrix m2 : the second full of 1 and 0

  dates/authors :
  14/10
  geoffroy du mesnil du buisson

  */
  Matrix m3;

  m3.height = m1.height;
  m3.width = m1.width;
  m3.matrix = malloc(m3.height*m3.width*sizeof(double));

  for (int i = 0 ; i < m1.height ; i++){
      for (int j = 0 ; j < m1.width ; j++){

              m3.matrix[i*m3.width+j]=m1.matrix[i*m1.width+j]*m2.matrix[i*m2.width+j];
      }
  }
  return m3;
}

Matrix copyMatrix(Matrix M){
  /*
  description :

  create a copy of a matrix to not madifiying directly a matrix

  parameters :

  Matrix M : the matrix to copy

  dates/authors :
  14/10
  geoffroy du mesnil du buisson

  */
    Matrix mcopy;

    mcopy.height = M.height;
    mcopy.width = M.width;
    mcopy.matrix = malloc(mcopy.height*mcopy.width*sizeof(double));

    for (int i = 0 ; i < mcopy.height*mcopy.width ; i++){

      mcopy.matrix[i] = M.matrix[i];
    }
    return mcopy;
}


void freeMatrix(Matrix M){
  /*
  description :
  unallocate the memory that have been allocate for a matrix

  parameters :
  Matrix M : the matrix that we want to supress because we
  dont need it anymore

  dates/authors :
  12/10
  geoffroy du mesnil du buisson

  */
  free(M.matrix);
  M.width = 0;
  M.height = 0;
}


// Return the cuted matrix (part of the original matrix)
Matrix cutMatrix(Matrix M, int x, int y, int height, int width)    // Return the cuted matrix (part of the original matrix)
{
  /*
  description :
  //TODO

  parameters :
  //TODO

  dates/authors :
  23/10
  marine thunet

  */
        Matrix cut;
        cut.height = height;
        cut.width = width;
        cut.matrix = malloc(height*width*sizeof(double));

        for (int i = x ; i < x+cut.height ; i++)
    {
        for (int j = y ; j < y+cut.width ; j++) cut.matrix[(i-x)*cut.width+(j-y)] = M.matrix[i*M.width+j];

    }

        return cut;
}