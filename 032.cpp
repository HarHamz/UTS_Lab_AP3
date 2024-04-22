#include <iostream>
using namespace std;
main (){
    string nomorKartu;
    int digitKartu,checksum;
    string tipeKartu;
    cout<<"Masukkan nomor kartu : ";
    cin>>nomorKartu;
        if((nomorKartu.length()==16)&&((nomorKartu[0]==51||nomorKartu[0]==52||nomorKartu[0]==53||nomorKartu[0]==54||nomorKartu[0]==55)))
        {
            tipeKartu="MASTERCARD";
        }
        else if (((nomorKartu.length()==13)&&(nomorKartu[0]==4))||((nomorKartu.length()==13)&&(nomorKartu[0]==4))){
            tipeKartu="VISA";
        }
    cout<<digitKartu<<endl;
    cout<<"Nomor kartu anda : "<<nomorKartu<<endl;
    cout<<"Tipe kartu anda : "<<tipeKartu<<endl;
    cout<<"Checksum : "<<checksum<<endl;
}