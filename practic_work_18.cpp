#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct Vector {
    int* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    size_t get_quantity() {
        return size;
    }

    size_t get_quantity_buffer() {
        return capacity;
    }

    int& get_index(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Array out of bounds!");
        }
        return data[index];
    }

    int& at(size_t index) {
        return get_index(index);
    }

    void delete_index(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Array out of bounds!");
        }
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void add_index(size_t index, int value) {
        if (index > size) {
            throw std::out_of_range("Array out of bounds!");
        }
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newData = new int[capacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        for (size_t i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void add_element_end(int value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newData = new int[capacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
};

void menu(Vector& vec) {
    int a = -1;
    while (a != 0) {
        std::cout 
        << "\n__MENUSHKA__"  
        << "\n 1 - Adding elements to the end" 
        << "\n 2 - Adding elements by index"
        << "\n 3 - Removing elements by index"
        << "\n 4 - Getting element by index"
        << "\n 5 - Getting number of elements present"
        << "\n 6 - Getting number of elements in buffer"
        << "\n 0 - Exit"
        << "\n> ";

        std::cin >> a;

        switch (a) {
            case 1: {
                int val;
                std::cout << "Value: ";
                std::cin >> val;
                vec.add_element_end(val);
                break;
            }
            case 2: {
                size_t idx;
                int val;
                std::cout << "Index and Value: ";
                std::cin >> idx >> val;
                try { 
                    vec.add_index(idx, val); 
                } catch(const std::exception& e) { 
                    std::cerr << e.what() << '\n'; 
                }
                break;
            }
            case 3: {
                size_t idx;
                std::cout << "Index: ";
                std::cin >> idx;
                try { 
                    vec.delete_index(idx); 
                } catch(const std::exception& e) { 
                    std::cerr << e.what() << '\n'; 
                }
                break;
            }
            case 4: {
                size_t idx;
                std::cout << "Index: ";
                std::cin >> idx;
                try { 
                    std::cout << "Element: " << vec.get_index(idx) << '\n'; 
                } catch(const std::exception& e) { 
                    std::cerr << e.what() << '\n'; 
                }
                break;
            }
            case 5: {
                std::cout << "Quantity: " << vec.get_quantity() << '\n';
                break;
            }
            case 6: {
                std::cout << "Buffer: " << vec.get_quantity_buffer() << '\n';
                break;
            }
            case 0:
                break;
            default:
                std::cerr << "Error\n";
        }
    }
}

int main() {
    Vector vec;
    
    menu(vec);
    
    std::cout << "\nElement of vector: ";
    for (size_t i = 0; i < vec.size; ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\nSize: " << vec.size << "\nCapacity: " << vec.capacity << std::endl;

    return 0;
}