#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    public:
        Rectangle(int x, int y, int h, int w);
        ~Rectangle();
        int GetHeight();
        int GetWidth();
        bool operator==(const Rectangle &r);


    private:
        int xLow, yLow, height, width;

    
};


#endif // RECTANGLE_H
