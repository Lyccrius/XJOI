#include <bits/stdc++.h>
using namespace std;
int id, n, m, T;
char s[105][105];
int x[4], y[4], dx[4] = {0,1,-1,0}, dy[4] = {1, 0, 0, -1};
int cnt;
/*
int fun1(char st){
    int cnt = 0;
    if (st == 'L')
    {
        while(1)
        {
            while(y1 > 1)
            {
                y1--; y2--;
                cnt += 2;
            }
            while(x1 - x2 > 1 && y1 < y2)
            {
                x2++; y1++; cnt += 2;
            }
            if (x1 - x2 == 1 && y1 < y2)
            {
                return cnt + 2;
            }
            else
            {
                cnt += 2;
                if (x1 - x2 > 1) x2++;
                y1++;
            }
            
            while(y1 < m)
            {
                y1++; y2++;
                cnt += 2;
            }
            while(x1 - x2 > 1 && y1 > y2)
            {
                x2++; y1--; cnt += 2;
            }
            if (x1 - x2 == 1 && y1 > y2)
            {
                return cnt + 2;
            }
            else
            {
                cnt += 2;
                if (x1 - x2 > 1) x2++;
                y1--;
            }
        }
    }
    else
    {
        while(1)
        {
            while(y1 < m)
            {
                y1++; y2++;
                cnt += 2;
            }
            while(x1 - x2 > 1 && y1 > y2)
            {
                x2++; y1--; cnt += 2;
            }
            if (x1 - x2 == 1 && y1 > y2)
            {
                return cnt + 2;
            }
            else
            {
                cnt += 2;
                if (x1 - x2 > 1) x2++;
                y1--;
            }
            
            while(y1 > 1)
            {
                y1--; y2--;
                cnt += 2;
            }
            while(x1 - x2 > 1 && y1 < y2)
            {
                x2++; y1++; cnt += 2;
            }
            if (x1 - x2 == 1 && y1 < y2)
            {
                return cnt + 2;
            }
            else
            {
                cnt += 2;
                if (x1 - x2 > 1) x2++;
                y1++;
            }
        }
    }
}*/
int main()
{
	freopen("zu.in", "r", stdin);
	freopen("zu.out", "w", stdout);
    cin >> id >> T;
    while(T--)
    {
        int p = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> s[i][j];
                if (s[i][j] == 'O')
                {
                    x[++p] = i;
                    y[p] = j;
                }
                else if (s[i][j] == 'X')
                {
                    x[0] = i; y[0] = j;
                }
            }
        }
        bool flag = 1;
        for (int i = 1; i <= 2; i++)
        {
            if (flag == 0) break;
            for (int j = 0; j < 4; j++)
            {
                if (s[x[i]+dx[j]][y[i]+dy[j]] != '#' && s[x[i]+dx[j]][y[i]+dy[j]] != 'O' && s[x[i]+dx[j]][y[i]+dy[j]] != '\0')
                {
                    flag = 0; break;
                }
            }
        }
        if (flag) 
        {
            cout << "Black 0" << '\n';
            continue;
        }
        if (x[1]-1 == '#') swap(x[1], x[2]), swap(y[1], y[2]);
         int d1 = -x[1] + x[0], d2 = abs(y[1] - y[0]);
         if ((d1 == 0 && d2 == 1) || (d2 == 0 && abs(d1) == 1))
         {
             cout << "Red 1\n"; continue;
         }
        if (id >= 1 && id <= 4)
        {
			cout << "Tie\n"; continue;
		}
        else if (m == 1)
        {
            int t1 = 0, t2 = 0, p1 = 1, p2 = n;
            for (int i = x[0]+1; i <= n; i++)
            {
                if (s[i][1] == '#') 
                {
                    p2 = i; break;
                }
                else if (s[i][1] == 'O')
                {
                     t2 = 1; p2 = i; break;
                }
            }
            for (int i = x[0]-1; i >= 1; i--)
            {
                if (s[i][1] == '#') 
                {
                    p1 = i; break;
                }
				if (s[i][1] == 'O')
				{
                    t1 = 1; p1 = i; break;
				}
            }
            if (t1 == 1 && t2 == 1)
            {
                if (x[0] - p1 == 2 && p2 - x[0] == 2)
                {
                    if (s[p1-1][1] != '.' && s[p2+1][1] != '.')
                    {
                        cout << "Black 2" << '\n';
                    }
                    else 
                    {
                        cout << "Red 5" << '\n';
                    }
                }
                else 
                {
                    int d1 = max(x[0]-p1, p2-x[0]), d2 = min(x[0]-p1, p2-x[0]);
                    if (d2 == 2) cout << "Red " << (d1-2)*2+1 << '\n';
                    else if (d2 == 3) cout << "Red " << (d1 - 2) * 2 + 3 << '\n';
                    else if (d2 == 4) cout << "Red" << (d1 - 2) * 2 + 5 << '\n';
                }
            }
            else if (t1 == 0 && t2 == 0 && p1 != 1)
            {
                cout << "Tie" << '\n';
            }
            else if (t1 == 0 && t2 == 1 && p1 == 1)
            {
                cout << "Black " << x[0]*2-2 << '\n';
            }
            else if (t1 == 1 && t2 == 0)
            {
                p2 = 1;
                for (int j = p1-1; j >= 1; j--)
                {
                    if (s[j][1] == '#')
                    {
                        p2 = j; break;
                    }
                }
                if ((x[0] - p1)%2 == 1)
                {
                    cout << "Red" << x[0]-p1 + 2 * (n - x[0]) << '\n';
                }
                else
                {
                    cout << "Black " << x[0] - p1 + 2 * (p1 - p2) << '\n';
                }
            }
            continue;
            
        }
        else
        {
			cout << "Tie\n";
		}
        
    }
    return 0;
}
