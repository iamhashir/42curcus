#include "whatever.hpp"
#include <iostream>

int main()
{
    int a =  12;
    int b =  13;

    std::cout << "\033[95m================= Swap (Custom Test) =================\033[0m" << std::endl;
    std::cout << "before swap a: " << a << std::endl;
    std::cout << "before swap b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "after swap a: " << a << std::endl;
    std::cout << "after swap b: " << b << std::endl;
    std::cout << std::endl;

    std::cout << "\033[96m================== Min (Custom Test) ==================\033[0m" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "min(a, b): " << ::min(a, b) << std::endl;
    a = b;
    std::cout << "a = b" << std::endl;
    std::cout << "min(a, b): " << ::min(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "\033[92m================== Max (Custom Test) ==================\033[0m" << std::endl;
    a = 121;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max(a, b): " << ::max(a, b) << std::endl;
    a = b;
    std::cout << "a = b" << std::endl;
    std::cout << "max(a, b): " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "\033[93m================ Subject Test (UNCHANGED) ================\033[0m" << std::endl;

    int a2 = 2;
    int b2 = 3;
    ::swap( a2, b2 );
    std::cout << "a = " << a2 << ", b = " << b2 << std::endl;
    std::cout << "min( a, b ) = " << ::min( a2, b2 ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a2, b2 ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}
