#include <iostream>
using namespace std;

int main(){
    //Membuat batas maksimal jumlah array ke dalam memori
    const int maxMhs = 50;
    string namaMhs[maxMhs];

    int n;
    string* pNamaMhs;
    pNamaMhs = &namaMhs[0];

    //melakukan perulangan agar program berjalan sesuai perintah pengondisian
    do {
        cout << "Masukan Jumlah Mahasiswa: ";//menginput jumlah mahasiswa
        cin >> n;
        //pengkondisian
        if (n > maxMhs){
            cout << "Jumlah Mahasiswa Melebihi Batas Maksimum.\n";
        }
        if (n < 10){
            cout << "Masukan Jumlah Mahasiswa Lebih Atau Sama Dengan 10.\n";
        }
    } while (n > maxMhs || n < 10);//melanjutkan program jika melewati syarat

    //memasukan nama mahasiswa
    for(int i = 0; i < n; i++){
        cout << "Masukan Nama Mahasiswa ke-" << i+1 << ": ";
        cin >> namaMhs[i];
    }

    //output nama mahasiswa dan alamatnya
    cout << "\n\nNama Mahasiswa \t\t Alamat Pada Komputer\n";
    cout << "========================================\n";

    for (int k = 0; k < n; k++){
        cout << *pNamaMhs << "\t\t\t " << pNamaMhs << endl;
        pNamaMhs++;
    }

    cout << "\nProgram Ini Dibuat Oleh : Zaldy Seno Yudhanto (2310631170123)\n";
    return 0;
}
