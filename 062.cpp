#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menghitung checksum menggunakan Algoritma Luhn
    long long hitungchecksum (const string& nomorkartu) 
    {
        long long jumlah = 0;
        bool ganti = false;

// Iterasi setiap digit kartu dari paling ujung kanan ke kiri
    for (int i = nomorkartu.length() - 1; i >= 0; i--) 
    {
        long long digit = nomorkartu[i] - '0'; // Mengubah karakter ke angka

// Periksa apakah perlu menggandakan digit
if (ganti) 
{
    digit *= 2; // ika 'ganti' = 'true', kalikan digit dengan 2.

// Jika hasil kali menghasilkan dua digit, tambahkan kedua digit
if (digit > 9) 
{
    digit -= 9;
}
}

// Tambahkan digit ke jumlah
jumlah += digit;
// mengubah nilai 'ganti' untuk iterasi selanjutnya
ganti = !ganti;
}

return jumlah; // Mengembalikan hasil jumlah sebagai checksum
}

// Fungsi untuk memeriksa nomor kartu valid atau tidak
bool periksakartuvalid (const string& nomorkartu) 
{
    long long jumlah = hitungchecksum (nomorkartu);
// Kartu valid jika jumlah modulo 10 sama dengan 0
    return (jumlah % 10 == 0);
}

// Fungsi untuk menentukan jenis kartu
string jeniskartu (const string& nomorkartu) 
{
// Memeriksa digit awal nomor kartu
    if (nomorkartu.substr(0, 1) == "4") //Memeriksa apakah digit pertama nomor kartu adalah 4, yang menunjukkan kartu VISA.
    {
        return "VISA"; 
    } 
    //Memeriksa apakah dua digit pertama nomor kartu adalah 51-55, yang menunjukkan kartu MASTERCARD.
    else if (nomorkartu.substr(0, 2) == "51" || 
    nomorkartu.substr(0, 2) == "52" ||
    nomorkartu.substr(0, 2) == "53" ||
    nomorkartu.substr(0, 2) == "54" ||
    nomorkartu.substr(0, 2) == "55")
    {
        return "MASTERCARD";
    }
    else 
    {
        return "TIDAK DIKETAHUI"; // Mengembalikan "TIDAK DIKETAHUI" jika nomor kartu tidak sesuai dengan VISA atau MASTERCARD.
    }
}

int main() // titik masuk program
{
    string nomorkartu;
    
// Menerima input dari pengguna
    cout << "Masukkan angka kartu: ";
    cin >> nomorkartu;

// Cetak nomor kartu
    cout << "Nomor kartu anda: " << nomorkartu << endl;

// Periksa apakah kartu valid
    if (periksakartuvalid (nomorkartu)) 
    {
// Menentukan jenis kartu
        string jenis = jeniskartu(nomorkartu);
        cout << "Tipe kartu anda: " << jenis << endl;
    } 
    else 
    {
        cout << "Tipe kartu anda: TIDAK VALID" << endl;
    }

// Hitung checksum
    long long checksum = hitungchecksum(nomorkartu);
    cout << "checksum: " << checksum << endl;
    
    return 0;
}