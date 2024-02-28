#include <iostream>
using namespace std;

int main() {
    char input[] = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'd'};
    int panjang = 10;

    cout << "Input: ";
    for (int i = 0; i < panjang; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    int compressed = 0;
    int count = 1;

    for (int i = 0; i < panjang; i++) {
        // Jika karakter saat ini sama dengan karakter berikutnya
        if (i < panjang - 1 && input[i] == input[i + 1]) {
            count++; // Tambah jumlah kemunculan karakter
        } else {
            // Tambahkan karakter saat ini ke array hasil kompresi
            input[compressed++] = input[i];
            // Tambahkan jumlah kemunculan karakter jika lebih dari 1
            if (count > 0) {
                input[compressed++] = count + '0'; // Ubah jumlah menjadi karakter dan tambahkan ke array
            }
            count = 1; // Reset count untuk karakter baru
        }
    }

    // Mengakhiri string hasil kompresi
    input[compressed] = '0';

    cout << "Output: ";
    for (int i = 0; input[i] != '0'; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    cout << "\nProgram Ini Dibuat Oleh : Zaldy Seno Yudhanto (2310631170123)\n";

    return 0;
}
