#pragma once
#include <initializer_list>
#include <stdexcept>

void validateInput(unsigned char digit);
int ToDecimal(unsigned char digit);
unsigned char decimalToTwelve(int digit);

class Twelve {
  public:
    Twelve();
    Twelve(const size_t &length, unsigned char value = 0);
    Twelve(const std::initializer_list<unsigned char> &valuesList);
    Twelve(const std::string &value);
    Twelve(const Twelve &other);
    Twelve(Twelve &&other) noexcept;
    virtual ~Twelve() noexcept;

    Twelve &operator=(const Twelve &other);
    Twelve &operator+=(const Twelve &other);
    Twelve &operator-=(const Twelve &other);

    bool operator==(const Twelve &other) const;
    bool operator<(const Twelve &other) const;
    bool operator>(const Twelve &other) const;

    size_t getSize() const;
    unsigned char *getData() const;

    private:
    size_t size_;
    unsigned char *data_;
};

class invalidInput : public std::invalid_argument {
    public:
    invalidInput(): std::invalid_argument("Invalid digit: It must be between 0 and 12(B)") {}
};

class NegativeSubtraction : public std::invalid_argument {
    public:
    NegativeSubtraction(): std::invalid_argument("\nNegative result of subtraction (1 must be larger than 2)") {}
};