#include "icludy.h"

using namespace std;
 
int modulo_rand(int s)
{
    int liczba = ((int)rand() % s);
    return liczba;
}
int sys2dec (string binarna, int s)
{
    int systemowa = strtol(binarna.c_str(), NULL, s);
    return systemowa;
}
int main()
{
    int bit, sys1, sys2, syst1,proby,czas_ukonczenia,minut,sekund;
    string odpowiedz;
    cout<<"Podaj ilosc bitow: ";
    cin>>bit;
    cout<<"Podaj system zapisania: ";
    cin>>sys1;
    cout<<"Podaj system zgadywania: ";
    cin>>sys2;
    srand(time(NULL));
    string INt = "";
    for (int i = 0; i < bit; i++) {
        int x = modulo_rand(sys1);
        INt += to_string(x);
    }
    syst1=sys2dec(INt,sys1);
    char systemowa[255];
    itoa(syst1, systemowa, sys2);
    //cout<<INt<<endl<<systemowa<<endl<<sys1<<endl;
    cout<<INt<<" w systemie ("<<sys1<<") to w systemie ("<<sys2<<"): ";
    clock_t czas = clock();
    do
    {
        cin>>odpowiedz;
        proby++;
    } while (odpowiedz!=systemowa);
    czas_ukonczenia=(clock()-czas)/CLOCKS_PER_SEC;
    minut=floor(czas_ukonczenia/60);
    sekund=czas_ukonczenia%60;
    if (minut==0&&sekund>1)
    {
        cout<<"Gratulacje uzytkowniku wygrales za "<<proby<<" razem, w czasie: "<<sekund<<" sekund!";
    }
    else if (minut==1)
    {
        cout<<"Gratulacje uzytkowniku wygrales za "<<proby<<" razem, w czasie: 1 minuty i "<<sekund<<" sekund!";
    }
    else if (minut==0&&sekund<=1)
    {
        cout<<"I mamy nowy rekord 102 metry!!! 102 metry!!!";
    }
    else{
        cout<<"Gratulacje uzytkowniku wygrales za "<<proby<<" razem, w czasie:"<<minut<<" minut i "<<sekund<<" sekund!";
    }
    cout<<endl;
    system("pause");
    return 0;
}