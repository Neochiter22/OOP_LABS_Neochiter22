#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/calculator.h"

TEST(TwelveTest, AddUpTest_1)
{
  std::string str = "22B";
  std::string str2 = "25A";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'4', '8', '9'};

  Twelve number1(str);
  Twelve number2(str2);
  number2 += number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(TwelveTest, AddUpTest_2)
{
  std::string str = "AB";
  std::string str2 = "234";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'3', '2', '3'};

  Twelve number1(str);
  Twelve number2(str2);
  number2 += number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(TwelveTest, SubstractTest_1)
{
  std::string str = "1";
  std::string str2 = "13A";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'1', '3', '9'};

  Twelve number1(str);
  Twelve number2(str2);
  number2 -= number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(TwelveTest, SubstractTest_2)
{
  std::string str = "97";
  std::string str2 = "28B";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'1', 'B', '4'};

  Twelve number1(str);
  Twelve number2(str2);
  number2 -= number1;
  size_t realSize = number2.getSize();
  unsigned char *realData = number2.getData();

  ASSERT_TRUE(expectedSize == realSize);
  ASSERT_TRUE(expectedData[0] == realData[0]);
  ASSERT_TRUE(expectedData[1] == realData[1]);
  ASSERT_TRUE(expectedData[2] == realData[2]);
}

TEST(TwelveTest, NegativeSubtractionException_1)
{
  std::string str = "432";
  std::string str2 = "B";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'4', '2', '3'};

  Twelve number1(str);
  Twelve number2(str2);

  bool result = number1 > number2;

  ASSERT_TRUE(result);
  ASSERT_THROW(number2 -= number1, NegativeSubtraction);
}

TEST(TwelveTest, NegativeSubtractionException_2)
{
  std::string str = "AB24";
  std::string str2 = "5A1";
  size_t expectedSize = 3;
  unsigned char expectedData[] = {'A', '5', '4', '3'};

  Twelve number1(str);
  Twelve number2(str2);

  bool result = number1 > number2;

  ASSERT_TRUE(result);
  ASSERT_THROW(number2 -= number1, NegativeSubtraction);
}

TEST(TwelveTest, CompareLessTest_1){
  std::string str = "AB8";
  std::string str2 = "26";
  Twelve number1(str);
  Twelve number2(str2);

  bool result = number1 > number2;

  ASSERT_TRUE(result);
}

TEST(TwelveTest, CompareGreatTest_2) {
  std::string str = "21";
  std::string str2 = "2344";
  Twelve number1(str);
  Twelve number2(str2);

  bool result = number2 > number1;

  ASSERT_TRUE(result);
}

TEST(TwelveTest, CompareEqualTest_3) {
  std::string str = "AB225AB";
  std::string str2 = "AB225AB";

  Twelve number1(str);
  Twelve number2(str2);

  bool result = number1 == number2;

  ASSERT_TRUE(result);
}

TEST(TwelveTest, InvalidInputException_1)
{
  std::string str = "serdttgyhu";

  ASSERT_THROW(Twelve number1(str), invalidInput);
}