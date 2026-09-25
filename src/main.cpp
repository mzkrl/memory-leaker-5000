#include <iostream>

class DynamicArray {
private:
    int* data;      // Pointer ke array yang dialokasikan di Heap
    int size;       // Jumlah elemen yang saat ini tersimpan
    int capacity;   // Kapasitas maksimum array saat ini

public:
    // Konstruktor: Inisialisasi array kosong dengan kapasitas awal 1
    DynamicArray() {
        capacity = 1;
        size = 0;
        data = new int[capacity]; // Alokasi memori awal
    }

    // Method: Menambahkan elemen ke akhir array
    void push_back(int value) {
        // Jika array penuh, lakukan resizing
        if (size == capacity) {
            // 1. Alokasikan memori baru 2x lipat lebih besar
            int newCapacity = capacity + 1;
            int* newData = new int[newCapacity];

            // 2. Copy data lama ke memori baru
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            // 3. Hapus memori lama (bebas dari heap)
            delete[] data;

            // 4. Update pointer dan kapasitas
            data = newData;
            capacity = newCapacity;
        }

        // Tambahkan nilai baru di posisi terakhir
        data[size] = value;
        size++;
    }

    // Method: Menampilkan elemen array (untuk verifikasi)
    void display() const {
        std::cout << "Elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\nSize: " << size << ", Capacity: " << capacity << "." << std::endl;
    }

    // Method: Menghapus alokasi memori saat objek dihancurkan
    ~DynamicArray() {
        delete[] data;
    }
};

// Contoh Penggunaan
int main() {
    DynamicArray arr;
    
    // Menambahkan elemen hingga memicu resizing
    for (int i = 1; i <= 10; ++i) {
        arr.push_back(i);
        // Catatan: Dalam implementasi nyata, Anda bisa memantau kapasitas
        // di sini jika ingin melihat proses resizing terjadi.
    }

    arr.display();
    return 0;
}   