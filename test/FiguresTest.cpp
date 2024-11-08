#include <gtest/gtest.h>
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/ShapeArray.h"
#include <sstream>

TEST(SquareTest1, AreaCalculation) {
    Square square(0, 0, 4);
    ASSERT_DOUBLE_EQ(square.square(), 16); 
}

TEST(SquareTest3, CenterCalculation) {
    Square square(0, 0, 4);
    testing::internal::CaptureStdout();
    square.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Square center: (2, 2)\n");
}
TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 3, 1, 3);
    testing::internal::CaptureStdout();
    trapezoid.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Trapezoid center: (2, 1.5)\n");
}

TEST(TrapezoidTest, CopyAssignment) {
    Trapezoid trapezoid1(0, 0, 4, 0, 3, 3, 1, 3);
    Trapezoid trapezoid2 = trapezoid1;
    ASSERT_EQ(trapezoid1, trapezoid2);
}

TEST(TrapezoidTest, MoveAssignment) {
    Trapezoid trapezoid1(0, 0, 4, 0, 3, 3, 1, 3);
    Trapezoid trapezoid2 = std::move(trapezoid1);
    ASSERT_DOUBLE_EQ(trapezoid2.square(), 9);
}

TEST(TrapezoidTest, SquareCalculation) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 3, 1, 3);
    ASSERT_DOUBLE_EQ(trapezoid.square(), 9);
}

TEST(ShapeArrayTest1, AddShape) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    shapeArray.add_shape(square);
    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 16.0);
}

TEST(ShapeArrayTest2, RemoveShape) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    shapeArray.add_shape(square);
    shapeArray.removeShape(0);
    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 0.0);
}

TEST(ShapeArrayTest3, TotalArea) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    Rectangle* rectangle = new Rectangle(0, 0, 4, 6);

    shapeArray.add_shape(square);
    shapeArray.add_shape(rectangle);

    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 16.0 + 24.0);
}


TEST(ShapeArrayTest4, RemoveShapeByIndex) {
    ShapeArray shapeArray;
    Square* square1 = new Square(0, 0, 4);
    Rectangle* rectangle = new Rectangle(0, 0, 4, 6);
    Square* square2 = new Square(0, 0, 2);

    shapeArray.add_shape(square1);
    shapeArray.add_shape(rectangle);
    shapeArray.add_shape(square2);

    shapeArray.removeShape(1);

    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 16.0 + 4.0);
}

TEST(RectangleTest5, CenterCalculation) {
    Rectangle rectangle(0, 0, 4, 6);
    testing::internal::CaptureStdout();
    rectangle.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Rectangle center: (2, 3)\n");
}

TEST(RectangleTest1, SquareCalculation) {
    Rectangle rectangle(0, 0, 4, 6);
    ASSERT_DOUBLE_EQ(rectangle.square(), 24);
}

TEST(RectangleTest2, MoveAssignment) {
    Rectangle rectangle1(0, 0, 4, 6);
    Rectangle rectangle2 = std::move(rectangle1);
    ASSERT_DOUBLE_EQ(rectangle2.square(), 24);
}

TEST(SquareTest1, CenterCalculation) {
    Square square(0, 0, 4);
    testing::internal::CaptureStdout();
    square.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Square center: (2, 2)\n");
}

TEST(SquareTest3, CopyAssignment) {
    Square square1(0, 0, 4);
    Square square2 = square1;
    ASSERT_EQ(square1, square2);
}

TEST(SquareTest4, MoveAssignment) {
    Square square1(0, 0, 4);
    Square square2 = std::move(square1);
    ASSERT_DOUBLE_EQ(square2.square(), 16);
}

TEST(SquareTest5, CopyAssignment) {
    Square square1(0, 0, 4);
    Square square2 = square1;
    ASSERT_EQ(square1, square2);
}

TEST(SquareTest5, MoveAssignment) {
    Square square1(0, 0, 4);
    Square square2 = std::move(square1);
    ASSERT_DOUBLE_EQ(square2.square(), 16);
}

TEST(RectangleTest1, AreaCalculation) {
    Rectangle rectangle(0, 0, 4, 6);
    ASSERT_DOUBLE_EQ(rectangle.square(), 24);
}

TEST(RectangleTest2, CenterCalculation) {
    Rectangle rectangle(0, 0, 6, 2);
    testing::internal::CaptureStdout();
    rectangle.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Rectangle center: (3, 1)\n");
}

TEST(RectangleTest3, CopyAssignment) {
    Rectangle rectangle1(0, 0, 4, 6);
    Rectangle rectangle2 = rectangle1;
    ASSERT_EQ(rectangle1, rectangle2);
}

TEST(RectangleTest4, MoveAssignment) {
    Rectangle rectangle1(0, 0, 5, 5);
    Rectangle rectangle2 = std::move(rectangle1);
    ASSERT_DOUBLE_EQ(rectangle2.square(), 25);
}

TEST(TrapezoidTest1, CenterCalculation) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 3, 1, 3);
    testing::internal::CaptureStdout();
    trapezoid.get_center();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "  Trapezoid center: (2, 1.5)\n");
}

TEST(ShapeArrayTest, AddShape) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    shapeArray.add_shape(square);
    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 16.0);
}

TEST(ShapeArrayTest, RemoveShape) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    shapeArray.add_shape(square);
    shapeArray.removeShape(0);
    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 0.0);
}

TEST(ShapeArrayTest, TotalArea) {
    ShapeArray shapeArray;
    Square* square = new Square(0, 0, 4);
    Rectangle* rectangle = new Rectangle(0, 0, 4, 6);
    
    shapeArray.add_shape(square);
    shapeArray.add_shape(rectangle);
    
    ASSERT_DOUBLE_EQ(shapeArray.totalArea(), 16.0 + 24.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
