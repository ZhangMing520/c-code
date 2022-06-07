#include "template_func.h"
#include <stdexcept>
#include <algorithm>
#include <iterator>

using std::domain_error;
using std::string;
using std::vector;
using std::ostream_iterator;



bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

