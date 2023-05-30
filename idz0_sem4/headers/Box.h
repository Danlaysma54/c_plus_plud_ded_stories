#pragma once

#include <iostream>
#include <istream>
#include <ostream>

namespace BoxSpace {
    class Box {
    private :
        int length;
        int width;
        int height;
        double weight;
        int value;
    public:
        Box(int length_input, int width_input, int height_input, double weight_input, int value_input) {
            length = length_input;
            width = width_input;
            height = height_input;
            weight = weight_input;
            value = value_input;
        }

        Box() {
            length = 0;
            width = 0;
            height = 0;
            weight = 0;
            value = 0;
        }

        int GetLength() {
            return length;
        }

        int GetWidth() {
            return width;
        }

        int GetHeight() {
            return height;
        }

        double GetWeight() {
            return weight;
        }

        int GetValue() {
            return value;
        }

        void SetLength(int input_length) {
            length = input_length;
        }

        void SetWidth(int input_width) {
            length = input_width;
        }

        friend std::ostream &operator<<(std::ostream &os, const Box &box) {
            {
                return os << box.length << " " << box.height << " " << box.width << " " << box.weight << " "
                          << box.value;
            }
        }

        friend std::istream &operator>>(std::istream &in, Box &box) {
            in >> box.length >> box.weight >> box.height >> box.width >> box.value;
            return in;
        }

    };
}


