/*
 Zadanie 4
Proszę napisać funkcję sprawdzającą czy posiadacz podanego numeru PESEL jest pełnoletni w podanym
dniu.
Na wejściu funkcji są dwa parametry:
- numer PESEL: parametr tekstowy,
- data do weryfikacji w formacie „RRRRMMDD” (gdzie „RRRR” oznacza rok, „MM” miesiąc, a „DD” dzień): parametr tekstowy.
Funkcja powinna sprawdzać poprawność numeru PESEL zgodnie z zastosowanym zabezpieczeniem – opis podany jest na stronie https://pl.wikipedia.org/wiki/PESEL
Funkcja zwracać będzie następujące wartości:
- ‘0’ - posiadacz numeru PESEL nie będzie pełnoletni w podanym dniu,
- ‘1’ - posiadacz numeru PESEL będzie pełnoletni w podanym dniu,
- ‘2’ - podany numer PESEL jest nieprawidłowy. 
*/
#include <iostream>
#include <string>
#include <sstream>

int sprawdzenie (std::string pes, std::string dat);

int main()
{
    
//std::string P =   "50220494836";
//std::string D = "20580203";

std::string P;
std::string D;

std::cout<<"Podaj pesel: ";
std::cin>>P;
std::cout<<"Podaj datę: (w formacie RRRRMMDD): ";
std::cin>>D;
std::cout<<"\n";
    
if ((sprawdzenie (P, D)) == 0)
    std::cout<<"Posiadacz numeru PESEL nie będzie pełnoletni w podanym dniu\n";

if ((sprawdzenie (P, D)) == 1)
    std::cout<<"Posiadacz numeru PESEL będzie pełnoletni w podanym dniu\n";

if ((sprawdzenie (P, D)) == 2)
    std::cout<<"Podany numer PESEL jest nieprawidłowy\n";

    return 0 ;
}

int sprawdzenie (std::string pes, std::string dat)
{
    
long long pesel, data;        
        
std::istringstream zmien1(pes); 
zmien1 >> pesel; 

std::istringstream zmien2(dat);
zmien2 >> data;
//========
long long liczba = pesel;

long long cyfra1 = (liczba / 10000000000) % 10; 
long long cyfra2 = (liczba / 1000000000) % 10; 
long long cyfra3 = (liczba / 100000000) % 10; 
long long cyfra4 = (liczba / 10000000) % 10; 
long long cyfra5 = (liczba / 1000000) % 10; 
long long cyfra6 = (liczba / 100000) % 10;
long long cyfra7 = (liczba / 10000) % 10; 
long long cyfra8 = (liczba / 1000) % 10; 
long long cyfra9 = (liczba / 100) % 10; 
long long cyfra10 = (liczba / 10 ) % 10;
long long cyfra11 = (liczba / 1) % 10;

long long czy_poprawny;

czy_poprawny = 9 * cyfra1 + 7 * cyfra2 + 3 * cyfra3 + 1 * cyfra4 + 9 * cyfra5 + 7 * cyfra6 + 3 * cyfra7 + 1 * cyfra8 + 9 * cyfra9 + 7 * cyfra10;
  
int liczba_kontrolna = czy_poprawny  % 10;

if (liczba_kontrolna != cyfra11)   
   return 2; 

//========

/*
long cyfra_do_sprawdz1 = cyfra1 * 100000;
long cyfra_do_sprawdz2 = cyfra2 * 10000;
long cyfra_do_sprawdz3 = cyfra3 * 1000;
long cyfra_do_sprawdz4 = cyfra4 * 100;
long cyfra_do_sprawdz5 = cyfra5 * 10;
long cyfra_do_sprawdz6 = cyfra6;

//long cyfra_do_sprawdz_suma = cyfra_do_sprawdz1 + cyfra_do_sprawdz2 + cyfra_do_sprawdz3 + cyfra_do_sprawdz4 + cyfra_do_sprawdz5 + cyfra_do_sprawdz6;
*/

//========
int rok_pesel = 0;
int miesiac = (cyfra3 * 10) + cyfra4;

if (miesiac >= 81 && miesiac <= 92)
    rok_pesel += 1800;

if (miesiac >= 1 && miesiac <= 12)
    rok_pesel += 1900;

if (miesiac >= 21 && miesiac <= 32)
    rok_pesel += 2000;

if (miesiac >= 41 && miesiac <= 52)
    rok_pesel += 2100;

if (miesiac >= 61 && miesiac <= 72)
    rok_pesel += 2200;

rok_pesel += (cyfra1 * 10) + cyfra2;

//====================================================
//pobranie miesiąca z pesel

int miesiac_pesel = (cyfra3 * 10) + cyfra4;

if (miesiac_pesel >= 81 && miesiac_pesel <= 92)
    miesiac_pesel -= 80;

if (miesiac_pesel >= 21 && miesiac_pesel <= 32)
    miesiac_pesel -= 20;

if (miesiac_pesel >= 41 && miesiac_pesel <= 52)
    miesiac_pesel -= 40;

if (miesiac_pesel >= 61 && miesiac_pesel <= 62)
    miesiac_pesel -= 60;

//std::cout<<"MIesiąc sprawdz: "<<miesiac_pesel;

//====================================================
// pobranie dnia z pesel

int dzien = (cyfra5 * 10) + cyfra6;

//std::cout<<"pobranie dnia z pesel: "<<dzien<<std::endl;
//====================================================
// rozłożenie daty na czynniki pierwsze
long long liczba_data = data;

long long cyfra_data1 = (liczba_data / 10000000) % 10; 
long long cyfra_data2 = (liczba_data / 1000000) % 10; 
long long cyfra_data3 = (liczba_data / 100000) % 10; 
long long cyfra_data4 = (liczba_data / 10000) % 10; 
long long cyfra_data5 = (liczba_data / 1000) % 10; 
long long cyfra_data6 = (liczba_data / 100) % 10; 
long long cyfra_data7 = (liczba_data / 10 ) % 10; 
long long cyfra_data8 = (liczba_data / 1) % 10; 
//====================================================
//Rok z daty:
int rok_data = (cyfra_data1 * 1000) + (cyfra_data2 * 100) + (cyfra_data3 * 10) + cyfra_data4;

// std::cout<<"ROk DATA: " <<rok_data<<std::endl;
//====================================================
//miesiąc z daty
int miesiac_data = (cyfra_data5 * 10) + cyfra_data6;

//dzień z daty:
int dzien_data = (cyfra_data7 * 10) + cyfra_data8;
//====================================================

//porównianie peselu i daty:

if (rok_data - rok_pesel >= 19)
    return 1;

if (rok_data - rok_pesel <= 17)
    return 0;

if (rok_data - rok_pesel == 18)
{
    if (miesiac_data > miesiac_pesel)
        return 1;
    
    if (miesiac_data < miesiac_pesel)
        return 0;
    
    if (miesiac_data == miesiac_pesel)
    {
        if (dzien_data >= dzien)
            return 1;
        
        if (dzien_data <= dzien)
            return 0;
            
    }
    
    
}
    
    
    
}
