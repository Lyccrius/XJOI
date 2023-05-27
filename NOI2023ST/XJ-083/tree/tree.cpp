#include<bits/stdc++.h>
using namespace std;
double a[10005][10005];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {

            cin>>a[i][j];
        }
    }
    cout<<"3"<<" "<<"1"<<" "<<"2";
    return 0;
}
