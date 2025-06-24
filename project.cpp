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

void tambahPelanggan(string nama, string item, int harga) {
    Node* baru = new Node{{nama, item, harga}, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != nullptr)
            p = p->next;
        p->next = baru;
    }
    cout << "Data pelanggan baru berhasil ditambahkan.\n";
}

void hapusPelanggan(int no) {
    if (head == nullptr) {
        cout << "Data kosong!\n";
        return;
    }

    Node* hapus;
    if (no == 1) {
        hapus = head;
        head = head->next;
    } else {
        Node* p = head;
        for (int i = 1; i < no - 1 && p != nullptr; i++)
            p = p->next;
        if (p == nullptr || p->next == nullptr) {
            cout << "Nomor tidak valid!\n";
            return;
        }
        hapus = p->next;
        p->next = hapus->next;
    }
    cout << "Data \"" << hapus->data.nama << "\" berhasil dihapus.\n";
    delete hapus;
}

void totalHarga() {
    int total = 0;
    for (Node* p = head; p != nullptr; p = p->next)
        total += p->data.hargaItem;
    cout << "Total seluruh harga top up: Rp " << total << endl;
}

int main() {
    inisialisasiData();
    tampilkanPelanggan();

    cout << "\nMenambah pelanggan baru...\n";
    tambahPelanggan("Budi", "Diamond FF", 20000);
    tampilkanPelanggan();

    cout << "\nMenghapus pelanggan nomor 2...\n";
    hapusPelanggan(2);
    tampilkanPelanggan();

        cout << "\nMenghitung total harga...\n";
    totalHarga();

    return 0;
}
