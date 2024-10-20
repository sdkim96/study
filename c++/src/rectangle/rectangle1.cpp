#include <iostream>
#include "../../include/rectangle/Rectangle.h"

int main() {

    Rectangle r(1,2,3,4),s(5,6,3,4);
    Rectangle *p = &s;

    if (r.GetHeight() * r.GetWidth() > p->GetHeight() * p->GetWidth()) {
        std::cout << "r has a larger area than p" << std::endl;
    } else {
        std::cout << "p has a larger area than r" << std::endl;
    }

    r == s ? std::cout << "The rectangles are equal" << std::endl : std::cout << "The rectangles are not equal" << std::endl;

    return 0;
}
