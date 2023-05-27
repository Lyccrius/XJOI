#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n,k;
int sum;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%d %d",&n,&k);
    if(k==1)
    {
        printf("%d",n);
        return 0;
    }
    sum=1;
    for(int i=4;i<=n;i++)
    {
        for(int j=2;j<=sqrt(i);j++)
        {
            int sum1=sum;
            int a=j;
            for(int y=2;y<k;y++)
                    a*=j;
            for(int t=k;t<=20;t++)
            {
                a=a*j;
                if(a==i)
                {
                    sum++;
                    break;
                }
                if(a>i)break;
            }
            if(sum1!=sum)break;
        }
    }
    printf("%d",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}