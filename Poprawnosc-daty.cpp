/*
 * Zadanie 2
Napisz funkcję sprawdzającą poprawność daty w latach 2001-2099 (daty spoza tego okresu uznaj za niepoprawne).
Wejście – trzy parametry liczbowe (dzień, miesiąc, rok).
Wyjście – parametr logiczny (true – data poprawna, false – data niepoprawna) .
Proszę zaimplementować własny algorytm kontroli – nie wolno korzystać z gotowych rozwiązań, np.
LocalDate, Calendar, itp.
*/

#include <iostream>

bool data (int dzien, int miesiac, int rok);

int main()
{
 int dzien_main, miesiac_main, rok_main;
 
 std::cout<<"Podaj dzień, miesiąc, rok oddzielone spacją. \n";
 std::cin>>dzien_main>>miesiac_main>>rok_main;
 
 //data (dzien_main, miesiac_main, rok_main);

if (data(dzien_main, miesiac_main, rok_main) == true)
     std::cout<<"Data poprawna\n";
if (data(dzien_main, miesiac_main, rok_main) == false)
     std::cout<<"Data niepoprawna\n"; 
 
    return 0;
}

bool data (int dzien, int miesiac, int rok)
{
    if  (rok >= 2001 && rok <= 2099)
    {
        if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12) 
        {
            if (dzien > 0 && dzien <= 31)
        return true;            
        }   
        
        if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) 
        {
             if (dzien > 0 && dzien <= 30)      
        return true;    
        }
        
        if (miesiac == 2)
        {
            if (dzien > 0 && dzien <= 28)      
        return true;    
        }
        
    }
        
        if  ((rok >= 2001 && rok <= 2099) 
            && ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0))
            && (miesiac == 2)
            && (dzien == 29))
        {
            return true;
        }
        
   
    else 
        return false;
 
    
    /*
    if ((rok < 2001 || rok > 2099) || (miesiac < 0 || miesiac > 12) || ( dzien < 0 || dzien > 31))
    {
    return false;
    }
    */

        
}

