#include "Box.h"
#include "MyCustomException.h"
#include <vector>

using namespace BoxSpace;
namespace ContainerSpace {
    class Container {
    private:
        std::vector<Box> boxes;
        int length;
        int width;
        int height;
        double weight;
    public:
        Container(int input_length, int input_width, int input_height, double input_weight,
                  std::vector<Box> input_boxes) {
            length = input_length;
            width = input_width;
            height = input_height;
            weight = input_height;
            boxes = input_boxes;
        }

        std::vector<Box> GetBoxes() {
            return boxes;
        }

        void AddBoxByIndex(Box box, int index) {
            boxes.insert(boxes.begin() + index, box);
        }

        void DeleteBoxByIndex(int index) {
            boxes.erase(boxes.begin() + index);
        }

        int NumbOfBoxes() {
            return boxes.size();
        }

        double AllBoxesWeight() {
            double all_weight = 0;
            for (int i = 0; i < boxes.size(); i++) {
                all_weight += boxes.at(i).GetWeight();
            }
            return all_weight;
        }

        int AllBoxesValue() {
            int all_value = 0;
            for (int i = 0; i < boxes.size(); i++) {
                all_value += boxes.at(i).GetValue();
            }
            return all_value;
        }

        Box GetBox(int index) {
            return boxes[index];
        }

        int AddLastBox(Box box) {
            int sum_height = 0;
            int sum_width = 0;
            int sum_length = 0;
            MyCustomException myCustomException;
            if (AllBoxesWeight() + box.GetWeight() > weight) {

                std::cout << myCustomException.what();
            }
            for (int i = 0; i < boxes.size(); i++) {
                sum_height += boxes[i].GetHeight();
                sum_length += boxes[i].GetLength();
                sum_width += boxes[i].GetWidth();
            }
            if (sum_width + box.GetWidth() > width || sum_length + box.GetLength() > length ||
                sum_height + box.GetHeight() > height) {
                std::cout << myCustomException.what_size();
            }
            boxes.push_back(box);
            return boxes.size();
        }

        friend std::ostream &operator<<(std::ostream &os, const Container &container) {
            {
                os << container.length << " " << container.height << " " << container.width << " " << container.weight
                   << "\n";
                for (int i = 0; i < container.boxes.size(); i++) {
                    os << container.boxes[i] << "\n";
                }
                return os;
            }
        }

        friend std::istream &operator>>(std::istream &in, Container &container) {
            int size;
            in >> container.length >> container.width >> container.height >> container.weight;
            std::cin >> size;
            container.boxes.clear();
            container.boxes[size];
            for (int i = 0; i < size; i++) {
                in >> container.boxes[i];
                container.boxes.push_back(container.boxes[i]);
            }
            return in;
        }

        Box &operator[](const int index) {
            return boxes[index];
        }
    };
}