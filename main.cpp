#include <iostream>

#include "src/strfunctions.hpp"

void test(const char s1[], const char s2[],
          bool skipSpaces = false,
          short maxChars = -1)
{
    short result = strcmp_case_insensitive(s1, s2, skipSpaces, maxChars);

    std::cout << "The comparison of \"" << (s1 ? s1 : "nullptr")
              << "\" and \"" << (s2 ? s2 : "nullptr") << "\"";

    if (skipSpaces) std::cout << " [skipSpaces=true]";
    if (maxChars >= 0) std::cout << " [maxChars=" << maxChars << "]";

    std::cout << " returns " << result << "." << std::endl;
}


int main()
{
    std::cout << "==== BASIC TESTS ====\n";
    test("Hi", "hi");
    test("String one", "string two");
    test("String one", "string one");
    test("String two", "string one");

    std::cout << "\n==== SKIP SPACES TESTS ====\n";
    test("My Cool String!", "mycool string!", true);
    test(" My Cool String ", "mycool string", true);

    std::cout << "\n==== MAX CHAR TESTS ====\n";
    test("abcdef", "abcxyz", false, 3);
    test("abcdef", "abcxyz", false, 0);

    std::cout << "\n==== NUMERIC PREFIX TESTS ====\n";
    test("2", "50");
    test("2", "10");
    test("20", "5");
    test("20", "1");
    test("100", "100");

    test("2 Some String", "50 Some String");
    test("2 Some String", "10 Some String");
    test("20 Some String", "5 Some String");
    test("20 Some String", "1 Some String");
    test("100 Some String", "100 Some String");

    return 0;
}
