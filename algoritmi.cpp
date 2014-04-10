#include "algoritmi.h"
#include <iostream>


int fibonacci1(int n)
{
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  return fibonacci1(n-1)+fibonacci1(n-2);
}


int fibonacci2( int n)
{
  if(n == 1)
    return n;
  int x = 0;
  int y = 1;
  int z = 0;
  for (int i = 0; i < n; i++) {
    z = x+y;
    x = y;
    y = z;
  }
  return z;
}


int moltiplicazione( int x, int y)
{
  if( y == 0)
    return 0;
  int z = moltiplicazione(x,y/2);
  if((x%2) == 0)
    return z*2;
  else
    return z*z+x;
}



void Divisione::fun(int x, int y)
  {
    if(x == 0)
    {
    this->q = this->r = 0;
    return;
    }

    fun(x/2,y);
    this->q = this->q*2;
    this->r = this->r*2;
    if(x%2 != 0)
    {
      this->r = this->r + 1;
    }
    if(this->r >= y)
    {
      this->q = this->q + 1;
      this->r = this->r - y;
    }
    return;
  }



void Euclid::MCD(int a, int b)
{
  this->a = a;
  this->b = b;
  if(this->b == 0)
  {
    return;
  }
  MCD(this->b, this->a%this->b);
}



void EE::Extended_Euclid(int a, int b) {
  int x_temp, y_temp = 0;
  if(b == 0) {
    this->x = 1;
    this->y = 0;
    this->d = a;
  }
  Extended_Euclid(b,a%b);
  x_temp = this->x;
  y_temp = this->y;
  this->x = y_temp;
  this->y = (x_temp - ((a/b)*y_temp));
  return;
}


void insertion_sort( int A[], int n) {
  int key,j;
  for (int i = 1; i < n; i++)
  {
    key = A[i];
    j = i-1;
    while (j >= 0 && A[j] > key)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
}


void merge(int a1[], int n1, int a2[], int n2)
{
  int i1, i2 , l ;
  int *b ;
  b = new int[n1+n2] ;

  
  for(i1 = 0, i2 = 0, l = 0; 
      i1 < n1 && i2 < n2 ; 
      l++) {
    if (a1[i1] < a2[i2])
      b[l] = a1[i1++] ;
    else
      b[l] = a2[i2++] ;
  }
  for ( ; i1 < n1 ; i1++, l++ ) 
    b[l] = a1[i1] ;
  for ( ; i2 < n2 ; i2++, l++ ) 
    b[l] = a2[i2] ;
  for (i1 = 0 ; i1 < l ; i1++)
    a1[i1] = b[i1] ;

  delete[] b ;
}



void merge_sort(int a[], int n) {
  if (n > 1) {
  int center = n / 2 ;
  merge_sort(a, center) ;
  merge_sort(&a[center], n - center) ;
  merge(a, center, &a[center], n - center);
  }
}
