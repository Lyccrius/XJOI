#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, k;
int temp;
int ans = 0;
int main(){
    freopen("power.in","r", stdin);
    freopen("power.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = k; j <= n; j++){
            for(int q = j; q >= 1; q--){
                
                temp = i * i;
            }
        
        }
        if(temp <= n) ans ++;
        else break;
    }
    cout << ans+3 << endl;
    return 0;
}