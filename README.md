# E-Commerce Shopping
## Deskripsi

Sistem E-Commerce Shopping merupakan aplikasi berbasis Command Line Interface (CLI) yang dikembangkan menggunakan bahasa C++. Program ini mensimulasikan proses operasional sebuah toko online dengan mengintegrasikan berbagai struktur data dan algoritma dalam satu aplikasi.

Fitur utama yang tersedia meliputi:

- Pencarian produk
- Manajemen antrian pelanggan
- Prioritas pelanggan berdasarkan total transaksi
- Proses pembayaran
- Pembatalan transaksi (Undo)
- Perhitungan ongkos kirim
- Sistem review pelanggan
- Statistik review
Aplikasi ini dikembangkan sebagai implementasi materi Struktur Data, dengan menerapkan konsep Queue, Stack, Binary Search Tree (BST), Graph, dan Array untuk menyelesaikan berbagai kebutuhan sistem secara efisien.
---

# Struktur Data yang Digunakan

1. Queue
   - Mengelola antrian checkout pelanggan.

2. Stack
   - Menyimpan riwayat transaksi untuk fitur pembatalan (Undo).

3. Binary Search Tree (BST)
   - Menyimpan data review pelanggan berdasarkan rating.

4. Graph (Adjacency Matrix)
   - Menyimpan informasi ongkos kirim antar kota.

5. Array
   - Menyimpan daftar produk dan harga.

---

# Struktur Direktori

```
.
├── src/
│   └── E_Commerce.cpp
├── README.md
└── (file pendukung lainnya)
```

Apabila seluruh source code berada pada satu file, struktur direktori dapat menjadi:

```
.
├── E_Commerce.cpp
└── README.md
```

---

# Branch Repository

Repository ini menggunakan branch utama `main` sebagai branch produksi/stabil.

---

# Prasyarat

Sebelum menjalankan program, pastikan telah menginstal salah satu environment berikut:

Untuk VS Code:
- Visual Studio Code
- Compiler C++ (GCC/G++ atau MinGW-w64 pada Windows)
- Terminal / Command Prompt

Untuk Dev-C++:
- Dev-C++ (compiler sudah terintegrasi)

---

# Cara Kompilasi

Menggunakan VS Code:
1. g++ E_Commerce.cpp -o ecommerce
2. ./ecommerce

Menggunakan Dev-C++:
1. Buka file E_Commerce.cpp
2. Klik Compile & Run (F11)



---

# Cara Menjalankan Program

Windows (Command Prompt / PowerShell)

```bash
ecommerce.exe
```


Linux / macOS jika program kompatibel

```bash
./ecommerce
```
Catatan:
Jika menggunakan Dev-C++, program dapat langsung dijalankan melalui tombol Compile & Run (F11) tanpa perlu menjalankan perintah manual di terminal.

---

# Menu Program

Program menyediakan beberapa menu utama:

1.Cari & Lihat Produk
2.Tambah Pelanggan ke Antrian
3.Urutkan Antrian Prioritas Sultan
4.Proses Antrian Berikutnya / Pembayaran
5.Batalkan Transaksi Terakhir
6.Lihat Peta Tarif Ongkir Logistik
7.Menu Ulasan / Review Toko
8.Lihat Antrian Saat Ini
9.Keluar

---

# Implementasi Struktur Data

| Struktur Data | Implementasi |
|--------------|--------------|
| Queue | Antrian Checkout |
| Stack | Undo Pembayaran |
| Binary Search Tree | Penyimpanan Review |
| Graph | Ongkos Kirim Antar Kota |
| Array | Data Produk |

---

# Anggota Kelompok

- Alia Cintia Anjjali - 2025130047
- Dela Salsabila - 20251320046
- Hesti Julia Rohmah - 2025130067
- Marsya Wulandari - 20251320054

---

# Repository

GitHub Repository: E-Commerce Repository

---
# Status Repository
Public (dapat diakses oleh siapa saja)

---

# Lisensi

Project ini dibuat untuk keperluan pembelajaran dan penyelesaian tugas mata kuliah Struktur Data. Seluruh kode dan dokumentasi dalam repository ini digunakan untuk tujuan akademik.
