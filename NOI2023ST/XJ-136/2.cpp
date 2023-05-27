#include<stdio.h>
int main()
{
    freopen("power.in ","r",stdin);
    freopen("power.out","w",stdout);
    int n,k,i,j,h=1,ans=1;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++)
    for(j=2;j<=i;j++)
    if(i%j==0)
    while(1)
    {
        if(h>i)
        break;
        h*=j;
        n+=1;
        if(h==i&&n>=k)
        ans++;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}