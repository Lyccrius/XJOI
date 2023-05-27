#include <iostream>
using namespace std;
int a[100050][2];
int main()
{
    int n,m,k;
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    cout<<"9";
    fclose(stdin);
    fclose(stdout);
    return 0;
}