#include<iostream>
using namespace std;
int a,b;
int main(){
    freopen("power","r",stdin);
    freopen("power","w",stdout);
    cin>>a>>b;
    if(b==1){
        cout<<a;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
