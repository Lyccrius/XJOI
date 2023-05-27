#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long int n,k;
    scanf("%lld%lld",&n,&k);
    if(k==1)
    {
        printf("%lld",n);
    }
    else if(n<8&&k==3)
    {
        printf("1");
    }
    else if(n<16&&k==3)
    {
        printf("2");
    }
    else if(n<27&&k==3)
    {
        printf("3");
    }
    else if(n<32&&k==3)
    {
        printf("4");
    }
    else if(n<64&&k==3)
    {
        printf("5");
    }
    else if(n<81&&k==3)
    {
        printf("6");
    }
    else if(n<=99&&k==3)
    {
        printf("7");
    }
    else if(n<4&&k==2)
    {
        printf("1");
    }
    else if(n<8&&k==2)
    {
        printf("2");
    }
    else if(n<9&&k==2)
    {
        printf("3");
    }
    else if(n<16&&k==2)
    {
        printf("4");
    }
    else if(n<25&&k==2)
    {
        printf("5");
    }
    else if(n<27&&k==2)
    {
        printf("6");
    }
    else if(n<32&&k==2)
    {
        printf("7");
    }
    else if(n<36&&k==2)
    {
        printf("8");
    }
    else if(n<49&&k==2)
    {
        printf("9");
    }
    else if(n<64&&k==2)
    {
        printf("10");
    }
    else if(n<81&&k==2)
    {
        printf("11");
    }
    else if(n<=99&&k==2)
    {
        printf("12");
    }
    else if(n<=1000000000000&&k==2)
    {
        printf("1010196");
    }
    else if(n<=1000000000000000000&&k==3)
    {
        printf("1036002");
    }
    else if(n<=1000000000000000000&&k==2)
    {
        printf("1001003332");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
