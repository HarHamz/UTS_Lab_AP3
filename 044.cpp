#include <iostream>
#include <string>
using namespace std;

int main() {
    long long angka_kartu,nomor_kartu;
    string tipe_kartu;
    int checksum,jumlah,digit,i;

    cout<<"masukkan angka kartu: ";
    cin>>angka_kartu;

    nomor_kartu = angka_kartu;
    cout<<"nomor kartu anda: "<<nomor_kartu<<endl;

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


    //untuk tipe kartu
    if (nomor_kartu>=5100000000000000 && nomor_kartu<=5599999999999999) {
        if (jumlah%10==0) {
            tipe_kartu = "Mastercard";
        }
        else {
            tipe_kartu = "Tidak Valid";
        }
    }
    else if((nomor_kartu/1000000000000000==4) || (nomor_kartu/1000000000000==4)) {
        if (jumlah%10==0) {
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