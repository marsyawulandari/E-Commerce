# Sistem E-Commerce Integrated Structure System

## Deskripsi

Sistem E-Commerce Integrated Structure System merupakan aplikasi berbasis Command Line Interface (CLI) yang dibuat menggunakan bahasa C++. Program ini mensimulasikan proses transaksi pada sebuah toko online dengan mengimplementasikan berbagai struktur data dalam satu aplikasi.

Fitur utama yang tersedia antara lain:

- Pencarian produk
- Manajemen antrian pelanggan
- Prioritas pelanggan berdasarkan total transaksi
- Pembayaran transaksi
- Pembatalan transaksi (Undo)
- Perhitungan ongkos kirim
- Sistem review pelanggan
- Statistik review

Program ini dikembangkan sebagai implementasi materi Struktur Data.

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
│   └── main.cpp
├── README.md
└── (file pendukung lainnya)
```

Apabila seluruh source code berada pada satu file, struktur direktori dapat menjadi:

```
.
├── main.cpp
└── README.md
```

---

# Branch Repository

Repository menggunakan branch utama:

```
main
```

---

# Prasyarat

Sebelum menjalankan program, pastikan telah menginstal:

- GCC / G++
- MinGW (Windows)
- Terminal / Command Prompt

Cek versi compiler:

```bash
g++ --version
```

---

# Cara Kompilasi

Masuk ke folder project kemudian jalankan:

```bash
g++ main.cpp -o ecommerce
```

Apabila source code berada pada folder src:

```bash
g++ src/main.cpp -o ecommerce
```

---

# Cara Menjalankan Program

Windows

```bash
ecommerce.exe
```

atau

```bash
./ecommerce.exe
```

Linux / macOS

```bash
./ecommerce
```

---

# Menu Program

Program menyediakan beberapa menu utama:

1. Cari Produk
2. Tambah Pelanggan ke Antrian
3. Urutkan Prioritas Pelanggan
4. Proses Pembayaran
5. Batalkan Transaksi
6. Lihat Ongkos Kirim
7. Review Toko
8. Lihat Antrian
9. Keluar

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

- Nama Anggota 1
- Nama Anggota 2
- Nama Anggota 3

---

# Repository

Repository GitHub:

```
https://github.com/username/nama-repository
```

Ganti URL di atas sesuai repository GitHub yang digunakan.

---

# Lisensi

Repository ini dibuat untuk keperluan pembelajaran dan tugas mata kuliah Struktur Data.
