#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void kembali();//mendeklarasikan fungsi

//membuat struct
 struct nilai{
    int absen, tugas, uts, uas;
};

struct mahasiswa{
    string nama,npm;
    float nilaiAkhir;
    nilai nilai;
    char nilaiHuruf;
};

//membuat fungsi hiasan garis
void garis (){
    for (int i = 0; i < 72; i++){
        cout << "=";
    }
    cout << endl;
}

//medeklarasikan array agar menjadi global
const int MAX_MHS = 20;
mahasiswa mhs[MAX_MHS];
int jumlah = 0;

//fungsi untuk menghitung nilai akhir
float nilaiAkhir(int absen, int tugas, int uts, int uas){
    return 0.1*absen + 0.2*tugas + 0.3*uts + 0.4*uas;
}

//fungsi untuk menghitung nilai huruf
char nilaiHuruf(float ipk){
    if(ipk > 80){
        return 'A';
    } else if (80 >= ipk > 70){
        return 'B';
    } else if (70 >= ipk > 60){
        return 'C';
    } else {
        return 'D';
    }
}

void data(){
    cout << "Data Mahasiswa" << endl;
    garis();
    cout << setiosflags(ios::left) << setw(32) << "Nama mahasiswa";
    cout << setiosflags(ios::left) << setw(14) << "NPM" ;
    cout << setiosflags(ios::left) << setw(6) << "Absen";
    cout << setiosflags(ios::left) << setw(7) << "Tugas";
    cout << setiosflags(ios::left) << setw(6) << "UTS";
    cout << setiosflags(ios::left) << setw(6) << "UAS";
    cout << setiosflags(ios::left) << setw(6) << "Final";
    cout << setiosflags(ios::left) << setw(4) << "Huruf\n";
    garis();
    for(int i = 0; i < jumlah; i++){
        cout << setiosflags(ios::left) << setw(30) << mhs[i].nama;
        cout << setiosflags(ios::left) << setw(17) << mhs[i].npm;
        cout << setiosflags(ios::left) << setw(6) << mhs[i].nilai.absen;
        cout << setiosflags(ios::left) << setw(6) << mhs[i].nilai.tugas;
        cout << setiosflags(ios::left) << setw(6) << mhs[i].nilai.uts;
        cout << setiosflags(ios::left) << setw(6) << mhs[i].nilai.uas;
        cout << setiosflags(ios::left) << setw(6) << mhs[i].nilaiAkhir;
        cout << setiosflags(ios::left) << setw(4) << mhs[i].nilaiHuruf;
        cout << endl;
    }
}

void create (){
    do {
        cout << "Masukan jumlah mahasiswa : ";
        cin >> jumlah;
        if(jumlah <= 20 && jumlah > 0){
            garis();
            for(int i = 0; i < jumlah; i++){
                cout << "Masukan data mahasiswa ke-" << i + 1 << endl;
                cout << "Nama Mahasiswa : ";
                //agar bisa lebih dari satu kata
                cin.ignore();
                getline(cin, mhs[i].nama);
                cout << "NPM Mahasiswa : ";
                cin >> mhs[i].npm;
                cout << " Masukan nilai\n";
                cout << "Nilai Absen : ";
                cin >> mhs[i].nilai.absen;
                cout << "Nilai Tugas : ";
                cin >> mhs[i].nilai.tugas;
                cout << "Nilai UTS : ";
                cin >> mhs[i].nilai.uts;
                cout << "Nilai UAS : ";
                cin >> mhs[i].nilai.uas;;

                mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].nilai.absen, mhs[i].nilai.tugas, mhs[i].nilai.uts, mhs[i].nilai.uas);
                mhs[i].nilaiHuruf = nilaiHuruf(mhs[i].nilaiAkhir);

                system("cls");

            }
            cout << "Data mahasiswa berhasil dibuat.\n";
            kembali();
        } else {
            cout << "Batas jumlah adalah 20!\nMasukan jumlah yang valid\n\n";
        }
    } while (true);
}

