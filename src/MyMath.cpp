#include "MyMath.h"
#include <cmath>

double Combinations(int n, int k)
{
    if(n < 0 || k < 0)
        return -1.0;

    if (k > n)
    {
        return 0;
    }
    return std::tgamma(n + 1) / (std::tgamma(k + 1) * std::tgamma(n - k + 1));


    //return factorial(n) / ( factorial(n-k) * factorial(k));
}

int factorial(int n)
{
    if(n < 0)
        return -1;
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);

}
