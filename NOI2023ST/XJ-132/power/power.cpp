#include <iostream>
using namespace std;
int num=0;
void jc(int a,int n,int k)
{
    int i,j,l;
    int s=1;
    while(a<n)
        a=a*a;
        s++;
    if(a==n && s>=k)
        num++;

}
int main()
{
    int i,j,k,n,a,t=1;
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%d",&n,&k);
    if(k!=1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                jc(j,i,k);
            }
        }
    }
    else
    {
        num=n;
    }
    printf("%d",num);
    return 0;
}
