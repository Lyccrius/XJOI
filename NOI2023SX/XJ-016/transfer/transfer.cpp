#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int sid, n, m, k, pt, path[MAXN], a[MAXN], f[MAXN][2], g[MAXN];
struct node
{
	int v, w;
} b[MAXN];
bool cmp(node jta, node tql)
{
	return jta.w < tql.w;
}
priority_queue <int, vector<int>, greater<int> > q;
vector<int> e[MAXN];
vector<int> x[MAXN];
pair<int, int> data[MAXN];
void dfs(int u, int p)
{
    int sz = e[u].size(), szx = x[u].size();
    if (sz == 0) 
    {
		//cout << x[u][szx-1] << '\n';
        if (szx > 0) a[u] = x[u][szx-1], f[u][1] = x[u][szx-1];
        else a[u] = 0; 
        f[u][0] = 0;
        return;
    }
    for (int i = 0; i < sz; i++)
    {
		int v = e[u][i];
        if (v == p) continue;
        dfs(v, u);
    }
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
		int v = e[u][i];
		sum += f[v][1];
		g[i] = f[v][1] - f[v][0];
	}
	sort(g, g+sz); f[u][0] = sum;
	if (szx > 0) f[u][1] = sum + x[u][szx - 1];
	else f[u][1] = sum;
	for (int i = 0; i < min(szx, sz); i++)
	{
		//if (i == szx-1) f[u][1] = max(f[u][0] + x[u][0], f[u][1]);
		f[u][1] = max(f[u][0] + x[u][szx-1-i], f[u][1]);
		f[u][0] = max(sum-g[i]+x[u][szx-1-i], f[u][0]);
		sum = sum-g[i]+x[u][szx-1-i];
		//cout << u << ' '  << f[u][0] << '\n'; 
		//if (f[u][0] != sum) f[u][1] = max(f[u][0] + x[u][szx-1-i], f[u][1]);
	}
	if (szx > sz) f[u][1] = max(f[u][0] + x[u][szx-sz-1], f[u][1]);
	
}

int main()
{
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
    cin >> sid;
    cin >> n >> k >> m;
    int p, v, xx;
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        e[p].push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> xx >> v;
        data[i] = {xx, v};
        x[xx].push_back(v);
    }
    
    for (int i = 1; i <= 2500; i++) sort(x[i].begin(), x[i].end());
    //for (int i = 1; i <= n; i++)
    //{
	//	cout << i << ":";
	//	for (auto p: x[i])
	//	{
	//		cout << p << ' ';
	//	}
	//	cout << endl;
	//}
    dfs(1, -1);
    //for (int i = 1; i <= n; i++)
   // {
		//cout << i << ":";
		//cout << f[i][1] << ' ' << f[i][0] << '\n';
	//}
    cout << f[1][1] << ' ';
    int op;
    for (int i = 1; i <= m; i++)
    {
		for (int j = 1; j <= n; j++) f[j][0] = f[j][1] = 0;
        cin >> op;
        if (op == 1)
        {
            cin >> xx >> v;
            data[++k] = {xx, v};
            x[xx].push_back(v);
            int sz = x[xx].size();
            for (int j = sz-1; j >= 1; j--)
            {
                if (x[xx][j] < x[xx][j-1]) swap(x[xx][j], x[xx][j-1]);
                else break;
            }
        }
        else
        {
            int id;
            cin >> id;
            xx = data[id].first; v = data[id].second;
            //int sz = x[xx].size();
            for(auto p = x[xx].begin(); p != x[xx].end(); ++p)
            {
                if (*p == v)
                {
                    auto itt = p; ++itt;
                    x[xx].erase(p, itt);
                    break;
                }
            }
        }
        dfs(1, -1);
        cout << f[1][1] << ' ';
    }
    return 0;
}
