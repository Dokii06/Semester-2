#include <iostream>

using namespace std;

int main(){
    int matrixA[2][2];
    int matrixB[2][2];
    int result[2][2];

    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << "Masukan nilai dari matrix A = [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << "Masukan nilai dari matrix B = [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }
    cout << endl;

    cout << "Matrix A : " << endl;
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << matrixA [i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B : " << endl;
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << matrixB [i][j] << " ";
        }
        cout << endl;
    }

     for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            result[i][j] = 0; //Untuk mereset hasil perhitungan
            for (int k = 0; k < 2; k++){
                result[i][j] = result [i][j] + (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }

    cout << "\nMatriks A * Matriks B : \n";
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nProgram Dibuat Oleh : Zaldy Seno Yudhanto (2310631170123)" << endl;
}
