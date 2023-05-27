#include <iostream>

using namespace std;
int chs[10005][10005];

int T, n, m, q;

void init()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			chs[i][j] = 0;
		}
}

int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);

	cin>>T;

	while(T--)
	{
		cin>>n>>m>>q;
		int opt, x, c;
		while(q--)
		{
			cin>>opt>>x>>c;

			if(opt == 0)
			{
				for(int i = 1; i <= m; i++)
				{
					chs[x][i] = c;
				}
			}
			else
			{
				for(int i = 1; i <= n; i++)
				{
					chs[i][x] = c;
				}
			}
			
		}
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cout<<chs[n][m]<<" ";
			}
			cout<<endl;
		}
		init();
	}
	return 0;
}
