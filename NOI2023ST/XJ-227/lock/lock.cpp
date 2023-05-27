#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 0x3f3f3f3f;
ll a[3][150005]={0};
ll T,k,n;
ll solve1(){
	cin >> n;
	ll a;
	ll Min = inf,Max = -inf;
    for(int j = 1; j <= n; j++){
		cin >> a;
		Min = min(a,Min);
		Max = max(a,Max);
    }
    return Max - Min;
}
ll solve2(){
	cin >> n;
	ll Mina = inf,Maxa = -inf,Minb = inf,Maxb = -inf;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
			cin >> a[i][j];
    for(int j = 1; j <= n; j++){
		if(a[1][j] > a[2][j]) swap(a[1][j],a[2][j]);
		Mina = min(a[1][j],Mina);
		Maxa = max(a[1][j],Maxa);
		Minb = min(a[2][j],Minb);
		Maxb = max(a[2][j],Maxb);
	}
    return max(Maxa-Mina, Maxb-Minb);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cin >> T >> k;
    if(k == 1) 	   while(T--) cout << solve1() << endl;
    else if(k == 2)while(T--) cout << solve2() << endl;
    else 		   while(T--) cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
