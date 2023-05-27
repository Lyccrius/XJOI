#include<bits/stdc++.h>
using namespace std;
int n;
struct tree{
    int num;
    double x,y,s;
}t[1005];
bool cmp(tree a,tree b)
{
    
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].x>>t[i].y;
        t[i].num=i;
    }
    sort(t+1,t+n+1,cmp);
    fclose(stdin);
    fclose(stdout);
    return 0;
}