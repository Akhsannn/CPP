#include <iostream>

using namespace std;
int x,y,z;
int main()
{
    cout << "Menampilan Angka 1 s.d 5" << endl;
    for (x = 1; x <= 5; x++){
            for (y = 1; y <= x ; y++){
                  cout << y ;
            }
            cout << endl ;
      }
    cout << endl ;
    cout<<"Menampilkan Angka 5 s.d 1" <<endl;
    for (x=5; x>=1; x--) {
        for( y=0; y<=0+x; y++) {
        cout<<" ";
        }
        for (z = x; z <= 5 ; z++){
            cout << z ;
            }
            cout<<endl;
}
    cout << endl ;
    cout<<"Menampilkan Bintang, 5 baris & kolom" <<endl;
    for (x = 1 ; x <=5 ; x++){
        for(y = 0 ; y <= 5 ; y++){
         cout<<"*";
        }
        cout<<endl;
        }

    return 0;
}
