/*---------------------------------------------------------
 *                   LIBRERIA ALGORITMI
 *-------------------------------------------------------*/

/*------------------------TO DO LIST-----------------------
 * fixare fibonacci1 (non funziona eppure il codice è giusto)
 * fixare moltiplicazione
 * extended_euclid
 * Funzione modulare esponenziale
 * merge-sort
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
//---------------------------------------------------------





/*---------------------------------------------------------/
 * fibonacci esponenziale
 * Costo O(n^n)
 * ------------------------------------------------------*/

int fibonacci1( int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	return fibonacci1(n-1)+fibonacci1(n-2);
}


/*---------------------------------------------------------
 * Fibonacci polinomiale
 * Costo O(n^2)
 * costo quadratico per via della bit complexity
 * ------------------------------------------------------*/

int fibonacci2( int n)
{
	if(n == 1)
		return n;
	int x = 0;
	int y = 1
;	int z = 0;
	for (int i = 0; i < n; i++) {
		z = x+y;
		x = y;
		y = z;
	}
	return z;
}


/*---------------------------------------------------------
 * Moltiplicazione1
 * Costo O(n^2)
 * Input: 2 numeri interi x e y dove y > 0
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


/*---------------------------------------------------------
 * Euclid
 * Costo O(n^3)
 * input: 2 interi a e b con a >= b >= 0 
 * Output:MCD(a,b)
 * ------------------------------------------------------*/

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


/*---------------------------------------------------------
 * Extended Euclid
 * Costo: O(n^3)
 * input: 2 interi 
 * ------------------------------------------------------*/
