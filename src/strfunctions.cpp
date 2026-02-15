#include <cctype>

/*
    strcmp_case_insensitive

    Case-insensitive comparison of two C-style strings.

    Features:
    - Optional skip spaces
    - Optional max characters to compare (-1 = unlimited)
    - Numeric prefix ordering
    - Safe for nullptr strings
    - Original strings unchanged
*/

short strcmp_case_insensitive(const char s1[], const char s2[],
                              bool skipSpaces = false,
                              short maxChars = -1)  // negative = unlimited
{
    short result = 0;          // final result
    short count = 0;           // characters compared
    bool done = false;         // exit flag

    // Handle nullptr
    if (!s1 && !s2) return 0;
    if (!s1) return -1;
    if (!s2) return 1;

    for (short i = 0, j = 0; !done && (maxChars < 0 || count < maxChars); ++count)
    {
        // Skip spaces if requested
        while (skipSpaces && s1[i] && std::isspace(s1[i])) ++i;
        while (skipSpaces && s2[j] && std::isspace(s2[j])) ++j;

        // Numeric prefix comparison
        if (std::isdigit(s1[i]) && std::isdigit(s2[j]))
        {
            short num1 = 0, num2 = 0;

            while (std::isdigit(s1[i]))
            {
                num1 = num1 * 10 + (s1[i] - '0');
                ++i;
            }

            while (std::isdigit(s2[j]))
            {
                num2 = num2 * 10 + (s2[j] - '0');
                ++j;
            }

            if (num1 < num2)
            {
                result = -1;
                done = true;
                continue;
            }
            else if (num1 > num2)
            {
                result = 1;
                done = true;
                continue;
            }
            // If equal → continue
        }

        // =========================
        // Case-insensitive character comparison
        // =========================
        unsigned char c1 = std::tolower(static_cast<unsigned char>(s1[i]));
        unsigned char c2 = std::tolower(static_cast<unsigned char>(s2[j]));

        if (c1 != c2)
        {
            result = c1 - c2;
            done = true;
        }
        else
        {
            if (s1[i] == '\0' || s2[j] == '\0')
            {
                result = c1 - c2;  // handle string length difference
                done = true;
            }
            else
            {
                ++i;
                ++j;
            }
        }
    }

    return result;
}