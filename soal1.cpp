#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int nilai){
    Node* nodeBaru = new Node;
    nodeBaru->data = nilai;
    nodeBaru->next = top;
    top = nodeBaru;

    cout << "Data " << nilai << " berhasil ditambahkan ke stack\n";
}

void pop(){
    if(top == NULL){
        cout << "Stack masih kosong\n";
        return;
    }

    Node* hapus = top;
    cout << "Data " << hapus->data << " dihapus dari stack\n";

    top = top->next;
    delete hapus;
}

void display(){
    if(top == NULL){
        cout << "Stack kosong\n";
        return;
    }

    Node* bantu = top;

    cout << "Isi Stack :\n";
    while(bantu != NULL){
        cout << "| " << bantu->data << " |\n";
        cout << " ---\n";
        bantu = bantu->next;
    }
}

int main(){
    int pilih, data;

    do{
        cout << "\nMENU STACK\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout << "Masukkan data : ";
                cin >> data;
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak tersedia\n";
        }

    }while(pilih != 4);

    return 0;
}