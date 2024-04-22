#include <iostream>
using namespace std;
main (){
    string nomorKartu;
    string tipeKartu;
    cout<<"Masukkan nomor kartu : ";
    cin>>nomorKartu;
        if(nomorKartu.length()==16)
        {
            if ((nomorKartu[0] == '5')&&(nomorKartu[1]=='1'||nomorKartu[1]=='2'||nomorKartu[1]=='3'||nomorKartu[1]=='4'||nomorKartu[1]=='5')) 
            tipeKartu = "MASTERCARD";
           else if (nomorKartu[0] == '4') 
            tipeKartu = "VISA";
            else tipeKartu="Tidak Valid";
        }
        else if ((nomorKartu.length()==13)&&(nomorKartu[0]=='4')){
            tipeKartu="VISA";
        }
        else tipeKartu="Tidak Valid";
    cout<<"Nomor kartu anda : "<<nomorKartu<<endl;
    cout<<"Tipe kartu anda : "<<tipeKartu<<endl;
    return 0;
}