#include <iostream>
using namespace std;

//fungsi untuk mwnghitung checksum
int hitungchecksum(long long angka_kartu){
    int jumlah=0,digit,i=1;
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
    return jumlah;
}

//fungsi untuk menentukan tipe kartu
string tipekartu(long long nomor_kartu, int checksum) {
    string tipe_kartu;
    if (nomor_kartu >= 5100000000000000 && nomor_kartu <= 5599999999999999) {
        if (checksum % 10 == 0) {
            tipe_kartu = "Mastercard";
        } else {
            tipe_kartu = "Tidak Valid";
        }
    } else if ((nomor_kartu / 1000000000000000 == 4) || (nomor_kartu / 1000000000000 == 4)) {
        if (checksum % 10 == 0) {
            tipe_kartu = "Visa";
        } else {
            tipe_kartu = "Tidak Valid";
        }
    } else {
        tipe_kartu = "tidak diketahui";
    }
    return tipe_kartu;
}

int main() {
    long long angka_kartu,nomor_kartu;
    cout << "masukkan angka kartu: ";
    cin >> angka_kartu;

    int checksum = hitungchecksum(angka_kartu);
    string tipe_kartu = tipekartu(angka_kartu, checksum);

    nomor_kartu = angka_kartu;
    cout << "nomor kartu anda: " << nomor_kartu << endl;
    cout << "tipe kartu: " << tipe_kartu << endl;
    cout << "checksum: " << checksum << endl;
    return 0;
}
