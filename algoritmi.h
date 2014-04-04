/*---------------------------------------------------------
 *                   LIBRERIA ALGORITMI                   *
 *-------------------------------------------------------*/

/*------------------------TO DO LIST-----------------------
 * fixare moltiplicazione
 * Funzione modulare esponenziale
 * Hash-table
 * quick-sort
 * ------------------------------------------------------*/

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

//-----------------------DEFINIZIONI-----------------------
int fibonacci1(unsigned int n);
int fibonacci2(unsigned int n);
int moltiplicazione(int x,int y);
struct Dresult; // divisione(int x,unsigned int y);
struct euclid; // euclid(unsigned int a, unsigned int b);
struct EE; // Extebded_Euclid(int a, int b);
void insertion_sort( int A[], int n);
void merge_sort(int A[], int n);
void merge(int a1[], int n1, int a2[], int n2);
//---------------------------------------------------------





/*---------------------------------------------------------/
 * fibonacci esponenziale                                  *
 * Costo O(n^n)                                            *
 * ------------------------------------------------------*/

int fibonacci1( int n)
{
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  return fibonacci1(n-1)+fibonacci1(n-2);
}


/*----------------------------------------------------------
 * Fibonacci polinomiale                                   *
 * Costo O(n^2)                                            *
 * costo quadratico per via della bit complexity           *
 * -------------------------------------------------------*/

int fibonacci2( int n)
{
  if(n == 1)
    return n;
  int x = 0;
  int y = 1
;   int z = 0;
  for (int i = 0; i < n; i++) {
    z = x+y;
    x = y;
    y = z;
  }
  return z;
}


/*----------------------------------------------------------
 * Moltiplicazione1a                                       *
 * Costo O(n^2)                                            *
 * Input: 2 numeri interi x e y dove y > 0a                *
 * Output: il loro prodotto
 * ------------------------------------------------------*/

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


/*---------------------------------------------------------
 * Divisione
 * Costo O(n^2)
 * input 2 numeri interi x e y dove y > 0
 * output: quoziente e resto
 * ------------------------------------------------------*/

 struct Dresult {
  int q;
  int r;
  Dresult divisione(int x, int y)
  {
    Dresult result;
    if(x == 0)
    {
    result.q = result.r = 0;
    return result;
    }

    result = divisione(x/2,y);
    result.q = result.q*2;
    result.r = result.r*2;
    if(x%2 != 0)
    {
      result.r = result.r + 1;
    }
    if(result.r >= y)
    {
      result.q = result.q +1;
      result.r = result.r - y;
    }
    return result;
  }
};


/*----------------------------------------------------------
 * Euclid                                                  *
 * Costo O(n^3)                                            *
 * input: 2 interi a e b con a >= b >= 0                   *
 * Output:MCD(a,b)                                         *
 * -------------------------------------------------------*/

struct euclid
{
  int a;
  int b;

  euclid MCD(int a, int b)
  {
    euclid result;

    if(b == 0)
    {
      return result;
    }
    return MCD(b, a%b);
  }
};


/*----------------------------------------------------------
 * Extended Euclid                                         *
 * Costo: O(n^3)                                           *
 * Input: 2 interi a e b con a >= b >= 0                   *
 * Output: 3 interi x,y,d tali che d = MCD(a,b) e ax+by=d  *
 * -------------------------------------------------------*/

struct EE {
  int x;
  int y;
  int d;

  EE Extended_Euclid(int a, int b) {
    EE result,temp;
    if(b == 0) {
      result.x = 1;
      result.y = 0;
      result.d = a;
    }
    result = Extended_Euclid(b,a%b);
    result = temp;
    result.x = temp.y;
    result.y = (temp.x - ((a/b)*y));
    return result;
  }
};
/*---------------------------------------------------------
 * Insertion Sort
 * Costo: O(n^2)
 * input: Array A di n numeri interi
 * Output: Array A ordinato
 * ------------------------------------------------------*/

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


/*---------------------------------------------------------
 * Merge Sort
 * Costo: O(n log n)
 * Input Array A di n numeri interi
 * Output: Array A ordinato
 * ------------------------------------------------------*/

void merge_sort(int a[], int n)
{
  if (n > 1) {
  int center = n / 2 ;
  merge_sort(a, center) ;
  merge_sort(&a[center], n - center) ;
  merge(a, center, &a[center], n - center);
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

