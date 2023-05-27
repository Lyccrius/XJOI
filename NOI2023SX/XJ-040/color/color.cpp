#include <iostream>
using namespace std;
int c,n,m,t,a[1000000];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        cin>>n>>m>>t;
        for(int i=1;i<=t;i++) cin>>a[i];
        cout<<rand()%998244353<<" "<<rand()%998244353<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}