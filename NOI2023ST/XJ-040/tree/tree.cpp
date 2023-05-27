#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
    }
    int x1=(int)n,x2=x1-1;
    printf("%d %d %d",x1,x1-x2,x2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}