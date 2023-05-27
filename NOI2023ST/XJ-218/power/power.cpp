#include <bits/stdc++.h>
using namespace std;
int k=0,s=0,c=1;

int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long int n;
    int a;
    cin>>n>>a;
  long long int m[1000000];
  memset(m,0,sizeof(m));
    if(a==1){cout<<n;
             fclose(stdin);
             fclose(stdout);
             return 0;}

    int i=a,j=2;
    while(pow(j,i)<=n){
    while(pow(j,i)<=n){
     m[k]=pow(j,i);
        k++;
        j++;
 
    }
    if(j==2){
        j=0;
        break;
    }
     i++;
     j=2;
    }

    sort(m,m+k);

for(int y=0;y<k;y++){
    if(m[y+1]!=m[y])s++;
}
cout<<s+1;
             fclose(stdin);
             fclose(stdout);
             return 0;
}