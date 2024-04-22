#include <iostream>
using namespace std;

int main() {
    long long angka_kartu;
    string tipe_kartu;
    int checksum,jumlah,digit,i;

    cout<<"masukkan angka kartu: ";
    cin>>angka_kartu;
    cout<<"nomor kartu anda: "<<angka_kartu<<endl;

    //untuk checksum
    jumlah = 0;
    i=1;
    while(angka_kartu>0) {
        digit = angka_kartu%10;
        if (i%2==0) {
            digit = digit*2;
            if (digit>9) {
                digit = digit/10+digit%10;
            }
        }
    jumlah = jumlah+digit;
    angka_kartu = angka_kartu/10;
    i++;
    }
    checksum = jumlah%10;


    //untuk tipe kartu
    if (angka_kartu>5099999999999999 && angka_kartu<5600000000000000) {
        if (checksum=0) {
            tipe_kartu = "Mastercard";
        }
        else {
            tipe_kartu = "Tidak Valid";
        }
    }
    else if((angka_kartu/10000000000000==4) || (angka_kartu/10000000000==4)) {
        if (checksum=0) {
            tipe_kartu = "Visa ";
        }
        else {
            tipe_kartu = "Tidak Valid";
    }
    }
    else {
        tipe_kartu = "tidak diketahui";
    }
    

 
    cout<<"tipe kartu: "<<tipe_kartu<<endl;
    cout<<"checksum: "<<jumlah<<endl;
    return 0;
}