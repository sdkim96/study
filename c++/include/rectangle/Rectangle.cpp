#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, int h, int w) {
    xLow = x;
    yLow = y;
    height = h;
    width = w;

    std::cout << "Rectangle constructor" << std::endl;
};

Rectangle::~Rectangle() {

    std::cout << "Rectangle destructor" << std::endl;

};

int Rectangle::GetHeight() {
    return height;
};

int Rectangle::GetWidth() {
    return width;
};

bool Rectangle::operator==(const Rectangle &r) {
    if (this->height == r.height && this->width == r.width) {
        return true;
    } else {
        return false;
    }
}