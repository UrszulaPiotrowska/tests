#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;



void F1(char[],int,int,char);   //Deklaracja funkcji F1
void F2(char[],int,int,char);   //Deklaracja funkcji F2

int main(){                     //Rozpoczęcie programu głównego
    int size;                   //Deklaracja rozmiaru tabeli
    char tab[size];             //Stworzenie tabeli znków o rozmiarze "size"
    
    cout <<"INPUT: ";           //Wyświetlenie napisu "INPUT:"
    cin >>tab;                  //Wpisanie danych do tabeli
    cout<<tab<<" -> ";          //Wyświetlenie danych z tabeli
    int l=1;                    //Deklaracja zmiennej "l"
    int sum=0;                  //Deklaracja zmiennej "sum"
    char k='0';                 //Deklaracja zmiennej "k"
       for (int i=0;i<0;i++){   //Pętla for, która nic nie robi, ale bez niej program nie działa poprawnie powyżej 15znaków ¯\_(ツ)_/¯
            cout<<int(tab[i]);
        }
        
    F1(tab,l,sum,k);            //Wywołanie funkcji F1
    cout<<"OUTPUT: ";           //Wyświetlenie napisu "OUTPUT:"
    
    F2(tab,l,sum,k);            //Wywołanie funkcji F2
    
    return 0;                   //Zwrot 0 dla funkcji main
}
void F1(char tab[],int l,int sum,char k){       //Zadanie dla funkcji F1 oraz zmiennych podanych w nawiasie

    for(int i=0;i<=i*l;i++){                    //Pętla for, która zwraca dane dla spełnionego warunku i<=i*l. 
        if (int(tab[i])!=0){                    //Pętla if, która wyświetla dane z kolejnych pozycji w tabeli tab jeżeli to miejsce jest inne niż 0
                if (k!=','){                    //Pętla if, która sprawdza czy k nie jest równe ,
                cout <<int(tab[i]);             //Jeżeli warunek jest spełniony, wypisuje dane z tab[i]
                k=',';                          //... oraz wpisuje do zmiennej k ,
                }
                else if (k=','){                //Jeżeli poprzedni warunek pętli if nie jest spełniony, sprawdza kolejny warunek czy k równe jest ,
                cout <<k<<int(tab[i]);          //Wyświetla zmienną k oraz kolejną pozycję z tabeli tab[]
                }
            }       
        else                                    //Wracajc do pierwszej pętli if, jeżeli warunek nie jest spełniony tzn tab[i]==0 wykona:
            l=-1;                               //Wpisze do l wartość -1. Jest to po to, aby przerwać pętle for, kiedy skończą się znaki w tabeli tab

    }
    cout<<endl;                                 //Przejście do kolejnej linii
}

void F2(char tab[],int l,int sum,char k){       //Zadanie dla funkcji F2, które jest podobne do funkcji F1, ale z różnicą że wyświetla tylko takie, których modulo równe jest 0, oraz do zmiennej k przypisuje +
    for(int i=0;i<=i*l;i++){
        if (int(tab[i])!=0){
            if (int(tab[i])%2==0){
                if (k!='+'){
                    cout <<int(tab[i]);
                    sum+=tab[i];
                    k='+';
                    }
                else if (k='+'){
                    cout <<k<<int(tab[i]);
                    sum+=tab[i];    
                    }
            }     
        }  
        else{
            l=-1;
        }
    }
    cout<<" = "<<sum<<endl;                       //Na koniec funkcja F2 zwraca naliczoną sume znaków z tablicy ASCII
}

/* Projekt oceniam na 4.5. Wywołanie programu jest dobre, zwraca poprawne wartości. Plus za
stworzenie funkcji i komentarze. Jednak mam kilka uwag do samego kodu.

1. Zmienna size, która ma określać rozmiar tablicy tab nie jest nigdy zdefniowana ani w programie ani 
w trakcie działania programu. To oznacza, że przyjmuje losowe dowolne wartości w zakresie od 0 do
INT_MAX. Jest to błędne postępowanie.

2. Nie rozumiem też tego fragmentu kodu:
 for (int i=0;i<0;i++){   //Pętla for, która nic nie robi, ale bez niej program nie działa poprawnie powyżej 15znaków ¯\_(ツ)_/¯
            cout<<int(tab[i]);
        }

3. Czytelność kodu jest niska, dlatego że trudno zrozumieć co oznacza zmienna l i zmienna k 
oraz jaką pełnią funkcję w programie.

4. Poniższy fragment kodu zawiera błąd, ponieważ jeżeli chcemy sprawdzić czy k jest równe "," 
to należy użyć podwójny znak równości.
else if (k=','){                //Jeżeli poprzedni warunek pętli if nie jest spełniony, sprawdza kolejny warunek czy k równe jest ,
                cout <<k<<int(tab[i]);          //Wyświetla zmienną k oraz kolejną pozycję z tabeli tab[]
                }

5. Prostszym sposobem byłoby użycie zmiast char tab[size], wykorzystanie zmiennej typu string. 
Wówczas łatwo możemy określić rozmiar tabeli poprzez użycie funkcji length() oraz iterować pojedyncze znaki
w pętlach bo string to tablica znaków.
*/