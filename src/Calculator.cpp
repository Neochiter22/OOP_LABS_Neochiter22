#include <iostream>
#include <cstring> 
#include "../include/Calculator.h"

void validateInput(unsigned char digit)
{
    if (!((digit >= '0' && digit <= '9') || (digit <= 'B' && digit >= 'A'))){
        throw invalidInput();
    }
}

int TwelveTo_10(unsigned char digit)
{
    if (digit >= '0' && digit <= '9') {
        return digit - '0';
    } 
    else if (digit >= 'A' && digit <= 'B') {
        return digit - 'A' + 10;
    } 
    else {
        throw std::invalid_argument("Invalid input");
    }
}

unsigned char ToTwelve(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    } 
    else if (digit >= 10 && digit <= 12) {
        return 'A' + (digit - 10);
    } else {
        throw std::invalid_argument("Invalid input");
    }
}

Twelve::Twelve() : size_(0), data_(nullptr) {}

Twelve::Twelve(const size_t &length, unsigned char value) {
    validateInput(value);
    size_ = length;
    data_ = new unsigned char[length];
    for (size_t i = 0; i < length; i++) {
        data_[i] = value;
    }
}

Twelve::Twelve(const std::initializer_list<unsigned char> &valuesList) {
    size_ = valuesList.size();
    data_ = new unsigned char[size_];

    size_t i = 0;
    for (unsigned char digit : valuesList) {
        validateInput(digit);
        data_[i++] = digit;
    }
}

Twelve::Twelve(const std::string &value) {
    size_ = value.size();
    data_ = new unsigned char[size_];

    for (size_t i = 0; i < size_; i++) {
        validateInput(value[i]);
        data_[i] = value[i];
    }
}

Twelve::Twelve(const Twelve &other) {
    size_ = other.size_;
    data_ = new unsigned char[size_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

Twelve::Twelve(Twelve &&other) noexcept {
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
}

Twelve &Twelve::operator=(const Twelve &other) {
    if (this == &other) {
        return *this;
    }

    delete[] data_;
    size_ = other.size_;
    data_ = new unsigned char[size_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
    return *this;
}

Twelve &Twelve::operator+=(const Twelve &other) {
    size_t maxSize = std::max(size_, other.size_);
    unsigned char *result = new unsigned char[maxSize + 1];

    int carry = 0;
    for (size_t i = 0; i < maxSize; i++) {
        int digit1 = (i < size_) ? TwelveTo_10(data_[size_ - 1 - i]) : 0;
        int digit2 = (i < other.size_) ? TwelveTo_10(other.data_[other.size_ - 1 - i]) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 12;
        result[maxSize - i] = decimalToTwelve(sum % 12);
    }


    unsigned char *finalResult = result;
    if (carry == 0) {
        finalResult = new unsigned char[maxSize];
        std::memcpy(finalResult, result + 1, maxSize);
        delete[] result;
    } 
    else {
        finalResult = result;
    }

    delete[] data_;
    data_ = finalResult;
    size_ = maxSize + (carry > 0 ? 1 : 0);

    return *this;
}

Twelve &Twelve::operator-=(const Twelve &other) {
    if (size_ < other.size_) {
        throw NegativeSubtraction();
    }

    int borrow = 0;
    for (size_t i = 0; i < size_; i++) {
        int currentDigit = TwelveTo_10(data_[size_ - 1 - i]) - borrow;
        int otherDigit = (i < other.size_) ? TwelveTo_10(other.data_[other.size_ - 1 - i]) : 0;

        if (currentDigit < otherDigit) {
            currentDigit += 12;
            borrow = 1;
        } 
        else {
            borrow = 0;
        }

        data_[size_ - 1 - i] = decimalToTwelve(currentDigit - otherDigit);
    }

    if (borrow != 0) {
        throw NegativeSubtraction();
    }

    return *this;
}

bool Twelve::operator==(const Twelve &other) const {
    if (size_ != other.size_) {
        return false;
    }
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] != other.data_[i]) {
            return false;
        }
    }
    return true;
}

bool Twelve::operator<(const Twelve &other) const {
    if (size_ != other.size_) {
        return size_ < other.size_;
    }

    for (size_t i = 0; i < size_; i++) {
        int digit1 = TwelveTo_10(data_[i]);
        int digit2 = TwelveTo_10(other.data_[i]);

        if (digit1 != digit2) {
            return digit1 < digit2;
        }
    }

    return false;
}

bool Twelve::operator>(const Twelve &other) const {
    if (size_ != other.size_) {
        return size_ > other.size_;
    }

    for (size_t i = 0; i < size_; i++) {
        int digit1 = TwelveTo_10(data_[i]);
        int digit2 = TwelveTo_10(other.data_[i]);

        if (digit1 != digit2) {
            return digit1 > digit2;
        }
    }

    return false;
}

size_t Twelve::getSize() const { return size_; }

unsigned char *Twelve::getData() const { return data_; }

Twelve::~Twelve() noexcept {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}
