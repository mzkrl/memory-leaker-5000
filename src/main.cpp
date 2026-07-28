#include <iostream>

int main() {
    std::cout << "cout.\n";
    std::cout << "Hello, World!\n";
    
    // Alokasi memori dinamis sederhana
    int* ptr = new int(42);
    std::cout << "[INFO] Data di memori heap: " << *ptr << "\n";
    std::cout << "[INFO] Alamat memori heap: " << ptr << "\n";
    
    // Cegah memory leak
    delete ptr;
    
    return 0;
}
