#include <iostream>
#include <conio.h>


using namespace std;
string nama ;
int a,i,u,e,o;


void cenam(){
    system("cls");
    nama = "Muhammad Akhsan Nurramdhan" ;
    for(i = 0 ; i < 3 ; i++){
    cout << nama << endl;
    }
}

void tambah(){
    system("cls");
    cout << "Masukan Nilai yang ingin dijumlahkan : " << endl ;
    cout << "Nilai 1 : " ;
    cin >> a ;
    cout << "Nilai 2 : " ;
    cin >> i;
    cout << "Hasil Penjumlahan Nilai1 + Nilai2 : " << a + i << endl;
}


void kurang(){
    system("cls");
    cout << "Masukan Nilai yang ingin dikurangi : " << endl ;
    cout << "Nilai 1 : " ;
    cin >> a ;
    cout << "Nilai 2 : " ;
    cin >> i;
    cout << "Hasil Pengurangan Nilai1 - Nilai2 : " << a - i << endl;
}


void bagi(){
    system("cls");
    cout << "Masukan Nilai yang ingin dibagi : " << endl ;
    cout << "Nilai 1 : " ;
    cin >> a ;
    cout << "Nilai 2 : " ;
    cin >> i;
    cout << "Hasil Pembagian Nilai1 / Nilai2 : " << a / i << endl;
}


void kali(){
    system("cls");
    cout << "Masukan Nilai yang ingin dikalikan : " << endl ;
    cout << "Nilai 1 : " ;
    cin >> a ;
    cout << "Nilai 2 : " ;
    cin >> i;
    cout << "Hasil Perkalian Nilai1 x Nilai2 : " << a * i << endl;
}

int main()
{
    start:
    system("cls");
    cout << "==================MENU==================" << endl;
    cout << "1. Cetak nama sebanyak 3 kali" << endl;
    cout << "2. Menghitung pertambahan" << endl;
    cout << "3. Menghitung pengurangan" << endl;
    cout << "4. Menghitung pembagian" << endl;
    cout << "5. Menghitung perkalian" << endl;
    cout << "Pilih Menu : ";
    cin >> a;
    switch(a){
    case 1 :
    cenam();
    getch();
    goto start;

    case 2 :
    tambah();
    getch();
    goto start;

    case 3 :
    kurang();
    getch();
    goto start;

    case 4 :
    bagi();
    getch();
    goto start;

    case 5 :
    kali();
    getch();
    goto start;
    }

    return 0;
}

