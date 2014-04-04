#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#include "algoritmi.h"
using namespace std;

const char menu[] = "1. Fibonacci ricorsivo\n"
		    "2. Fibonacci polinomiale\n"
	            "3. Moltiplicazione\n"
                    "4. Divisione\n"
		    "5. Euclid (MCD)\n";

int main(int argc, const char *argv[])
{
	int x,y,n,temp = 0;
	Dresult result_D;
	euclid result_MCD;
	while(true)
	{
		cout<<menu<<endl;
		unsigned int scelta;
		cin>>scelta;
		switch(scelta)
		{
			case 1:
				cout<<"inserisci n ";
				cin>>n;
				temp = fibonacci1(n);
				cout<<temp<<endl;
				break;
			case 2:
				cout<<"inserisci n ";
				cin>>n;
				temp = fibonacci2(n);
				cout<<temp<<endl;
				break;
			case 3:
				do {
					cout<<"inserisci x e y ";
					cin>>x>>y;
					if(y<0)
						cerr<<"y deve essere maggiore di 0";
				} while (y<0);
				cout<< moltiplicazione(x,y)<<endl;
				break;
			case 4:
				cout<<"inserisci x e y ";
				cin>>x>>y;
				result_D = result_D.divisione(x,y);
				cout<<"il quoziente e' "<<result_D.q<<" e il resto e' "<<result_D.r<<endl;
				break;
			case 5:
				do {
					cout<<"inserisci a e b ";
					cin>>x>>y;
					if(x<y)
						cout<<"a deve essere maggiore di b"<<endl;
				} while (x<y);
				result_MCD = result_MCD.MCD(x,y);
				cout<<result_MCD.a<<endl;
				break;
			default:
				cerr<<"error\n"<<endl;

		}
	}
	return 0;

}
