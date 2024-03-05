#include <iostream>
using namespace std;

int main(){
    const int n = 50;
    string namaBarang[n];

    int jumlahBarang, jumlahHari;

    cout << "Masukan jumlah barang yang diinput : ";
    cin >> jumlahBarang;

    cout << "Berapa hari ingin menginput data : ";
    cin >> jumlahHari;

    cout << "Masukan nama barang\n";
    for (int i = 0; i < jumlahBarang; i++){
        cout << "Nama barang ke-" << i+1 << " :";
        cin >> namaBarang[i];
    }

    cout << namaBarang;


}
