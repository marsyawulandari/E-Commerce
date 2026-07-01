#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

string toLowerCase(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validNumberInput() {
    if (cin.fail()) {
        clearInput();
        return false;
    }
    return true;
}

struct Pelanggan {
    string nama;
    string barang;
    int totalBayar;
    string metodePembayaran;
    Pelanggan* next;
};

struct QueueAntrian {
    Pelanggan* front = nullptr;
    Pelanggan* rear = nullptr;
    int size = 0;

    void enqueue(string nama, string barang, int total, string metode) {
        Pelanggan* baru = new Pelanggan{nama, barang, total, metode, nullptr};

        if (rear == nullptr) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }
        size++;
    }

    Pelanggan dequeue() {
        if (front == nullptr) return {"", "", 0, "", nullptr};

        Pelanggan* temp = front;
        Pelanggan dataKembali = *temp;

        front = front->next;
        if (front == nullptr) rear = nullptr;

        delete temp;
        size--;

        return dataKembali;
    }

    bool empty() {
        return front == nullptr;
    }

    void tampilkanAntrian() {
        if (front == nullptr) {
            cout << "\n[!] Antrian kosong.\n";
            return;
        }

        Pelanggan* current = front;
        int nomor = 1;

        cout << "\n===== ANTRIAN CHECKOUT SAAT INI =====\n";
        while (current != nullptr) {
            cout << nomor++ << ". "
                 << current->nama
                 << " | " << current->barang
                 << " | Rp" << current->totalBayar
                 << " | " << current->metodePembayaran
                 << endl;
            current = current->next;
        }
    }

    void urutkanAntrianSultan() {
        if (front == nullptr || front->next == nullptr) {
            cout << "\nAntrian terlalu sedikit untuk diurutkan.\n";
            return;
        }

        int n = size;
        Pelanggan* arr = new Pelanggan[n];

        Pelanggan* current = front;
        int i = 0;
        while (current != nullptr) {
            arr[i++] = *current;
            current = current->next;
        }

        for (int x = 0; x < n - 1; x++) {
            for (int y = 0; y < n - x - 1; y++) {
                if (arr[y].totalBayar < arr[y + 1].totalBayar) {
                    swap(arr[y], arr[y + 1]);
                }
            }
        }

        cout << "\n===== PRIORITAS SULTAN (SORTED VIEW) =====\n";
        for (int j = 0; j < n; j++) {
            cout << j + 1 << ". "
                 << arr[j].nama
                 << " | " << arr[j].barang
                 << " | Rp" << arr[j].totalBayar
                 << endl;
        }

        delete[] arr;
    }

    void cleanup() {
        while (!empty()) {
            dequeue();
        }
    }
};

struct StackCancel {
    Pelanggan* top = nullptr;

    void push(Pelanggan p) {
        Pelanggan* baru = new Pelanggan{
            p.nama,
            p.barang,
            p.totalBayar,
            p.metodePembayaran,
            top
        };
        top = baru;
    }

    Pelanggan pop() {
        if (top == nullptr) return {"", "", 0, "", nullptr};

        Pelanggan* temp = top;
        Pelanggan dataKembali = *temp;

        top = top->next;
        delete temp;

        return dataKembali;
    }

    bool empty() {
        return top == nullptr;
    }

    void cleanup() {
        while (!empty()) {
            pop();
        }
    }
};

struct TreeNode {
    int rating;
    string ulasan;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

void tambahReview(TreeNode*& root, int rat, string ulas) {
    if (root == nullptr) {
        root = new TreeNode{rat, ulas, nullptr, nullptr};
    } else if (rat < root->rating) {
        tambahReview(root->left, rat, ulas);
    } else {
        tambahReview(root->right, rat, ulas);
    }
}

void tampilkanReview(TreeNode* root) {
    if (root != nullptr) {
        tampilkanReview(root->left);
        cout << "[Bintang " << root->rating << "/5] : "
             << root->ulasan << endl;
        tampilkanReview(root->right);
    }
}

int hitungJumlahReview(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + hitungJumlahReview(root->left) + hitungJumlahReview(root->right);
}

int hitungTotalRating(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->rating
         + hitungTotalRating(root->left)
         + hitungTotalRating(root->right);
}

void tampilkanStatistikReview(TreeNode* root) {
    int jumlah = hitungJumlahReview(root);

    if (jumlah == 0) {
        cout << "\nBelum ada review.\n";
        return;
    }

    int total = hitungTotalRating(root);
    double rata = (double) total / jumlah;

    cout << "\n===== STATISTIK REVIEW =====\n";
    cout << "Jumlah Review : " << jumlah << endl;
    cout << "Rata-rata     : " << rata << "/5" << endl;
}

void hapusTree(TreeNode*& root) {
    if (root == nullptr) return;

    hapusTree(root->left);
    hapusTree(root->right);

    delete root;
    root = nullptr;
}

struct GraphOngkir {
    string kota[4] = {
        "Jakarta",
        "Bandung",
        "Surabaya",
        "Yogyakarta"
    };

