#include "Vector.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::sqrt;

double sqrt_num(Vector &v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); i++)
    {
        sum += sqrt(v[i]);
    }
    return sum;
}

int main()
{
    Vector v{2};
    v[0]=1;
    v[1]=3;
    cout << sqrt_num(v);
}