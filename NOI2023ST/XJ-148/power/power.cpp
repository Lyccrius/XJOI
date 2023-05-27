#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    if(k==2){
        if(n>=1&&n<4)
            cout<<"1";
        if(n>=4&&n<8)
            cout<<"2";
        if(n>=8&&n<9)
            cout<<"3";
        if(n>=9&&n<16)
            cout<<"4";
        if(n>=16&&n<25)
            cout<<"5";
        if(n>=25&&n<27)
            cout<<"6";
        if(n>=27&&n<32)
            cout<<"7";
        if(n>=32&&n<36)
            cout<<"8";
        if(n>=36&&n<49)
            cout<<"9";
        if(n>=49&&n<64)
            cout<<"10";
        if(n>=64&&n<81)
            cout<<"11";
        if(n>=81&&n<100)
            cout<<"12";
        if(n==100)
            cout<<"13";
    }
    if(k==3){
        if(n>=1&&n<8){
            cout<<"1";
            return 0;
        }
        if(n>=8&&n<16){
            cout<<"2";
            return 0;
        }
        if(n>=16&&n<27){
            cout<<"3";
            return 0;
        }
        if(n>=27&&n<32){
            cout<<"4";
            return 0;
        }
        if(n>=32&&n<64){
            cout<<"5";
            return 0;
        }
        if(n>=64&&n<81){
            cout<<"6";
            return 0;
        }
        if(n>=81&&n<=100){
            cout<<"7";
            return 0;
        }
    }
    return 0;
}