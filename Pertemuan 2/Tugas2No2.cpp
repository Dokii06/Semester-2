#include <iostream>
using namespace std;

const int MAX_N = 100;

// Fungsi untuk melakukan rotasi 90 derajat searah jarum jam pada array n x n
void putarArray(int arr[MAX_N][MAX_N], int n) {
    // Transpose array
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Reverse setiap baris
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(arr[i][j], arr[i][n - j - 1]);
        }
    }
}

// Fungsi untuk menampilkan array
void tampilkan(int arr[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;
    cout << endl;

    // Inisialisasi array sebelum rotasi
    int matrixSebelum[MAX_N][MAX_N];

    // Input elemen array sebelum rotasi
    cout << "Masukkan elemen array " << n << " x " << n << " sebelum rotasi:\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Masukkan array [" << i << "][" << j << "] : ";
            cin >> matrixSebelum[i][j];
        }
    }

    // Menampilkan array sebelum rotasi
    cout << "\n=======================================================";
    cout << "\nArray sebelum rotasi 90 derajat searah jarum jam:" << endl;
    tampilkan(matrixSebelum, n);

    // Inisialisasi array sesudah rotasi
    int matrixSesudah[MAX_N][MAX_N];

    // Mengisi array sesudah rotasi dengan nilai dari array sebelum rotasi
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrixSesudah[i][j] = matrixSebelum[i][j];
        }
    }

    // Rotasi array
    putarArray(matrixSesudah, n);

    // Menampilkan array yang sudah dirotasi
    cout << "\n=======================================================";
    cout << "\nArray setelah rotasi 90 derajat searah jarum jam:" << endl;
    tampilkan(matrixSesudah, n);

    cout << "Program dibuat oleh: Zaldy Seno Yudhanto(2310631170123)";

    return 0;
}
