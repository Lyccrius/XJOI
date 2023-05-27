#include<bits/stdc++.h>
using namespace std;
const int N=200010;
stack<int> stackl;
queue<int> queuer;
int n,m,x,a[N],b[N];
bool visa[N],visb[N],checkk[N];
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        for(int j=a[i];j<b[i];j++)
            checkk[j]=1;
    }
    sort(a+1,a+m+1);
    sort(b+1,b+m+1);
    //find the left side
    for(int i=x-1;i>=1;i--){
        if(checkk[i]==1){
            for(int j=1;j<=n;j++){
                if(a[j]==i&&visa[a[j]]==0){
                    stackl.push(a[j]);
                    visa[a[j]]=1;
                    continue;
                }
            }
        }
        else break;
    }
    //find the right side
    for(int i=x;i<n;i++){
        if(checkk[i]==1){
            for(int j=1;j<=n;j++){
                if(b[j]==i+1&&visb[b[j]]==0){
                    queuer.push(b[j]);
                    visb[b[j]]=1;
                    continue;
                }
            }
        }
        else break;
    }
    while(!stackl.empty()){
        cout<<stackl.top()<<' ';
        stackl.pop();
    }
    while(!queuer.empty()){
        cout<<queuer.front()<<' ';
        queuer.pop();
    }
    return 0;
}