#include <iostream>
#include <string>
using namespace std;

//fungsi untuk menghitung checksum
int hitungchecksum(long long angka_kartu){
    int jumlah=0,digit,i=1;
    /*
    jumlah diinisialisasi dengan 0, digunakan untuk menghitung jumlah akhir
    digit utk menyimpan digit terakhir dari nomor kartu
    i diinisialisasi dengan 1, digunakan untuk menentukan digit genap atau ganjil
    */
    while(angka_kartu>0) {
        digit = angka_kartu%10;
        //mengambil digit terakhir dari angka_kartu
        if (i%2==0) {
            /*
            jika i genap, digit dikali dua kemudian jika hasilnya lebih dari 9,
            maka digit tersebut akan diubah menjadi jumlah dari dua digit tersebut
            */
            digit = digit*2;
            if (digit>9) {
                digit = digit/10+digit%10;
            }
        }
        jumlah = jumlah+digit;
        //digit ditambahkan ke jumlah
        angka_kartu = angka_kartu/10;
        //angka_kartu dibagi 10 untuk menghapus digit terakhir
        i++;
        //i ditambahkan 1
    }
    return jumlah;
    //mengembalikan jumlah
}

//fungsi untuk menentukan tipe kartu
string tipekartu(long long nomor_kartu, int checksum) {
    string tipe_kartu;
    if (nomor_kartu >= 5100000000000000 && nomor_kartu <= 5599999999999999) {
        if (checksum % 10 == 0) {
            tipe_kartu = "Mastercard";
        } else {
            tipe_kartu = "Tidak Valid";
            //jika checksum tidak habis dibagi 10, maka kartu tidak valid
        }
    } else if ((nomor_kartu / 1000000000000000 == 4) || (nomor_kartu / 1000000000000 == 4)) {
        if (checksum % 10 == 0) {
            tipe_kartu = "Visa";
        } else {
            tipe_kartu = "Tidak Valid";
            //jika checksum tidak habis dibagi 10, maka kartu tidak valid
        }
    } else {
        tipe_kartu = "tidak diketahui";
        //jika nomor kartu tidak sesuai dengan tipe kartu yang ada
    }
    return tipe_kartu;
    //mengembalikan tipe kartu
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
