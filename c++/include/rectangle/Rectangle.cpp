#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, int h, int w , std::string c) {
    xLow = x;
    yLow = y;
    height = h;
    width = w;
    color = c;

    std::cout << "This Rectangle has: " << xLow << " " << yLow << " " << height << " " << width << std::endl;
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

int Rectangle::getArea() {
    return height * width;
};

int Rectangle::getPerimeter() {
    return 2 * (height + width);
};

std::string Rectangle::getColor() {
    return color;
};

bool Rectangle::operator==(const Rectangle &r) {
    if (this == &r) return true;

    if (
        this->height == r.height && 
        this->width == r.width && 
        this->xLow == r.xLow && 
        this->yLow == r.yLow
    ) return true;

    return false;
}

bool Rectangle::operator<(const Rectangle &s) {
    if (this->height * this->width < s.height * s.width) return true;
    return false;
}

std::ostream& operator<<(std::ostream &os, const Rectangle &r) {
    os << "xLow: " << r.xLow << " yLow: " << r.yLow << " height: " << r.height << " width: " << r.width;
    return os;
}