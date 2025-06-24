#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Pelanggan {
    string nama;
    string namaItem;
    int hargaItem;
};

struct Node {
    Pelanggan data;
    Node* next;
};

Node* head = nullptr;

void inisialisasiData() {
    Node* n1 = new Node{{"Aulia", "Diamond FF", 15500}, nullptr};
    Node* n2 = new Node{{"Adel", "UC PUBG", 14000}, nullptr};
    Node* n3 = new Node{{"Arin", "Diamond ML", 9000}, nullptr};

    head = n1;
    n1->next = n2;
    n2->next = n3;

    cout << "Data pelanggan berhasil dimasukkan.\n";
    getch();
}

void tampilkanPelanggan() {
    system("cls");
    if (head == nullptr) {
        cout << "Belum ada data pelanggan.\n";
    } else {
        cout << left << setw(5) << "No"
             << setw(20) << "Nama"
             << setw(20) << "Item"
             << setw(15) << "Harga Item" << endl;

        int no = 1;
        for (Node* p = head; p != nullptr; p = p->next) {
            cout << setw(5) << no++
                 << setw(20) << p->data.nama
                 << setw(20) << p->data.namaItem
                 << "Rp " << p->data.hargaItem << endl;
        }
    }
    getch();
}

int main() {
    inisialisasiData();
    tampilkanPelanggan();
    return 0;
}
