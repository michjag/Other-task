/*
Zadanie 3
Napisz program symulujący grę w kości. W grze bierze udział dwóch graczy o nazwach: pierwszy, drugi.
Każdemu graczowi przypada 5 tur. Tury graczy odbywają się naprzemiennie tzn. grę zaczyna gracz pierwszy, po jego turze następuje tura gracza drugiego, następna jest tura gracza pierwszego itd. Grę zawsze rozpoczyna gracz pierwszy. Podczas każdej tury gracz zbiera punkty karne według zasad opisanych poniżej.
Suma punktów każdego gracza przed rozpoczęciem gry wynosi zero. Wygrywa gracz, który zbierze mniejszą liczbę punktów.
W każdej turze, gracz wykonuje maksymalnie 10 rzutów dwoma kośćmi jednocześnie. Możliwe wyniki rzutu jedną kością to jedna z następujących cyfr {1, 2, 3, 4, 5, 6}.
Zasady gry:
1. Jeżeli w pierwszym rzucie tury gracz uzyska sumę oczek z obu kości równą 7 lub 11, wygrywa turę przed czasem (rozpoczyna się tura przeciwnika).
2. Jeżeli gracz w pierwszym rzucie tury uzyska sumę oczek z obu kości równą 2 lub 12, przegrywa turę przed czasem (rozpoczyna się tura przeciwnika). Do punktów gracza doliczana jest maksymalna możliwa liczba punktów karnych za turę (tyle, ile by uzyskał w najbardziej pesymistycznym przebiegu swojej tury).
3. Jeżeli gracz uzyska sumę oczek z obu kości równą 5, wygrywa turę przed czasem (rozpoczyna się tura przeciwnika).
4. Jeżeli gracz uzyska sumę oczek z obu kości inną niż opisane powyżej, do jego punktów doliczona zostaje suma oczek uzyskanych w danym rzucie podzielona przez numer rzutu w danej turze.
Po zakończeniu wszystkich tur obydwu graczy na standardowe wyjście zostaje wypisany komunikat o sumie punktów zdobytych przez każdego z graczy oraz informacja o zwycięzcy.
*/

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

float tura(); //FLOAT
int losowanie1();
int losowanie2();

int main ()
{
    
string pierwszy = "Pierwszy";
string drugi = "Drugi";

int punkty_pierwszy = 0;
int punkty_drugi = 0;


for (int i = 1; i < 6; i++) // i < 6 ma być !!!!!!!!!!!!!!!!!!!!!!!
{
 cout<<"TURA: "<<i<<endl;   
 cout<<"Gracz "<<pierwszy<< '\n';
 
 punkty_pierwszy += tura();
 
 getchar();
 // cin.get();
 
  
  
 cout<<"Gracz "<<drugi<< '\n';
 
 punkty_drugi += tura();
 
 getchar();
 //cin.get();
    
 cout<<endl;
}

cout<<"Suma punktów pierwszy: "<<punkty_pierwszy<<endl;
cout<<"Suma punktów drugi: "<<punkty_drugi<<endl;

if (punkty_pierwszy > punkty_drugi)
{
    cout<<"Wygrywa gracz: "<<drugi; 
}

if (punkty_pierwszy < punkty_drugi)
{
    cout<<"Wygrywa gracz: "<<pierwszy;
}

    return 0;
}

float tura() //FLOAT
{
 int wynik1, wynik2;
 float suma; //FLOAT
 float  sumapkt = 0; //FLOAT
 float NOWAsumapkt = 0.0; //FLOAT
 
 for (int i = 1; i < 11; i++) // i < 11 ma być !!!!!!!!!!!!!!!!!!!!!
 {
 
   //  losowanie();
     
     
     
    cout<<"Rzuć dwoma kostkami (Enter) ";
    //cin >>wynik1>>wynik2;
    // losowanie()>>wynik1;
    // losowanie()>>wynik2;
    wynik1 = losowanie1();
    wynik2 = losowanie2();
    getchar();
    cout<<wynik1<<" "<<wynik2<<endl;
    
    
    suma = wynik1 + wynik2;
    
    sumapkt += suma;
    
    if ((i == 1) && (sumapkt == 7 || sumapkt == 11))
    {
        //break;
        return sumapkt;
    }
    
    if ((i == 1) && (sumapkt == 2 || sumapkt == 12))
    {
        //break;
        return 120;
    }
    
    if (suma == 5)
        return sumapkt;
    

    else
    {
        float suma_else; //FLOAT
        suma_else = suma / i;
        //float NOWAsumapkt; //FLOAT
        NOWAsumapkt += suma_else;
      
//         cout<<"Suma_else "<<suma_else<<endl;
//         cout<<"Suma "<<suma<<endl;
//         cout<<"NOWAsumapkt "<<NOWAsumapkt<<endl;
        
        sumapkt = NOWAsumapkt;
    }
    
 }
    
    
    
    
    return sumapkt;
}


int losowanie1()
{
    int kostka;
    
    srand(time(NULL));
    kostka=rand()%6+1;
    
   // getchar();
   // cout<<"KOSTKA: "<<kostka;
    

return kostka;    
}
    
int losowanie2()
{
    int kostka;
    
    srand(time(NULL) + 4);
    kostka=rand()%6+1;
    
   // getchar();
   // cout<<"KOSTKA: "<<kostka;
    

return kostka;    
}

