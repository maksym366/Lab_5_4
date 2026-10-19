#include <iostream>
#include <cmath>
using namespace std;


double P0(const int N)
{
    double p = 1;

   
    for (int j = 1; j <= N; j++)
        p *= sqrt((1.0 * j * j) / (1 + exp(-1.0 * j)));

    return p;
}

double P1(const int N, const int j)
{
    if (j > N)
        return 1;
    else
        return sqrt((1.0 * j * j) / (1 + exp(-1.0 * j)))
        * P1(N, j + 1);
}

double P2(const int N, const int j)
{
    if (j < 1)
        return 1;
    else
        return sqrt((1.0 * j * j) / (1 + exp(-1.0 * j)))
        * P2(N, j - 1);
}

double P3(const int N, const int j, double p)
{
    p *= sqrt((1.0 * j * j) / (1 + exp(-1.0 * j)));

    if (j >= N)
        return p;
    else
        return P3(N, j + 1, p);
}

double P4(const int j, double p)
{
    p *= sqrt((1.0 * j * j) / (1 + exp(-1.0 * j)));

    if (j <= 1)
        return p;
    else
        return P4(j - 1, p);
}

int main()
{
    const int N = 15;

    cout << " P0 = " << P0(N) << endl;

    cout << " (+) P1 = " << P1(N, 1) << endl;

    cout << "  (-) P2 = " << P2(N, N) << endl;

    cout << " (+) P3 = " << P3(N, 1, 1) << endl;

    cout << "  (-) P4 = " << P4(N, 1) << endl;

    return 0;
}