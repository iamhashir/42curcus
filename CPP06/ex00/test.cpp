#include <iostream>
#include "ScalarConverter.hpp"

int main(void)
{
    try
    {
        std::cout << "\033[31m=================INPUT: \"A\"=================\033[0m" << std::endl;
        ScalarConverter::convert("A");
        std::cout << std::endl;

        std::cout << "\033[32m=================INPUT: \"+42\"=================\033[0m" << std::endl;
        ScalarConverter::convert("+42");
        std::cout << std::endl;

        std::cout << "\033[33m=================INPUT: \"+42ff\"=================\033[0m" << std::endl;
        ScalarConverter::convert("+42ff");
        std::cout << std::endl;

        std::cout << "\033[34m=================INPUT: \" \"=================\033[0m" << std::endl;
        ScalarConverter::convert(" ");
        std::cout << std::endl;

        std::cout << "\033[35m=================INPUT: \"0\"=================\033[0m" << std::endl;
        ScalarConverter::convert("0");
        std::cout << std::endl;

        std::cout << "\033[36m=================INPUT: \"-42\"=================\033[0m" << std::endl;
        ScalarConverter::convert("-42");
        std::cout << std::endl;

        std::cout << "\033[31m=================INPUT: \"2147483647\"=================\033[0m" << std::endl;
        ScalarConverter::convert("2147483647");
        std::cout << std::endl;

        std::cout << "\033[32m=================INPUT: \"2147483648\"=================\033[0m" << std::endl;
        ScalarConverter::convert("2147483648");
        std::cout << std::endl;

        std::cout << "\033[33m=================INPUT: \"-2147483649\"=================\033[0m" << std::endl;
        ScalarConverter::convert("-2147483649");
        std::cout << std::endl;

        std::cout << "\033[34m=================INPUT: \"4.2f\"=================\033[0m" << std::endl;
        ScalarConverter::convert("4.2f");
        std::cout << std::endl;

        std::cout << "\033[35m=================INPUT: \"42.f\"=================\033[0m" << std::endl;
        ScalarConverter::convert("42.f");
        std::cout << std::endl;

        std::cout << "\033[36m=================INPUT: \"nanf\"=================\033[0m" << std::endl;
        ScalarConverter::convert("nanf");
        std::cout << std::endl;

        std::cout << "\033[31m=================INPUT: \"+inff\"=================\033[0m" << std::endl;
        ScalarConverter::convert("+inff");
        std::cout << std::endl;

        std::cout << "\033[32m=================INPUT: \"-inff\"=================\033[0m" << std::endl;
        ScalarConverter::convert("-inff");
        std::cout << std::endl;

        std::cout << "\033[33m=================INPUT: \"4.2\"=================\033[0m" << std::endl;
        ScalarConverter::convert("4.2");
        std::cout << std::endl;

        std::cout << "\033[34m=================INPUT: \"+inf\"=================\033[0m" << std::endl;
        ScalarConverter::convert("+inf");
        std::cout << std::endl;

        std::cout << "\033[35m=================INPUT: \"-inf\"=================\033[0m" << std::endl;
        ScalarConverter::convert("-inf");
        std::cout << std::endl;

        std::cout << "\033[36m=================INPUT: \"nan\"=================\033[0m" << std::endl;
        ScalarConverter::convert("nan");
        std::cout << std::endl;

        std::cout << "\033[31m=================INPUT: \"1e309\"=================\033[0m" << std::endl;
        ScalarConverter::convert("1e309");
        std::cout << std::endl;

        std::cout << "\033[32m=================INPUT: \"1.2.3\"=================\033[0m" << std::endl;
        ScalarConverter::convert("1.2.3");
        std::cout << std::endl;

        std::cout << "\033[33m=================INPUT: \"abc\"=================\033[0m" << std::endl;
        ScalarConverter::convert("abc");
        std::cout << std::endl;

        std::cout << "\033[34m=================INPUT: \"\"=================\033[0m" << std::endl;
        ScalarConverter::convert("");
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
