#include<bits/stdc++.h>
using namespace std;
long long t;
long long m,n,q;
struct s{
    long long number,color;
}x[1000100];
s y[1000100];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)//cun hang
            x[i].color=x[i].number=0;
        for(int i=1;i<=m;i++)//cun hang
            y[i].color=y[i].number=0;
        for(int i=1;i<=q;i++){
            long long otp,j,c;
            cin>>otp>>j>>c;
            if(otp==0){
                x[j].color=c;
                x[j].number=i;
            }
            else{
               y[j].color=c;
                y[j].number=i;
            }
        }
        //for(int i=1;i<=n;i++)
        //        cout<<x[i].number<<" "<<x[i].color<<endl;
        //for(int i=1;i<=n;i++)
         //       cout<<y[i].number<<" "<<y[i].color<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 //   cout<<x[i].color<<" "<<y[j].color<<" ";
                if(x[i].number >y[j].number )
                    cout<<x[i].color<<" ";
                else
                    cout<<y[j].color<<" ";
                //cout<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
果opti= 0，那么这次操作会将第xi.行涂成颜色ci。
•如果opti= 1，那么这次操作会将第xi.列涂成颜色ci。
*/
