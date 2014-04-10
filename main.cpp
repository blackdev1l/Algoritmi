#include "algoritmi.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const char menu[] =
"1. Fibonacci ricorsivo\n"
"2. Fibonacci polinomiale\n"
"3. Moltiplicazione\n"
"4. Divisione\n"
"5. Euclid (MCD)\n"
"6. Extended Euclid\n"
"7. Instertion Sort\n"
"8. Merge Sort\n";

int main(int argc, const char *argv[])
{
  int *a,x,y,n,temp,num_elem = 0;
  Divisione division_result;
  Euclid MCD_result;
  EE EE_result;
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
        division_result.fun(x,y);
        cout<<"il quoziente e' "<<division_result.q<<" e il resto e' "<<division_result.r<<endl;
        break;
      case 5:
        do {
          cout<<"inserisci a e b ";
          cin>>MCD_result.a>>MCD_result.b;
          if(MCD_result.a < MCD_result.b)
            cout<<"a deve essere maggiore di b"<<endl;
        } while (MCD_result.a<MCD_result.b && MCD_result.a < 0);
        MCD_result.MCD(MCD_result.a, MCD_result.b);
        cout<<MCD_result.a<<endl;
        break;
       case 6:
        do {
          cout<<"inserisci a e b ";
          cin>>x>>y;
          if (x<y) {
            cout<<"a deve essere maggiore di b"<<endl;
          }
        } while (x<y && x < 0);
        EE_result.Extended_Euclid(x,y);
        cout<<"x = "<<EE_result.x<<endl;
        cout<<"y = "<<EE_result.y<<endl;
        cout<<"d = "<<EE_result.d<<endl;
        break;
      case 7:
        do {
          cout<<"Lunghezza array? ";
          cin>>num_elem;
        } while (num_elem<= 0);
        a = new int[num_elem];
        srand(time(0));
        for (int i = 0; i < num_elem; i++) {
          a[i] = rand();
        }
        cout<<"array non ordinato: ";
        for (int i = 0; i < num_elem; i++) {
          cout<<i+1<<" / "<<num_elem<<" "<<a[i]<<endl;
        }
        cout<<"ordino..."<<endl;
        insertion_sort(a,num_elem);
        cout<<"Ordinato!"<<endl;
        for (int i = 0; i < num_elem; i++) {
          cout<<i+1<<" / "<<num_elem<<a[i]<<endl;
        }
        delete [] a;
//        cout<<"premi qualsiasi tasto per continuare."<<endl;
//        cin>>temp;
        break;
      default:
        cerr<<"error\n"<<endl;

    }
  }
  return 0;

}
