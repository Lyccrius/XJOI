#include <bits/stdc++.h>
using namespace std;
bool cheak[1000000010];
long long sum;

int main()
{
    freopen ("power.in", "r", stdin);
    freopen ("power.out", "w", stdout);
    long long a, b;
    scanf ("%lld %lld", &a, &b);
    if (b == 1) return printf ("%lld", a), 0;
    double c = 1.0 / b;
    double k = pow(a, c);
    for (int i = 2; i <= k; ++ i)
    {
        if (cheak[i] == 0)
            for (int j = b; pow(i, j) <= a; j ++)
            {
                sum ++;
                if (pow((int)pow(i, j), b) <= a)
                    cheak[(int)pow(i, j)] = 1;
            }
    }
    printf ("%lld", sum + 1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}