#include <iostream>
using namespace std;
double map[1010][3];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>map[i][1]>>map[i][2];
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}