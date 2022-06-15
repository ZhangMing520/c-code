#include <vector>
#include <algorithm>
#include <cstring>

using std::vector;
using std::copy;

char *duplicate_chars(const char *p)
{
    size_t length = strlen(p) + 1;
    char *result = new char[length];

    copy(p, p + length, result);

    return result;
}