    int biaya[4][4] = {
        {0,     15000, 45000, 30000},
        {15000, 0,     35000, 20000},
        {45000, 35000, 0,     25000},
        {30000, 20000, 25000, 0}
    };

    void cekOngkir() {
        cout << "\n===== MATRIKS ONGKIR =====\n";

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    cout << kota[i]
                         << " -> "
                         << kota[j]
                         << " = Rp"
                         << biaya[i][j]
                         << endl;
                }
            }
        }
    }

    void cekRuteInteraktif() {
        int asal, tujuan;

        cout << "\n===== CEK ONGKIR ANTAR KOTA =====\n";
        cout << "Daftar Kota:\n";

        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << kota[i] << endl;
        }

        cout << "\nPilih Kota Asal (1-4): ";
        cin >> asal;

        if (!validNumberInput()) {
            cout << "\nInput tidak valid.\n";
            return;
        }

        cout << "Pilih Kota Tujuan (1-4): ";
        cin >> tujuan;

        if (!validNumberInput()) {
            cout << "\nInput tidak valid.\n";
            return;
        }

        asal--;
        tujuan--;

        if (asal < 0 || asal >= 4 || tujuan < 0 || tujuan >= 4) {
            cout << "\n[!] Pilihan kota tidak valid.\n";
            return;
        }

        if (asal == tujuan) {
            cout << "\nAsal dan tujuan sama. Ongkir = Rp0\n";
            return;
        }

        cout << "\n===== RUTE PENGIRIMAN =====\n";
        cout << kota[asal] << " -> " << kota[tujuan] << endl;
        cout << "Total Ongkir: Rp" << biaya[asal][tujuan] << endl;
    }
};

