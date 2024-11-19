#include <iostream>
#include "include/Square.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/Array.h"

int main() {
    Array<Figure<double>> figures;

    std::cout << "\nInput Square:\n";
    Point<double> bottom_left;
    double side_length;
    std::cout << "Enter the bottom-left point and side length: (0 0 5)\n";
    std::cin >> bottom_left >> side_length;
    figures.push_back(std::make_shared<Square<double>>(bottom_left, side_length));

    std::cout << "\nInput Rectangle:\n";
    Point<double> rect_bottom_left;
    double width, height;
    std::cout << "Enter the bottom-left point width and height: (10 20 4 5)\n";
    std::cin >> rect_bottom_left >> width >> height;
    figures.push_back(std::make_shared<Rectangle<double>>(rect_bottom_left, width, height));

    std::cout << "\nInput Trapezoid:\n";
    Point<double> v1, v2, v3, v4;
    std::cout << "Enter the coordinates of four Points: (as in previous cases, 4 points)\n";
    std::cin >> v1 >> v2 >> v3 >> v4;
    figures.push_back(std::make_shared<Trapezoid<double>>(v1, v2, v3, v4));
    
    std::cout << "\nAll Shapes:\n" << std::endl;
    figures.print_all();
    std::cout << "S: " << figures.total_S() << std::endl;

    int index_remove;
    std::cout << "\nEnter the number by index to delete the shape: " << std::endl;
    std::cin >> index_remove;
    figures.remove(index_remove);
    std::cout << "\nDeleting by index " << index_remove << " of figure number: " << index_remove + 1 << std::endl;

    std::cout << "\nRemaining figures:" << std::endl;
    figures.print_all();
    std::cout << "S of remaining shapes: " << figures.total_S() << std::endl;

    return 0;
}