#include <iostream>
using namespace std;

int main()
{
    long long base, power, mod;
    cin >> base >> power >> mod;

    long long result = 1;

    while(power > 0)
    {
        if(power % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        power /= 2;
    }

    result = result % mod; // a^0 % 1 = 0 but without this line, it will return 1. So, we need to handle this case separately.
    cout << result;

    return 0;
}