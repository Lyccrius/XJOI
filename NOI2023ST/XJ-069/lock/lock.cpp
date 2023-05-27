#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int t,k,l;
    cin>>t>>k;
    for(int i=1;i<=t;i++){
        int n,mx=-1,mn=100000;
        cin>>n;
        if(k==1){
            for(int j=1;j<=n;j++){
               cin>>l;
               if(l>mx)mx=l;
               if(l<mn)mn=l;
            }
            cout<<mx-mn<<endl;
        }
        else if(k==2){

        }
    }
    return 0;
}
