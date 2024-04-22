#include <iostream>
using namespace std;
main (){
    long long nomorKartu;
    int digitAkhir,jumlah;
    do 
    {
    cout<<"Masukkan nomor kartu : ";
    cin>>nomorKartu;
    }
    while(nomorKartu<=0);

    while(nomorKartu>0){
        digitAkhir=nomorKartu%10;
        nomorKartu/=100;
        cout<<digitAkhir<<" ";
    }
    
}