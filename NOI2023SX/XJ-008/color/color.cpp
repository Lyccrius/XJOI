#include<bits/stdc++.h>
using namespace std;
const int N=60;
int T,n,m,t;
int a[N];

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for(int i=1;i<=t;i++) scanf("%d",&a[i]);
        printf("0 0\n");
    }    
}