#ifndef IDZ2_SEM4_DYNAMICARRAYINT_H
#define IDZ2_SEM4_DYNAMICARRAYINT_H

#include "MyCustomException.h"
#include <iostream>

class DynamicArray {
private:
    int *arr;
    int size;
    int buff;
public:
    DynamicArray() {
        size = 10;
        arr = new int[size];
        buff = 0;
    }

    DynamicArray(int input_size) {
        size = input_size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        buff = 0;
    }

    DynamicArray(int input_size, int n) {
        size = input_size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
        buff = 0;
    }

    DynamicArray(int input_size, int n, int capacity) {
        buff = capacity;
        size = input_size;
        arr = new int[size + buff];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }

    DynamicArray(const DynamicArray &a) {
        buff = a.buff;
        size = a.size;
        arr = new int[a.size + a.buff];
        for (int i = 0; i < a.size; i++)
            arr[i] = a.arr[i];
    }

    DynamicArray(DynamicArray &&a) {
        buff = a.buff;
        arr = a.arr;
        size = a.size;
        a.arr = nullptr;
        a.size = 0;
        a.buff = 0;
    }

    ~DynamicArray() {
        delete[]arr;
    }

    int GetSize() {
        return size;
    }

    void SetSize(int x) {
        size = x;
    }

    int *GetArray() {
        return arr;
    }

    int &operator[](const int index) {
        MyCustomException error;
        if (index < 0 || index >= size)
            throw std::exception(error);
        return arr[index];
    }

    void reSize(int input_size) {
        buff = 0;
        DynamicArray dynamicArray = DynamicArray(input_size);
        for (int i = 0; i < input_size; i++) {
            if (i < size) {
                dynamicArray.arr[i] = arr[i];
            } else {
                dynamicArray.arr[i] = 0;
            }
        }
        delete[]arr;
        size = input_size;
        arr = new int[input_size];
        for (int i = 0; i < input_size; i++) {
            if (i < size) {
                arr[i] = dynamicArray.arr[i];

            }
        }
    }

    DynamicArray &operator=(const DynamicArray &obj) {
        if (this == &obj) { return *this; }
        DynamicArray copy(obj);
        std::swap(arr, copy.arr);
        std::swap(size, copy.size);
        return *this;
    }

    DynamicArray &operator=(DynamicArray &&obj) {
        if (this == &obj) { return *this; }
        std::swap(arr, obj.arr);
        std::swap(size, obj.size);
        return *this;
    }

    bool operator==(const DynamicArray &obj) {
        MyCustomException error;
        if (obj.size == size) {
            for (int i = 0; i < size; i++) {
                if (arr[i] != obj.arr[i]) {
                    return false;
                }
            }
            return true;
        } else {
            throw std::exception(error);
        }
    }

    bool operator!=(const DynamicArray &obj) {
        MyCustomException error;
        if (obj.size == size) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == obj.arr[i]) {
                    return false;
                }
            }
            return true;
        } else {
            throw std::exception(error);
        }
    }

    bool operator>(const DynamicArray &obj) {
        if (size > obj.size) {
            for (int i = 0; i < obj.size; i++) {
                if (obj.arr[i] >= arr[i])
                    return false;
            }
            return true;
        } else {
            for (int i = 0; i < size; i++) {
                if (obj.arr[i] >= arr[i])
                    return false;
            }
            return true;
        }
    }

    bool operator>=(const DynamicArray &obj) {
        if (size > obj.size) {
            for (int i = 0; i < obj.size; i++) {
                if (obj.arr[i] > arr[i])
                    return false;
            }
            return true;
        } else {
            for (int i = 0; i < size; i++) {
                if (obj.arr[i] > arr[i])
                    return false;
            }
            return true;
        }
    }

    bool operator<(const DynamicArray &obj) {
        if (size > obj.size) {
            for (int i = 0; i < obj.size; i++) {
                if (obj.arr[i] <= arr[i])
                    return false;
            }
            return true;
        } else {
            for (int i = 0; i < size; i++) {
                if (obj.arr[i] <= arr[i])
                    return false;
            }
            return true;
        }
    }

    bool operator<=(const DynamicArray &obj) {
        if (size > obj.size) {
            for (int i = 0; i < obj.size; i++) {
                if (obj.arr[i] < arr[i])
                    return false;
            }
            return true;
        } else {
            for (int i = 0; i < size; i++) {
                if (obj.arr[i] < arr[i])
                    return false;
            }
            return true;
        }
    }

    friend DynamicArray operator+(DynamicArray &obj1, DynamicArray &obj2) {
        int t = 0;
        DynamicArray dynamicArray;
        dynamicArray.SetSize(obj1.GetSize() + obj2.GetSize());
        for (int i = 0; i < obj1.GetSize(); i++) {
            dynamicArray.GetArray()[i] = obj1.GetArray()[i];
        }
        for (int i = obj1.GetSize(); i < obj1.GetSize() + obj2.GetSize(); i++) {
            dynamicArray.GetArray()[i] = obj2.GetArray()[t];
            t++;
        }
        return dynamicArray;
    }

    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &dynamicArray) {
        {
            os << "size: " << dynamicArray.size << " " << "buff size: " << dynamicArray.buff << std::endl;
            for (int i = 0; i < dynamicArray.size; i++) {
                os << dynamicArray.arr[i] << "\n";
            }
            return os;
        }
    }

    friend std::istream &operator>>(std::istream &in, DynamicArray &dynamicArray) {
        int inp_size;
        int numb = 0;
        std::cout << "write size\n";
        std::cin >> dynamicArray.size;
        std::cout << "write buff\n";
        std::cin >> dynamicArray.buff;
        delete[]dynamicArray.arr;
        dynamicArray.arr = new int[dynamicArray.size + dynamicArray.buff];
        for (int i = 0; i < dynamicArray.size; i++) {
            in >> numb;
            dynamicArray[i] = numb;
        }
        return in;
    }

    void reserve(int n) {
        buff = n;
        DynamicArray copy;
        delete copy.arr;
        copy.arr = new int[size];
        copy.size = size;
        for (int i = 0; i < size; i++) {
            copy.arr[i] = arr[i];
        }
        delete[]arr;
        arr = new int[n + size];
        for (int i = 0; i < size; i++) {
            arr[i] = copy.arr[i];
        }
    }

    int capacity() {
        return buff;
    }

    void pushback(int x) {
        if (buff == 0) {
            this->reSize(size * 2);
        }
        size += 1;
        arr[size - 1] = x;
        buff--;
    }

    void popBack() {
        MyCustomException error;
        if (size == 0) {
            throw std::exception(error);
        }
        size -= 1;
        buff++;
    }
};


#endif //IDZ2_SEM4_DYNAMICARRAYINT_H
