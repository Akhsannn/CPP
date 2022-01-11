#include <iostream>

using namespace std;
string nama;
int a,b,c,i;
int main()
{
    nama = "Muhammad Akhsan Nurramdhan";
    cout << "=====Menu Looping=====" << endl;
    cout << "1. Looping For" << endl;
    cout << "2. Looping While" << endl;
    cout << "3. Looping Do While" << endl;
    cout << "Pilih Menu : ";
    cin >> a ;
    switch(a){
    case 1 :
        cout << "=====Menu Looping For=====" << endl;
        cout << "1. Looping Nama" << endl;
        cout << "2. Looping Bilangan Ganjil" << endl;
        cout << "3. Looping Bilangan Genap" << endl;
        cout << "Pilih Menu : " ;
        cin >> b ;
        switch(b){
            case 1 :
                for(i = 0 ; i < 5 ; i++){
                cout << nama << endl;
                }
            case 2 :
                for(i=1; i < 10 ; i++){
                cout<< i + 2 << endl;
            }
            case 3 :
                for(i=1; i < 10; i++){
                cout<< i + 1 << endl;
                i++;
            }
    }
    }
    return 0;
}