int main() {
    QueueAntrian antrianBelanja;
    StackCancel riwayatSelesai;
    TreeNode* rootReview = nullptr;
    GraphOngkir petaKurir;

    string katalog[4] = {
        "Laptop Game",
        "Mouse Wireless",
        "Keyboard Mechanical",
        "Monitor 4K"
    };

    int harga[4] = {
        15000000,
        400000,
        800000,
        3500000
    };

    int pilihan;

    do {
        cout << "\n=================================================\n";
        cout << "   SUPER E-COMMERCE INTEGRATED STRUCTURE SYSTEM\n";
        cout << "=================================================\n";
        cout << "1. Cari & Lihat Produk \n";
        cout << "2. Tambah Pelanggan ke Antrian \n";
        cout << "3. Urutkan Antrian Prioritas Sultan \n";
        cout << "4. Proses Antrian Berikutnya / Pembayaran \n";
        cout << "5. Batalkan Transaksi Terakhir \n";
        cout << "6. Lihat Peta Tarif Ongkir Logistik \n";
        cout << "7. Menu Ulasan / Review Toko \n";
        cout << "8. Lihat Antrian Saat Ini\n";
        cout << "9. Keluar Aplikasi\n";
        cout << "Pilih menu (1-9): ";

        cin >> pilihan;

        if (!validNumberInput()) {
            cout << "\nInput harus berupa angka.\n";
            continue;
        }

        cin.ignore();

        switch (pilihan) {

        case 1: {
            string cari;
            string cariLower;

            cout << "\n--- Katalog Toko ---\n";
            for (int i = 0; i < 4; i++) {
                cout << "- " << katalog[i]
                     << " (Rp" << harga[i] << ")\n";
            }

            cout << "\nMasukkan nama produk yang dicari: ";
            getline(cin, cari);
            cariLower = toLowerCase(cari);

            bool ketemu = false;

            for (int i = 0; i < 4; i++) {
                string produk = toLowerCase(katalog[i]);

                if (produk.find(cariLower) != string::npos) {
                    cout << "[Ketemu!] Produk "
                         << katalog[i]
                         << " tersedia dengan harga Rp"
                         << harga[i]
                         << endl;
                    ketemu = true;
                }
            }

            if (!ketemu) {
                cout << "[!] Produk tidak ditemukan.\n";
            }

            break;
        }

        case 2: {
            string nama, barang, metode;
            int total, opsiBayar;

            cout << "\nMasukkan Nama Pelanggan: ";
            getline(cin, nama);

            cout << "Masukkan Nama Barang   : ";
            getline(cin, barang);

            cout << "Masukkan Total Harga   : Rp";
            cin >> total;

            if (!validNumberInput()) {
                cout << "\nInput total tidak valid.\n";
                break;
            }

            cout << "\nPilih Metode Pembayaran:\n";
            cout << "1. Transfer Bank\n";
            cout << "2. E-Wallet\n";
            cout << "3. COD\n";
            cout << "Pilihan: ";

            cin >> opsiBayar;

            if (!validNumberInput()) {
                cout << "\nInput metode tidak valid.\n";
                break;
            }

            cin.ignore();

            metode = (opsiBayar == 1) ? "Transfer Bank" :
                     (opsiBayar == 2) ? "E-Wallet" :
                     "COD";

            antrianBelanja.enqueue(nama, barang, total, metode);

            cout << "-> " << nama
                 << " masuk ke antrian checkout.\n";
            break;
        }

        case 3:
            antrianBelanja.urutkanAntrianSultan();
            break;

        case 4: {
            if (!antrianBelanja.empty()) {
                Pelanggan pSelesai = antrianBelanja.dequeue();

                cout << "\n--- Memproses Pembayaran ---\n";
                cout << "Nama Pelanggan    : " << pSelesai.nama << endl;
                cout << "Barang Belanja    : " << pSelesai.barang << endl;
                cout << "Total Bayar       : Rp" << pSelesai.totalBayar << endl;
                cout << "Metode Pembayaran : " << pSelesai.metodePembayaran << endl;
                cout << "Status            : BERHASIL LUNAS!\n";

                riwayatSelesai.push(pSelesai);
            } else {
                cout << "\n[!] Antrian kosong.\n";
            }
            break;
        }

        case 5: {
            if (!riwayatSelesai.empty()) {
                Pelanggan ditarik = riwayatSelesai.pop();

                cout << "\n[Undo Sukses] Transaksi atas nama "
                     << ditarik.nama
                     << " senilai Rp"
                     << ditarik.totalBayar
                     << " dibatalkan & di-refund!\n";

                antrianBelanja.enqueue(
                    ditarik.nama,
                    ditarik.barang,
                    ditarik.totalBayar,
                    ditarik.metodePembayaran
                );
            } else {
                cout << "\n[!] Tidak ada transaksi untuk dibatalkan.\n";
            }
            break;
        }

        case 6: {
            int menuGraph;

            cout << "\n1. Lihat Semua Tarif Ongkir\n";
            cout << "2. Cek Ongkir Antar Kota\n";
            cout << "Pilihan: ";
            cin >> menuGraph;

            if (!validNumberInput()) {
                cout << "\nInput tidak valid.\n";
                break;
            }

            if (menuGraph == 1) {
                petaKurir.cekOngkir();
            } else if (menuGraph == 2) {
                petaKurir.cekRuteInteraktif();
            } else {
                cout << "\nPilihan tidak valid.\n";
            }

            break;
        }

        case 7: {
            int menuTree;

            cout << "\n1. Tulis Review Baru\n";
            cout << "2. Lihat Semua Review\n";
            cout << "3. Statistik Review\n";
            cout << "Pilihan: ";
            cin >> menuTree;

            if (!validNumberInput()) {
                cout << "\nInput tidak valid.\n";
                break;
            }

            cin.ignore();

            if (menuTree == 1) {
                int r;
                string u;

                cout << "Masukkan Rating (1-5): ";
                cin >> r;

                if (!validNumberInput()) {
                    cout << "\nInput rating tidak valid.\n";
                    break;
                }

                cin.ignore();

                if (r < 1 || r > 5) {
                    cout << "Rating harus 1-5.\n";
                    break;
                }

                cout << "Tulis Ulasan: ";
                getline(cin, u);

                tambahReview(rootReview, r, u);
                cout << "-> Review disimpan ke Tree.\n";

            } else if (menuTree == 2) {
                cout << "\n--- REVIEW TOKO (BST Inorder) ---\n";
                tampilkanReview(rootReview);

            } else if (menuTree == 3) {
                tampilkanStatistikReview(rootReview);

            } else {
                cout << "\nPilihan tidak valid.\n";
            }

            break;
        }

        case 8:
            antrianBelanja.tampilkanAntrian();
            break;

        case 9:
            cout << "\nKeluar program. Terima kasih!\n";
            break;

        default:
            cout << "\nPilihan salah!\n";
        }

    } while (pilihan != 9);

    antrianBelanja.cleanup();
    riwayatSelesai.cleanup();
    hapusTree(rootReview);

    return 0;
}