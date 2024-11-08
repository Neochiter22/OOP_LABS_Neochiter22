#include <iostream>
#include "include/Square.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/ShapeArray.h"

int main() {
    ShapeArray shapeArray;

    std::cout << "\nInput Square:" << std::endl;
    Square* square = new Square;
    std::cin >> *square;
    shapeArray.add_shape(square);
    std::cout << *square;
    square->get_center();
    std::cout << "  Square S: " << (double)(*square) << std::endl;

    std::cout << "\nInput Rectangle:" << std::endl;
    Rectangle* rectangle = new Rectangle;
    std::cin >> *rectangle;
    shapeArray.add_shape(rectangle);
    std::cout << *rectangle;
    rectangle->get_center();
    std::cout << "  Rectangle S: " << (double)(*rectangle) << std::endl;

    std::cout << "\nInput Trapezoid:" << std::endl;
    Trapezoid* trapezoid = new Trapezoid;
    std::cin >> *trapezoid;
    shapeArray.add_shape(trapezoid);
    std::cout << *trapezoid;
    trapezoid->get_center();
    std::cout << "  Trapezoid S: " << (double)(*trapezoid) << std::endl;

    std::cout << "\nAll Shapes:\n";
    shapeArray.print_shapes();
    std::cout << "Total S of all shapes: " << shapeArray.totalArea() << std::endl;

    std::cout << "Removing index 0." << std::endl;
    shapeArray.removeShape(0);

    std::cout << "\nRemaining Shapes:\n";
    shapeArray.print_shapes();
    std::cout << "Total S of remaining shapes: " << shapeArray.totalArea() << std::endl;

    return 0;
}