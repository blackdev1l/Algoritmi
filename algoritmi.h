/*---------------------------------------------------------
 *                   LIBRERIA ALGORITMI                   *
 *-------------------------------------------------------*/

/*------------------------TO DO LIST-----------------------
 * Fixare MCD 
 * fixare EE
 * testare tutte le funzioni
 * fixare moltiplicazione
 * Funzione modulare esponenziale
 * Hash-table
 * quick-sort
 * ------------------------------------------------------*/

#pragma once
#include <iostream>


/*---------------------------------------------------------/
 * fibonacci esponenziale                                  *
 * Costo O(n^n)                                            *
 * ------------------------------------------------------*/

int fibonacci1(int n);


/*----------------------------------------------------------
 * Fibonacci polinomiale                                   *
 * Costo O(n^2)                                            *
 * costo quadratico per via della bit complexity           *
 * -------------------------------------------------------*/

int fibonacci2(int n);


/*----------------------------------------------------------
 * Moltiplicazione1a                                       *
 * Costo O(n^2)                                            *
 * Input: 2 numeri interi x e y dove y > 0a                *
 * Output: il loro prodotto
 * ------------------------------------------------------*/

int moltiplicazione( int x, int y);


/*---------------------------------------------------------
 * Divisione
 * Costo O(n^2)
 * input 2 numeri interi x e y dove y > 0
 * output: quoziente e resto
 * ------------------------------------------------------*/

class Divisione {

public:
  int q;
  int r;
  void fun(int x, int y);
};


/*----------------------------------------------------------
 * Euclid                                                  *
 * Costo O(n^3)                                            *
 * input: 2 interi a e b con a >= b >= 0                   *
 * Output:MCD(a,b)                                         *
 * -------------------------------------------------------*/

class Euclid {

public:
  int a;
  int b;
  void MCD(int a, int b);
};


/*----------------------------------------------------------
 * Extended Euclid                                         *
 * Costo: O(n^3)                                           *
 * Input: 2 interi a e b con a >= b >= 0                   *
 * Output: 3 interi x,y,d tali che d = MCD(a,b) e ax+by=d  *
 * -------------------------------------------------------*/

class EE {

public:
  int x;
  int y;
  int d;

  void Extended_Euclid(int a, int b);
};


/*---------------------------------------------------------
 * Insertion Sort
 * Costo: O(n^2)
 * input: Array A di n numeri interi
 * Output: Array A ordinato
 * ------------------------------------------------------*/

void insertion_sort( int A[], int n);


/*---------------------------------------------------------
 * Merge Sort
 * Costo: O(n log n)
 * Input Array A di n numeri interi
 * Output: Array A ordinato
 * ------------------------------------------------------*/


void merge(int a1[], int n1, int a2[], int n2);

void merge_sort(int a[], int n);
