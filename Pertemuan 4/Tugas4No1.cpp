#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node*input = NULL;

//Fungsi untuk menginput data
void normal(){
    int n;
    cout << "Banyaknya data yang ingin di input:";
    cin >> n;
    cout << endl;
    for(int i = 0; i < n; i++){
        node* newNode = new node;
        newNode->next = NULL;
        cout << "Inputkan data ke-" << i+1 <<" : ";
        cin >> newNode->data;

        if(input == NULL){
            input = newNode;
        }
        else{
            node* temp = input;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

    }
    cout << endl;

}

//Fungsi untuk mereverse
node* revers(node* head){
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while(current != NULL){
        next = current->next; // Simpan next node
        current->next = prev; // Putar pointer next node
        prev = current;       // Geser prev
        current = next;       // Geser current
    }
    head = prev; // Atur head ke node terakhir yang sudah dibalik
    return head;
}

//Fungsi untuk membalikan node
void output(node* head){
    node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){

    normal();
    cout << "Output data yang kita masukan: ";
    output(input);

    input = revers(input);

    cout << "Output data yang sudah di reverse: ";
    output(input);

    cout << "\nProgram dibuat oleh Zaldy Seno Yudhanto (2310631170123)\n";

    return 0;


}
