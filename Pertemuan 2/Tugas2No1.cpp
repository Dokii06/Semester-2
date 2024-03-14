#include <iostream>
#include <string>
using namespace std;

const int MAX_BARANG = 50;
const int MAX_HARI = 5;

struct Barang {
    string nama;
    int jumlahPerHari[MAX_HARI];
};

Barang dataBarang[MAX_BARANG][MAX_HARI];
int jumlahBarangInput, jumlahHariInput;

void inputData() {
    do {
        cout << "Masukkan jumlah barang yang diinput: ";
        cin >> jumlahBarangInput;

        if (jumlahBarangInput > MAX_BARANG) {
            cout << "Jumlah barang melebihi batas maksimum!" << endl;
            return;
        }

        cout << "Masukkan jumlah hari: ";
        cin >> jumlahHariInput;

        if (jumlahHariInput < MAX_HARI) {
            cout << "Jumlah hari tidak mencukupi!" << endl;
            return;
        }

        for (int i = 0; i < jumlahBarangInput; ++i) {
            cout << "\nMasukkan nama barang ke-" << i + 1 << ": ";
            cin >> dataBarang[i][0].nama; // Menggunakan hari pertama untuk menyimpan nama barang
            for (int j = 0; j < jumlahHariInput; ++j) {
                cout << "Jumlah barang untuk hari ke-" << j + 1 << ": ";
                cin >> dataBarang[i][j].jumlahPerHari[j];
            }
        }
    } while (false); // Membuat loop hanya dijalankan sekali, sehingga input hanya diminta sekali
}

void detailBarang() {
    int tanggal, kodeBarang;
    cout << "\nMencari barang yang diinginkan";
    do {
        cout << "\nMasukkan tanggal: ";
        cin >> tanggal;
        if (tanggal < 1 || tanggal > jumlahHariInput) {
            cout << "Tanggal yang dimasukkan tidak valid. Mohon masukkan kembali." << endl;
        }
    } while (tanggal < 1 || tanggal > jumlahHariInput);

    cout << "Masukkan kode barang: ";
    cin >> kodeBarang;

    if (kodeBarang < 0 || kodeBarang >= jumlahBarangInput) {
        cout << "Data barang tidak ditemukan!" << endl;
        return;
    }

    cout << "\n===================================================";
    cout << "\nDetail barang untuk tanggal " << tanggal << ":" << endl;
    cout << "Nama Barang: " << dataBarang[kodeBarang][0].nama << endl; // Mengambil nama barang dari hari pertama
    cout << "Jumlah Barang: " << dataBarang[kodeBarang][tanggal - 1].jumlahPerHari[tanggal - 1] << " buah" << endl;
    cout << "Alamat Barang pada komputer: " << &dataBarang[kodeBarang] << endl;
}

int main() {
    inputData();

    char pilihan;
    do {
        detailBarang();
        cout << "\nApakah ingin mencari detail barang lagi? (Y/N): ";
        cin >> pilihan;
    } while (pilihan == 'Y' || pilihan == 'y');

    cout << "Program dibuat oleh: Zaldy Seno Yudhanto(2310631170123)";

    return 0;
}
