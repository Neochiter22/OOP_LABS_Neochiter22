#include <iostream>
#include <string>
#include "include/Calculator.h"

void showMenu()
{
    std::cout << "\nChoose one of the following:" << std::endl;
    std::cout << "1. Enter two 12-based numbers (0-9 and A-B)" << std::endl;
    std::cout << "2. Sum of the numbers" << std::endl;
    std::cout << "3. Subtract the second number from the first" << std::endl;
    std::cout << "4. Compare numbers" << std::endl;
    std::cout << "5. Print numbers" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main()
{
    std::cout << "\nWelcome to Twelve Program" << std::endl;
    Twelve num1, num2;
    bool numbersEntered = false;
    int choise = 0;

    while (choise != 6)
    {
        showMenu();
        if (!(std::cin >> choise))
        {
            std::cerr << "Invalid input. Enter number from 1 to 7" << std::endl;
            std::cin.clear();
            continue;
        }
        try
        {
            switch (choise)
            {
            case 1:
            {
                if (numbersEntered)
                {
                    std::cout << "\nNumbers already entered" << std::endl;
                    break;
                }
                std::string inputNum1, inputNum2;
                std::cout << "\nEnter the first number more than the second: ";
                std::cin >> inputNum1;
                num1 = Twelve(inputNum1);
                std::cout << "Enter the second number less than the first one: ";
                std::cin >> inputNum2;
                num2 = Twelve(inputNum2);
                numbersEntered = true;
                std::cout << "\nNumbers entered" << std::endl;
                break;
            }
            case 2:
            {
                if (!numbersEntered)
                {
                    std::cout << "Please enter numbers before this operation" << std::endl;
                    break;
                }
                Twelve sumResult = num1;
                sumResult += num2;
                std::cout << "\nSum of numbers: ";
                for (size_t i = 0; i < sumResult.getSize(); i++)
                {
                    std::cout << sumResult.getData()[i];
                }
                std::cout << std::endl;
                break;
            }
            case 3:
            {
                if (!numbersEntered)
                {
                    std::cout << "Please enter numbers before this operation" << std::endl;
                    break;
                }
                Twelve subResult = num1;
                subResult -= num2;
                std::cout << "\nSubtraction result: ";
                for (size_t i = 0; i < subResult.getSize(); i++)
                {
                    std::cout << subResult.getData()[i];
                }
                std::cout << std::endl;
                break;
            }
            case 4:
            {
                if (!numbersEntered)
                {
                    std::cout << "Please enter numbers before this operation" << std::endl;
                    break;
                }
                std::cout << "\nComparision result: ";
                if (num1 == num2)
                {
                    std::cout << "Equal" << std::endl;
                }
                else if (num1 < num2)
                {
                    std::cout << "First is less than second" << std::endl;
                }
                else if (num1 > num2)
                {
                    std::cout << "First is greater than second" << std::endl;
                }
                break;
            }

            case 5:
            {
                if (!numbersEntered)
                {
                    std::cout << "Please enter numbers before this operation" << std::endl;
                    break;
                }
                std::cout << "\nFirst number: ";
                for (size_t i = 0; i < num1.getSize(); i++)
                {
                    std::cout << num1.getData()[i];
                }
                std::cout << std::endl;

                std::cout << "Second number: ";
                for (size_t i = 0; i < num2.getSize(); i++)
                {
                    std::cout << num2.getData()[i];
                }
                std::cout << std::endl;
                break;
            }
            case 6:
            {
                std::cout << "\nHave a nice day ! :)\n" << std::endl;
                break;
            }

            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
        catch (const invalidInput &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (const NegativeSubtraction &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}