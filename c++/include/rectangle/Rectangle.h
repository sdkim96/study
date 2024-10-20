#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class Rectangle {
    public:
        Rectangle(int x, int y, int h, int w, std::string c);
        ~Rectangle();
        int GetHeight();
        int GetWidth();
        //넓이를 계산하는 함수
        int getArea();
        //둘레를 계산하는 함수
        int getPerimeter();
        std::string getColor();
        bool operator==(const Rectangle &r);
        bool operator<(const Rectangle &s);
        friend std::ostream& operator<<(std::ostream& os, const Rectangle &r);

    private:
        int xLow, yLow, height, width;
        std::string color;

    
};


#endif // RECTANGLE_H
