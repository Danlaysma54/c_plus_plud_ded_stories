#include "Box.h"

struct Data {
    BoxSpace::Box box;
    int volume;

    Data() {
        volume = 0;
    }
};