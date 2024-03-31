#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_BARANG = 100; // Maksimum jumlah barang yang dapat disimpan dalam array

void kembali();

struct barang {
    string nama;
    int harga, kode;
    int stok; // Menambahkan variabel stok

    barang* next;
};

barang* input = NULL;

//membuat fungsi hiasan garis
void garis (){
    for (int i = 0; i < 72; i++){
        cout << "=";
    }
    cout << endl;
}

void data(){
    if (input == NULL) {
        cout << "Belum ada data barang yang dimasukkan.\n";
    } else {
        cout << "Data Barang:\n\n";
        barang* temp = input;
        int counter = 1;
        while (temp != NULL) {
            cout << "Data ke-" << counter++ << ":\n";
            cout << "Nama Barang: " << temp->nama << endl;
            cout << "Harga Barang: Rp." << temp->harga << endl;
            cout << "Kode Barang: " << temp->kode << endl;
            cout << "Stok Barang: " << temp->stok << endl;
            cout << "Alamat Barang: " << temp << endl;
            cout << endl;
            cout << endl;
            temp = temp->next;
        }
    }
}

void create (){
    int jumlah;
    do {
        cout << "Masukan jumlah barang yang ingin di data : ";
        cin >> jumlah;
        garis();

        for(int i = 0; i < jumlah; i++){
            barang* newNode = new barang;
            newNode->next = NULL;
            cin.ignore(); // Membersihkan newline karakter dari buffer
            cout << "Masukan nama barang: ";
            getline(cin, newNode->nama); // Membaca seluruh baris sebagai input nama barang
            cout << "Masukan harga barang: ";
            cin >> newNode->harga;
            cout << "Masukan kode barang: ";
            cin >> newNode->kode;
            cout << "Masukan stok barang: ";
            cin >> newNode->stok; // Membaca stok barang

            if(input == NULL){
                input = newNode;
            }
            else{
                barang* temp = input;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            system("cls");
        }
        cout << "Data berhasil dibuat.\n";
        kembali();
    } while (true);
}

void read() {
    data();
    kembali();
}

void update() {
    data();
    int kode;
    cout << "Masukkan kode barang yang ingin diupdate: ";
    cin >> kode;

    barang* temp = input;
    bool found = false;
    while (temp != NULL) {
        if (temp->kode == kode) {
            cout << "Data barang ditemukan.\n";
            cout << "Masukkan nama barang yang baru: ";
            cin.ignore(); // Membersihkan newline karakter dari buffer
            getline(cin, temp->nama); // Membaca seluruh baris sebagai input nama barang
            cout << "Masukkan harga barang yang baru: ";
            cin >> temp->harga;
            cout << "Masukkan stok barang yang baru: ";
            cin >> temp->stok; // Memperbarui stok barang
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Data barang dengan kode tersebut tidak ditemukan.\n";
    }

    kembali();
}

void del() {
    data();
    int kode;
    cout << "Masukkan kode barang yang ingin dihapus: ";
    cin >> kode;

    barang* prev = NULL;
    barang* temp = input;
    bool found = false;

    while (temp != NULL) {
        if (temp->kode == kode) {
            cout << "Data barang ditemukan dan dihapus.\n";
            if (prev == NULL) {
                // Jika barang yang ingin dihapus berada di awal linked list
                input = input->next;
            } else {
                // Jika barang yang ingin dihapus berada di tengah atau akhir linked list
                prev->next = temp->next;
            }
            delete temp;
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        cout << "Data barang dengan kode tersebut tidak ditemukan.\n";
    }

    kembali();
}

void menuUtama(){
    int pil;
    garis();
    cout << "Selamat datang di program pendataan barang!\n\n";
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