void read (){
    data();
    kembali();
}

void update (){
    string npm;
    data();
    cout << "\nMasukan NPM mahassiswa yang ingin diperbaharui: ";
    cin >> npm;
    bool found = false;
    for (int i = 0; i < jumlah; ++i) {
        if (mhs[i].npm == npm) {
            cout << "Data mahasiswa ditemukan.\n";
            system("cls");
            cout << "Masukkan data baru:\n";
            cout << "Nama Mahasiswa : ";
            //agar bisa lebih dari satu kata
            cin.ignore();
            getline(cin, mhs[i].nama);
            cout << "Nilai Absen : ";
            cin >> mhs[i].nilai.absen;
            cout << "Nilai Tugas : ";
            cin >> mhs[i].nilai.tugas;
            cout << "Nilai UTS : ";
            cin >> mhs[i].nilai.uts;
            cout << "Nilai UAS : ";
            cin >> mhs[i].nilai.uas;

            mhs[i].nilaiAkhir = nilaiAkhir(mhs[i].nilai.absen, mhs[i].nilai.tugas, mhs[i].nilai.uts, mhs[i].nilai.uas);
            mhs[i].nilaiHuruf = nilaiHuruf(mhs[i].nilaiAkhir);

            cout << "Data berhasil diupdate.\n";
            found = true;
            break;
        }
    }
    if (!found){
        cout << "Data mahasiswa dengan NPM tersebut tidak ditemukan.\n";
    }
    kembali();
}

void del (){
    string npm;
    data();
    cout << "\nMasukkan NPM mahasiswa yang ingin dihapus: ";
    cin >> npm;
    bool found = false;
    for (int i = 0; i < jumlah; ++i) {
        if (mhs[i].npm == npm) {
            cout << "Data mahasiswa ditemukan.\n";
            for (int j = i; j < jumlah - 1; ++j) {
                mhs[j] = mhs[j + 1];
            }
            jumlah--;
            cout << "Data berhasil dihapus.\n";
            found = true;
            break;
        }
    }
    if (!found){
        cout << "Data mahasiswa dengan NPM tersebut tidak ditemukan.\n";
    }
    kembali();
}

void menuUtama(){
    int pil;
    garis();
    cout << "Selamat datang di program penginputan nilai mahasiswa\nuniversitas singaperbangsa karawang!\n\n";
    cout << "Menu Utama\n";
    garis();
    cout << setiosflags(ios::left) << setw(15) << "[1]Create";
    cout << setiosflags(ios::left) << setw(15) << "[2]Read";
    cout << setiosflags(ios::left) << setw(15) << "[3]Update";
    cout << setiosflags(ios::left) << setw(15) << "[4]Delete";
    cout << setiosflags(ios::left) << setw(15) << "[5]Exit";
    cout << endl;
    garis();

    do {
        cout << "\nMasukan Pilihan :";
        cin >> pil;

        switch (pil){
        case 1 :
            system ("cls");
            create ();
            break;
        case 2 :
            system ("cls");
            read ();
            break;
        case 3 :
            system ("cls");
            update ();
            break;
        case 4 :
            system ("cls");
            del ();
            break;
        case 5 :
            return;
            break;
        default:
            cout << "Pilihan tidak valid. Silahkan masukan pilihan antara 1 hingga 5\n";
        }
    } while (true);
}

void kembali (){
    char menu;

    cout << endl;
    garis();
    cout << "\nKetik [<] untuk kembali ke menu\n";
    do {
        cout << "Pilihan : ";
        cin >> menu;

        switch (menu){
        case '<' :
            system("cls");
            menuUtama();
            break;
        default :
            cout << "Pilihan tidak valid. Silahkan masukan pilihan [<] untuk kembali\n";
        }

    } while (menu != '<');

}


int main(){
    menuUtama();
    cout << "Program dibuat oleh Zaldy Seno Yudhanto (2310631170123)\n";
    return 0;
}
