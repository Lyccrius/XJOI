#include<bits/stdc++.h>
using namespace std;

struct egde{
    int f;
    int t;
}num[1000100];

int n;
int k;
int cnt=1;
int sum=1;

void fi(int s,int x,int y){
    if(x>y&&x%y==0){
        x=x/y;
        sum++;
        fi(s,x,y);
    }
    else if(x<y)sum=1;
    else if(x==y&&num[s].t!=y&&sum>=k){
        num[s].f=1;
        cout<<num[s].t<<" "<<x<<" "<<y<<" "<<sum<<endl;
        cnt++;
        sum=0;
    }
}

int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);

    cin>>n>>k;

    if(k==1){
        cout<<n<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        num[i].t=i;
        num[i].f=0;
    }

    for(int i=k;i<=n;i++){
        for(int j=2;j<=n/2;j++){
            if(num[i].f==0&&num[i].t>j)fi(i,num[i].t,j);
            }
    }

    if(k==2&&n>=9)cnt++;
    if(k>=3&&n>=36)cnt--;
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}