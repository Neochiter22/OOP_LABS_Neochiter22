#include <gtest/gtest.h>
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Array.h"

TEST(PointTest, InitializationAndOutput) {
    Point<double> p(3, 4);
    std::stringstream ss;
    ss << p;

    EXPECT_TRUE(p.x == 3 && p.y == 4 && ss.str() == "(3, 4)");
}

TEST(SquareTest, AreaAndCenterCalculation) {
    Point<double> bottom_left(0, 0);
    Square<double> square(bottom_left, 4);
    Point<double> center = square.center();
    double area = static_cast<double>(square);

    EXPECT_TRUE(area == 16.0 && center.x == 2 && center.y == 2);
}

TEST(SquareTest, VertexOutput) {
    Point<double> bottom_left(0, 0);
    Square<double> square(bottom_left, 4);
    std::stringstream ss;
    ss << square;
    std::string expected_output = "  Point 1: (0, 0)\n  Point 2: (4, 0)\n  Point 3: (4, 4)\n  Point 4: (0, 4)\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(RectangleTest, AreaAndCenterCalculation) {
    Point<double> rect_bottom_left(0, 0);
    Rectangle<double> rectangle(rect_bottom_left, 3, 5);

    Point<double> center = rectangle.center();
    double area = static_cast<double>(rectangle);

    EXPECT_TRUE(area == 15.0 && center.x == 1.5 && center.y == 2.5);
}

TEST(RectangleTest, VertexOutput) {
    Point<double> bottom_left(0, 0);
    Rectangle<double> rectangle(bottom_left, 3, 5);
    std::stringstream ss;
    ss << rectangle;
    std::string expected_output = "  Point 1: (0, 0)\n  Point 2: (3, 0)\n  Point 3: (3, 5)\n  Point 4: (0, 5)\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(TrapezoidTest, AreaAndCenterCalculation) {
    Point<double> v1(0, 0), v2(4, 0), v3(3, 3), v4(1, 3);
    Trapezoid<double> trapezoid(v1, v2, v3, v4);

    Point<double> center = trapezoid.center();
    double area = static_cast<int>(trapezoid);

    EXPECT_TRUE(area == 9 && center.x == 2 && center.y == 1.5);
}

TEST(TrapezoidTest_1, VertexOutput) {
    Point<double> v1(0, 0), v2(4, 0), v3(3, 3), v4(1, 3);
    Trapezoid<double> trapezoid(v1, v2, v3, v4);
    std::stringstream ss;
    ss << trapezoid;
    std::string expected_output = "  Point 1: (0, 0)\n  Point 2: (4, 0)\n  Point 3: (3, 3)\n  Point 4: (1, 3)\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(ArrayTest, ReserveIncreasesCapacity) {
    Array<Figure<double>> figures;
    size_t initial_capacity = 5;
    figures.reserve(initial_capacity);
    
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 2));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 3, 4));
    EXPECT_TRUE(figures.get_size() == 2);

    for (int i = 2; i < initial_capacity; ++i) {
        figures.push_back(std::make_shared<Square<double>>(Point<double>(i, i), 1));
    }
    EXPECT_TRUE(figures.get_size() == initial_capacity);
}

TEST(PointTest_2, InitializationAndOutput) {
    Point<double> p(3.5, 4.2);
    std::stringstream ss;
    ss << p;

    EXPECT_TRUE(p.x == 3.5 && p.y == 4.2 && ss.str() == "(3.5, 4.2)");
}

TEST(SquareTest_2, AreaAndCenterCalculation) {
    Point<double> bottom_left(1, 2);
    Square<double> square(bottom_left, 6);
    Point<double> center = square.center();
    double area = static_cast<double>(square);

    EXPECT_TRUE(area == 36.0 && center.x == 4 && center.y == 5);
}

TEST(SquareTest_2, VertexOutput) {
    Point<double> bottom_left(1, 2);
    Square<double> square(bottom_left, 6);
    std::stringstream ss;
    ss << square;
    std::string expected_output = "  Point 1: (1, 2)\n  Point 2: (7, 2)\n  Point 3: (7, 8)\n  Point 4: (1, 8)\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(RectangleTest_2, VertexOutput) {
    Point<double> bottom_left(2, 4);
    Rectangle<double> rectangle(bottom_left, 8, 3);
    std::stringstream ss;
    ss << rectangle;
    std::string expected_output = "  Point 1: (2, 4)\n  Point 2: (10, 4)\n  Point 3: (10, 7)\n  Point 4: (2, 7)\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(TrapezoidTest_2, VertexOutput) {
    Point<double> v1(1, 1), v2(7, 1), v3(6, 6), v4(2, 6);
    Trapezoid<double> trapezoid(v1, v2, v3, v4);
    std::stringstream ss;
    ss << trapezoid;
    std::string expected_output = "  Point 1: (1, 1)\n  Point 2: (7, 1)\n  Point 3: (6, 6)\n  Point 4: (2, 6)\n";

    EXPECT_EQ(ss.str(), expected_output);
}


TEST(ArrayTest, ShrinkToFitReducesCapacity) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 5));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 2, 3));

    figures.reserve(10);
    EXPECT_TRUE(figures.get_size() == 2);

    figures.shrink_to_fit();
    EXPECT_TRUE(figures.get_size() == 2);
}

TEST(ArrayTest, RemoveElementLeavesNullptr) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 4));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 3, 5));

    figures.remove(0);
    EXPECT_TRUE(figures.get_size() == 1);

    EXPECT_NO_THROW(figures[0]);

    double remaining_area = static_cast<double>(*figures[0]);
    EXPECT_EQ(remaining_area, 15.0);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 4));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 3, 5));

    double total_area = figures.total_S();
    EXPECT_EQ(total_area, 31.0);

    figures.remove(0);
    total_area = figures.total_S();
    EXPECT_EQ(total_area, 15.0);
}

TEST(ArrayTest, PushBackAccessAndArea) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 4));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 3, 5));

    double total_area = static_cast<double>(*figures[0]) + static_cast<double>(*figures[1]);

    EXPECT_TRUE(figures.get_size() == 2 && total_area == 31.0);
}

TEST(ArrayTest, RemoveElementAndAccess) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 0), 4));
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 0), 3, 5));

    figures.remove(0);
    double remaining_area = static_cast<double>(*figures[0]);

    EXPECT_TRUE(figures.get_size() == 1 && remaining_area == 15.0);
}

TEST(ArrayTest, EmptyArrayTotalArea) {
    Array<Figure<double>> figures;
    double totalArea = figures.total_S();
    EXPECT_EQ(totalArea, 0.0);
}
