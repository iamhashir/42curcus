#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cerrno>
#include <climits>

/* ===================== TYPE DETECTION ===================== */

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

static bool isChar(const std::string& s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isInt(const std::string& s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

static bool isFloat(const std::string& s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;

    if (s[s.length() - 1] != 'f')
        return false;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    bool dot = false;
    bool digit = false;
    for (; i < s.length() - 1; i++)
    {
        if (std::isdigit(s[i]))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return dot && digit;
}

static bool isDouble(const std::string& s)
{
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    bool dot = false;
    bool digit = false;
    for (; i < s.length(); i++)
    {
        if (std::isdigit(s[i]))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return dot && digit;
}

static LiteralType detectType(const std::string& s)
{
    if (s.empty())
        return INVALID;
    if (isChar(s))
        return CHAR;
    if (isInt(s))
        return INT;
    if (isFloat(s))
        return FLOAT;
    if (isDouble(s))
        return DOUBLE;
    return INVALID;
}

/* ===================== PARSING ===================== */

static double parseToDouble(const std::string& s)
{
    errno = 0;
    char* end;
    double d = std::strtod(s.c_str(), &end);
    return d;
}

/* ===================== PRINT ===================== */

static void printChar(double v)
{
    std::cout << "char: ";
    if (std::isnan(v) || v < 0 || v > 127)
    {
        std::cout << "impossible\n";
        return;
    }
    char c = static_cast<char>(v);
    if (!std::isprint(c))
    {
        std::cout << "Non displayable\n";
        return;
    }
    std::cout << "'" << c << "'\n";
}

static void printInt(double v)
{
    std::cout << "int: ";
    if (std::isnan(v) || v < INT_MIN || v > INT_MAX)
    {
        std::cout << "impossible\n";
        return;
    }
    std::cout << static_cast<int>(v) << "\n";
}

static void printFloat(double v)
{
    std::cout << "float: ";

    if (std::isnan(v))
    {
        std::cout << "nanf\n";
        return;
    }
    if (std::isinf(v))
    {
        std::cout << (v > 0 ? "+inff\n" : "-inff\n");
        return;
    }

    float f = static_cast<float>(v);
    if (f == static_cast<int>(f))
        std::cout << f << ".0f\n";
    else
        std::cout << f << "f\n";
}

static void printDouble(double v)
{
    std::cout << "double: ";

    if (std::isnan(v))
    {
        std::cout << "nan\n";
        return;
    }
    if (std::isinf(v))
    {
        std::cout << (v > 0 ? "+inf\n" : "-inf\n");
        return;
    }

    if (v == static_cast<int>(v))
        std::cout << v << ".0\n";
    else
        std::cout << v << "\n";
}

/* ===================== ENTRY ===================== */

void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    if (type == INVALID)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    double value;

    if (type == CHAR)
        value = static_cast<double>(literal[0]);
    else
        value = parseToDouble(literal);

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
