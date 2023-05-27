#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>s;
bool prime(int x){
    for (int i = 0;i < s.size();i++){
        if (x == s[i]) return false;
    }
    return true;
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin >> n >> k;
    if (k == 1) cout << n;
    else{
        int t = 1;
        for (int i = 2;i * i <= n;i++){
            if (prime(i)){
                int p = i,l = 1;
                while (p <= n){
                    p *= i;
                    s.push_back(p);
                    l++;
                    if (l >= k && p <= n){
                        t++;
                    }
                }
            }
        }
        cout << t;
    }
    return 0;
}
