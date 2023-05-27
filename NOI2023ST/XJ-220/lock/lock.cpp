#include<bits/stdc++.h>
using namespace std;
int T,k;
int n;
long long a[1000100][3];
int main(){
    //freopen("lock.in","r" ,stdin);
    //freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n;
        if(k==1){
            long long maxn=0,minn=0x3f3f3f3f,t;
            for(int i=1;i<=n;i++)  {
                cin>>t;
                maxn=max(t,maxn);
                minn=min(t,minn);
            }
            cout<<maxn-minn<<endl;
        }
        if(k==2){
            for(int i=1;i<=2;i++){
                for(int j=1;j<=n;j++)
                    cin>>a[i][j];
            }
            /*for(int i=1;i<=2;i++){
                for(int j=1;j<=n;j++)
                   cout<<a[i][j]<<" ";
                cout<<endl;
            }*/
            long long max1=0,max2=0,min1=0x3f3f3f3f,min2=0x3f3f3f3f;
            for(int i=1;i<=n;i++){
                if(a[1][i]>a[2][i]){
                    long long tmp=a[1][i];
                    a[1][i]=a[2][i];
                    a[2][i]=tmp;
                }
                //cout<<a[1][i]<<" "<<a[2][i]<<" "<<endl;
                max1=max(a[1][i],max1);
                max2=max(a[2][i],max2);
                min1=min(a[1][i],min1);
                min2=min(a[2][i],min2);
            }
            //cout<<endl;
            //cout<<max1<<" "<<min1<<" "<<max2<<" "<<min2<<endl;
            cout<<max(abs(min1-max1),abs(min2-max2))<<endl<<endl;
        }
    }
    return 0;
}
