#include <iostream>
#include <string>
using namespace std;

//fungsi untuk menghitung checksum
int hitungchecksum(long long angka_kartu){//angka_kartu adalah nomor kartu yang diinputkan
    int jumlah=0,digit,i=1;
    /*
    jumlah diinisialisasi dengan 0, digunakan untuk menghitung jumlah akhir
    digit utk menyimpan digit terakhir dari nomor kartu
    i diinisialisasi dengan 1, digunakan untuk menentukan digit genap atau ganjil
    */
    while(angka_kartu>0) { digit = angka_kartu%10;//jika nomor kartu lebih dari 0, digitnya adalah digit terakhir dari nomor kartu
        if (i%2==0) { digit = digit*2;//jika i genap, digit dikalikan 2
            if (digit>9) { digit = digit/10+digit%10;
            /* jika digit lebih dari 9, digit dipecah menjadi 2 digit
                dengan digit/10 adalah digit pertama dan digit%10 adalah digit kedua 
                lalu keduanya dijumlahkan
            */
            }
        }
        jumlah = jumlah+digit;//digit ditambahkan ke jumlah
        angka_kartu = angka_kartu/10;//angka_kartu dibagi 10 untuk menghapus digit terakhir
        i++;//i ditambahkan 1
    }
    return jumlah;//mengembalikan jumlah
}

//fungsi untuk menentukan tipe kartu
string tipekartu(long long nomor_kartu, int checksum) {
    string tipe_kartu;
    if (nomor_kartu >= 5100000000000000 && nomor_kartu <= 5599999999999999) {//jika nomor kartu diantara 5100000000000000 dan 5599999999999999
        if (checksum % 10 == 0) {// dan jika checksum habis dibagi 10
            tipe_kartu = "Mastercard";//maka kartu adalah Mastercard
        } else { 
            tipe_kartu = "Tidak Valid";//jika checksum tidak habis dibagi 10, maka kartu tidak valid
        }
    } else if ((nomor_kartu / 1000000000000000 == 4) || (nomor_kartu / 1000000000000 == 4)) {//jika nomor kartu diawali dengan 4
        if (checksum % 10 == 0) {//dan jika checksum habis dibagi 10
            tipe_kartu = "Visa";//maka kartu adalah Visa
        } else {
            tipe_kartu = "Tidak Valid";//jika checksum tidak habis dibagi 10, maka kartu tidak valid
        }
    } else { 
        tipe_kartu = "tidak diketahui";//jika nomor kartu tidak sesuai dengan kondisi diatas, maka tipe kartu tidak diketahui
    }
    return tipe_kartu;//mengembalikan tipe kartu
}

int main() {
    long long angka_kartu,nomor_kartu;
    cout << "masukkan angka kartu: ";//input nomor kartu
    cin >> angka_kartu;//memasukkan input ke variabel angka_kartu

    int checksum = hitungchecksum(angka_kartu);//menghitung checksum dengan memanggil fungsi hitungchecksum
    string tipe_kartu = tipekartu(angka_kartu, checksum);//menentukan tipe kartu dengan memanggil fungsi tipekartu

    nomor_kartu = angka_kartu;//nomor kartu diinisialisasi dengan angka kartu
    cout << "nomor kartu anda: " << nomor_kartu << endl;//menampilkan nomor kartu
    cout << "tipe kartu: " << tipe_kartu << endl;//menampilkan tipe kartu
    cout << "checksum: " << checksum << endl;//menampilkan checksum
    return 0;
}
