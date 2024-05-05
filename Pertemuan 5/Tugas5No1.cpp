#include <iostream>
#include <windows.h>

using namespace std;


struct node{
    int nilai;
    node* next;
};

struct Stack {
    node* top;
    Stack(){
        top = NULL;
    }

    void push(int value){
        node* newnode = new node;
        newnode->nilai = value;
        newnode->next = top;
        top = newnode;

        cout << "*nilai " << value << " sudah diinput ke dalam menara yang diinginkan.\n";
    }

    void pop(){
        if(top == NULL){
            cout << "Stack sudah kosong.\n";
            return;
        }
        node* temp = top;
        int poppedValue = top->nilai;
        top = top->next;
        delete temp;

        cout << "*nilai " << poppedValue << "sudah dihapus dari menara yang diinginkan.\n";
    }

    void display(char namaMenara){
        if(top == NULL){
            cout << "Menara" << namaMenara << " : ";
            cout << endl;
            return;
        }
        node* currentNode = top;
        cout << "Menara " << namaMenara << ": ";
        while (currentNode != NULL){
            cout << currentNode->nilai << " -> ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void pindah(Stack& tujuan, char namaTujuan){
        if (top == NULL){
            cout << "Nilai dari menara yang ingin dipindahkan kosong, tidak ada yang bisa dipindahkan.\n";
            return;
        }
        int value = top->nilai;
        pop();
        tujuan.push(value);
        cout << "Pemindahan nilai " << value <<  " ke menara " << namaTujuan << " berhasil." <<  endl;
    }
};

int main(){
    //menginisiasi nilai awal yang sudah ditentukan
    Stack A, B, C;
    A.push(20);
    A.push(40);
    A.push(60);

    cout << "\nIni adalah stack dari menara hanoi!\n";
    cout << "===================================\n";
    A.display('A');
    B.display('B');
    C.display('C');

    cout << "\nPemindahan nilai dari menara B ke menara A!\n";
    B.pindah(A, 'A');
    cout << "Setelah pemindahan nilai dari menara B ke menara A\n";
    cout << "==================================================\n";
    A.display('A');
    B.display('B');
    C.display('C');

    cout << "\nPemindahan nilai dari menara A ke menara B!\n";
    A.pindah(B, 'B');
    cout << "Setelah pemindahan nilai dari menara A ke menara B\n";
    cout << "==================================================\n";
    A.display('A');
    B.display('B');
    C.display('C');

    cout << "\nPemindahan nilai dari menara C ke menara A!\n";
    C.pindah(A, 'A');
    cout << "Setelah pemindahan nilai dari menara C ke menara A\n";
    cout << "==================================================\n";
    A.display('A');
    B.display('B');
    C.display('C');


    cout << "Program dibuat oleh Zaldy Seno Yudhanto (2310631170123)\n";
    return 0;
}
