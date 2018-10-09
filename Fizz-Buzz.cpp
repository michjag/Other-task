/*
Zadanie 1
Napisz program, który wypisuje liczby od 1 do 100. Ale dla wielokrotności trójki wyświetl "Fizz" zamiast
liczby oraz dla wielokrotności piątki wyświetl "Buzz". Dla liczb będących wielokrotnościami trójki oraz piątki
wyświetl "FizzBuzz".
*/

#include <iostream>

int main()
{
    
 for (int i = 1; i <= 100; i++)
 {
    if (i % 3 == 0 || i % 5 == 0)
    {
        if (i % 3 == 0 && i % 5 != 0)
            std::cout<<"Fizz\n";
        if (i % 5 == 0 && i % 3 != 0)
            std::cout<<"Buzz\n";
        if (i % 3 == 0 && i % 5 == 0)
            std::cout<<"FizzBuzz\n";
    }
     
    else 
        std::cout<<i<<'\n';   
 }
 
    return 0;
}
