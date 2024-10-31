#include <iostream>
#include "CImg.h"

using namespace cimg_library;

int main() {
	setlocale(LC_ALL, "Russian");
    CImg<unsigned char> image(800, 600, 1, 3, 255);
    const unsigned char black_color[] = {0, 0, 0}; 
    for (int x = 0; x < image.width(); x += 10) {
        image.draw_line(x, 0, x, image.height() - 1,black_color);
    }
    for (int y = 0; y < image.height(); y += 10) {
        image.draw_line(0, y, image.width() + 1, y, black_color);
    }
    CImgDisplay display(image, "Координатная сетка");
    while (!display.is_closed()) {
        if (display.button()) {
            int x = display.mouse_x();
            int y = display.mouse_y();
            std::cout << "Координаты: x = " << x << ", y = " << y << std::endl;
        }
        display.wait();
    }
    return 0;
}



