#include <bits/stdc++.h>
int k=0,re[12][12];
using namespace std;
void map1(){
int n,m,cnt=0;
cin>>n>>m;
for(int i=1;i<=n;++i){
    string a;
    cin>>a;
for(int j=0;j<m;++j){
    if(a[j]=='.')re[i][j+1]=3;
    if(a[j]=='O')re[i][j+1]=1;
    if(a[j]=='X')re[i][j+1]=2;
    if(a[j]=='#')re[i][j+1]=0;
}
}
for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        if(re[i][j]==1&&re[i-1][j]==0&&re[i+1][j]==0&&re[i][j+1]==0&&re[i][j-1]==0)cnt++;
        if(cnt==2){
            cout<<"Black 0"<<endl;
            return;
        }
         
    }
}

if(cnt==2){
     cout<<"Black 0"<<endl;
     cnt=0;
     return;}

cout<<"Tie"<<endl;
memset(re,0,sizeof(re));
}
void map2(){
int n,m,cnt=0,ans=0,e,f,g,x=0;
cin>>n>>m;
for(int i=1;i<=n;++i){
    string a;
    cin>>a;
for(int j=0;j<m;++j){
    if(a[j]=='.')re[i][j+1]=3;
    if(a[j]=='O')re[i][j+1]=1;
    if(a[j]=='X')re[i][j+1]=2;
    if(a[j]=='#')re[i][j+1]=0;
}
}
 for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        if(re[i][j]==1&&re[i-1][j]==0&&re[i+1][j]==0&&re[i][j+1]==0&&re[i][j-1]==0)cnt++;
            
        
        if(re[i][j]==2&&re[i-1][j]==0&&re[i+1][j]==0&&re[i][j+1]==0&&re[i][j-1]==0)ans++;
        if(cnt==2){
            cout<<"Black 0"<<endl;
            return;
        }
        if(ans==1){
            cout<<"Red 0"<<endl;
            return;
        }
        if(cnt==2&&ans==1){
            cout<<"Tie"<<endl;
            return;
        } 
    } }  
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    int id,T;
    cin>>id>>T;
    if(1<=id<=4){
        while(k!=T){
             k++;
            map1();
            
        }
    }
    if(7<=id<=9){  
     while(k!=T){
         k++;
        map2();
            
        }}
    fclose(stdin);
    fclose(stdout);
    return 0;
}