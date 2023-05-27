#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
vector<int> v;
int limit[1000005];
int fast_power(int a, int b)
{
    int res = 1, t = a;
    while(b)
    {
        if (b & 1) res *= t;
        t *= t;
        b >>= 1;
    }
    return res;
}
signed main()
{
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int lg = 0, t = 1;
    if (k == 1)
    {
		cout << n;
		return 0;
	}
    while(t <= n)
    {
        t *= 2;
        lg++;
    }
    lg--;
    v.push_back(1);
    limit[11] = 17;
    limit[12] = limit[13] = 16;
	limit[14] = limit[15] = 15;
	limit[19] = limit[16] = limit[17] = limit[18] = 14;
	limit[20] = limit[21] = limit[22] = limit[23] = limit[24] = 13;
	for (int i = 25; i <= 31; i++) limit[i] = 12;
	for (int i = 32; i <= 43; i++) limit[i] = 11;
	for (int i = 44; i <= 63; i++) limit[i] = 10;
	for (int i = 64; i <= 100; i++) limit[i] = 9;
	int q = 8, u = 1e18;
	for (int i = 101; i <= 1000000; i++)
	{
		if (fast_power(i,q)<u)limit[i] = q;
		else if (fast_power(i,q)==u) limit[i] = q--;
		else limit[i] = --q;
	}
    int cnt = 0, s;
    for (int i = 2; i <= 1000000; i++)
    {
		t = fast_power(i, 2); cnt = k+!(k%2)-1;
		for (int j = fast_power(i, k+!(k%2)); j <= n; j*=i)
		{
			cnt++;
			if (cnt > limit[i] && i > 10) break;
			if (j <= t) break;
			if (k==2&&(cnt&1)==0)
			{
				t = j; continue;
			}
			s = sqrt(j);
			if (s*s!=j || k > 2)v.push_back(j);
			t = j;
		}
	}
	
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    //for (auto p:v)
    //{
	//	cout << p << ' ' ;
	//}
    int ans = v.size();
    if (k == 2) ans += sqrt(n) - 1;
    cout << ans;
    return 0;
}
