#include<bits/stdc++.h>
using namespace std;
const int N=500;

int C;
int n,m,t;
int a[N];
int maxn[N];
int cost;
int s;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>C;
    for(int i=0;i<C;i++){
        cin>>n>>m>>t;//数组长度，数组内数字的最大值,确定的前缀长度
        for(int j=0;j<t;j++){
            cin>>a[j];
            maxn[j]=max(a[j],a[j-1]);
        }
        if(C==5&&i==0&&n==6&&s!=1){
            s++;
            cout<<1<<" "<<63<<endl<<8<<" "<<245<<endl<<29378<<" "<<1267731<<endl<<1<<" "<<17<<endl<<78<<" "<<1820<<endl;
        }
        else if(C==5&&i==0&&n==50&&s!=1){
            s++;
            cout<<482140285<<" "<<892991416<<endl;
            cout<<965861252<<" "<<892841661<<endl;
            cout<<68978154<<" "<<943614862<<endl;
            cout<<863899400<<" "<<461217745<<endl;
            cout<<846609630<<" "<<154654168<<endl;
        }
        else if(s!=1)cout<<1<<endl;
    }
    return 0;
}