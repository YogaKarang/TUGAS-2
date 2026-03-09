#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* depan = NULL;
Node* belakang = NULL;

void enqueue(int nilai){
    Node* nodeBaru = new Node;
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;

    if(depan == NULL){
        depan = belakang = nodeBaru;
    }else{
        belakang->next = nodeBaru;
        belakang = nodeBaru;
    }

    cout << "Data " << nilai << " ditambahkan ke queue\n";
}

void dequeue(){
    if(depan == NULL){
        cout << "Queue masih kosong\n";
        return;
    }

    Node* hapus = depan;
    cout << "Data " << hapus->data << " keluar dari queue\n";

    depan = depan->next;

    if(depan == NULL){
        belakang = NULL;
    }

    delete hapus;
}

void display(){
    if(depan == NULL){
        cout << "Queue kosong\n";
        return;
    }

    Node* bantu = depan;

    cout << "Isi Queue : ";
    while(bantu != NULL){
        cout << bantu->data;

        if(bantu->next != NULL){
            cout << " -> ";
        }

        bantu = bantu->next;
    }

    cout << endl;
}

int main(){
    int pilih, data;

    do{
        cout << "\nMENU QUEUE\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout << "Masukkan data : ";
                cin >> data;
                enqueue(data);
                break;

            case 2:
                dequeue();
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
