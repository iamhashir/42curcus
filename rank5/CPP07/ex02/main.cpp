#include <iostream>
#include "Array.hpp"

int main() {

    std::cout << "\033[95m================= DEFAULT CONSTRUCTOR =================\033[0m\n";
    {
        Array<int> a;
        std::cout << "Size: " << a.size() << std::endl;
    }

    std::cout << "\033[96m================ PARAMETERIZED CONSTRUCTOR =============\033[0m\n";
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = i * 10;
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "\033[92m==================== COPY CONSTRUCTOR ==================\033[0m\n";
    {
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = i + 1;

        Array<int> b(a);
        b[0] = 42;

        std::cout << "Original: ";
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\nCopy:     ";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "\033[93m================= ASSIGNMENT OPERATOR ==================\033[0m\n";
    {
        Array<int> a(4);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = i;

        Array<int> b;
        b = a;
        b[1] = 99;

        std::cout << "Original: ";
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\nAssigned: ";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "\033[94m=================== CONST ACCESS TEST ==================\033[0m\n";
    {
        Array<int> a(2);
        a[0] = 7;
        a[1] = 14;
        const Array<int> b(a);

        std::cout << b[0] << " " << b[1] << std::endl;
    }

    std::cout << "\033[91m================= OUT OF BOUNDS TEST ===================\033[0m\n";
    {
        Array<int> a(1);
        try {
            std::cout << a[5] << std::endl;
        } catch (const std::exception&) {
            std::cout << "Exception caught" << std::endl;
        }
    }

    std::cout << "\033[90m==================== EMPTY ASSIGNMENT ==================\033[0m\n";
    {
        Array<int> a(3);
        Array<int> b;
        b = a;
        std::cout << "Size after assignment: " << b.size() << std::endl;
    }

    return 0;
}
