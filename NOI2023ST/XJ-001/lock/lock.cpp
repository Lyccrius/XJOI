#include<bits/stdc++.h>
using namespace std;
long long a[100000][100000];
int main(){
    freopen("lock.in","w",stdin);
    freopen("lock.out","r",stdout);
    long long n,k,y,x,t;
    cin>>t>>k;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;i<=n;i++){
            for(int z=1;z<=k;z++)
            cin>>a[n][k];
        }
        for(int w=1,w<=n;i++)
            for(int q=1;q<=n;q++)
                a[w][q]=0;
    }
    cout<<0<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
