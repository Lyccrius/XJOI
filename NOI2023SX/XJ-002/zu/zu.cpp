#include<bits/stdc++.h>
using namespace std;
int id,T;
int n,m;
int cntO=0;
int m1X,m1O[3],mxcnt=0,m3[15],m3cnt=0;
char mp[15][15];
bool flag;
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d %d",&id,&T);
    while(T--)
    {
        cin>>n>>m;
        cntO=0;
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        if(m==1)
        {
            flag=0;
            mxcnt=m3cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(mp[i][1]=='O')
                {
                    m1O[++mxcnt]=i;
                }
                else if(mp[i][1]=='X')
                {
                    m1X=i;
                }
                else if(mp[i][1]=='#')
                {
                    m3[++m3cnt]=i;
                }
            }
            if(m1X<m3[1])
            {
                if(m1O[1]<m1X)
                {
                    if(m1O[2]<m1X)
                    {
                        cout<<"Red "<<(m1X-m1O[2])*2-1<<endl;
                        flag=true;
                    }
                    else if(m1O[2]==m1X+1)
                    {
                        cout<<"Red "<<1<<endl;
                        flag=true;
                    }
                    else
                    {
                        cout<<"Red "<<(m1X-m1O[1])*2-1<<endl;
                        flag=true;
                    }
                }
                else
                {
                    if(m1O[1]==m1X+1)
                    {
                        cout<<"Red "<<1<<endl;
                        flag=true;
                    }
                    else
                    {
                        cout<<"Black "<<(m1X-1)*2<<endl;
                        flag=true;
                    }
                }
            }
            else
            {
                if(m1O[1]<m1X)
                {
                    if(m1O[2]<m1X)
                    {
                        cout<<"Red "<<(m1X-m1O[2])*2-1<<endl;
                        flag=true;
                    }
                    else if(m1O[2]==m1X+1)
                    {
                        cout<<"Red "<<1<<endl;
                        flag=true;
                    }
                }
                else
                {
                    if(m1O[1]==m1X+1)
                    {
                        cout<<"Red "<<1<<endl;
                        flag=true;
                    }
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(cntO==2)
                {
                    break;
                }
                for(int j=1;j<=m;j++)
                {
                    if(mp[i][j]=='O')
                    {
                        if(i==1&&j==1)
                        {
                            if(mp[i][j+1]=='#'&&mp[i+1][j]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(i==n&&j==1)
                        {
                            if(mp[i-1][j]=='#'&&mp[i][j+1]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(i==1&&j==m)
                        {
                            if(mp[i+1][j]=='#'&&mp[i][j-1]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(i==n&&j==m)
                        {
                            if(mp[i-1][j]=='#'&&mp[i][j-1]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(i==1)
                        {
                            if(mp[i][j-1]=='#'&&mp[i][j+1]=='#'&&mp[i+1][j]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(i==n)
                        {
                            if(mp[i][j-1]=='#'&&mp[i][j+1]=='#'&&mp[i-1][j]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(j==1)
                        {
                            if(mp[i-1][j]=='#'&&mp[i+1][j]=='#'&&mp[i][j+1]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else if(j==m)
                        {
                            if(mp[i-1][j]=='#'&&mp[i+1][j]=='#'&&mp[i][j-1]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                        else
                        {
                            if(mp[i-1][j]=='#'&&mp[i][j-1]=='#'&&mp[i][j+1]=='#'&&mp[i+1][j]=='#')
                            {
                                cntO++;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if(flag==true)
        {
            continue;
        }
        if(cntO==2)
        {
            printf("Black 0\n");
            continue;
        }
        else
        {
            printf("Tie\n");
            continue;
        }
    }
    return 0;
}
/*
 🤡🤡🤡🤡    🤡🤡🤡🤡  🤡🤡🤡🤡🤡
🤡          🤡          🤡
🤡          🤡          🤡
🤡          🤡          🤡🤡🤡🤡
🤡          🤡          🤡
 🤡🤡🤡🤡    🤡🤡🤡🤡   🤡

🔞        🔞    🔞🔞🔞     🔞🔞🔞  
🔞🔞      🔞  🔞      🔞     🔞
🔞  🔞    🔞  🔞      🔞     🔞 
🔞    🔞  🔞  🔞      🔞     🔞
🔞      🔞🔞  🔞      🔞     🔞
🔞        🔞    🔞🔞🔞     🔞🔞🔞
*/
