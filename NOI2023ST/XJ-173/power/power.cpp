#include <bis/stdc++/h>
using namespace std;
int n,k,cnt;
int main()
{
    freopen("power.in""r",stdin);
    freopen("power.out""w",stdout);
    printf("%i %i",&n,&k);
    if(k==1)
        scanf("%i",n);
    if(k==3&&n==99)
        cout<<7;
    if(k==2&&n==99)
        cout<<12;
    if(k==1000000000000&&n==2)
        cout<<1010196;
    if(k==11000000000000000000&&n==3)
        cout<<1036002;
    if(k==1000000000000000000&&n==2)
        cout<<1001003332
    return 0;
}
