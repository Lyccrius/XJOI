#include <iostream>
#include <cstdio>
using namespace std;
bool o(bool a,bool b)
{
    if((a==0)&&(b==0))
    {
        return 0;
    }
    return 1;
}
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    int id,T;
    cin>>id>>T;
    int rpx[2],bpx,rpy[2],bpy;
    int flag;
    if(id<=4)
    {
        for(int t=0;t<T;t++)
        {
            flag=0;
            int n,m;
            cin>>n>>m;
            int board[n+2][m+2];
            for(int i=0;i<n+2;i++)
            {
                for(int j=0;j<m+2;j++)
                {
                    if(i==0){board[i][j]=0;continue;}
                    if(j==0){board[i][j]=0;continue;}
                    if(i==n+1){board[i][j]=0;continue;}
                    if(j==n+1){board[i][j]=0;continue;}
                    char s;
                    cin>>s;
                    if(s=='.')board[i][j]=0;
                    if(s=='#')board[i][j]=1;
                    if(s=='O')
                    {
                        board[i][j]=2;
                        rpx[flag]=i;
                        rpy[flag]=j;
                        flag++;
                        continue;
                    }
                    if(s=='X')
                    {
                        board[i][j]=3;
                        bpx=i;
                        bpy=j;
                        continue;
                    }
                }
            }
            if((board[rpx[0]+1][rpy[0]]==1)&&(board[rpx[0]][rpy[0]+1]==1)&&(board[rpx[0]-1][rpy[0]]==1)&&(board[rpx[0]-1][rpy[0]]==1))
            {
                if((board[rpx[1]+1][rpy[1]]==1)&&(board[rpx[1]][rpy[1]+1]==1)&&(board[rpx[1]-1][rpy[1]]==1)&&(board[rpx[1]-1][rpy[1]]==1))
                {
                    cout<<"Black 0"<<endl;
                    continue;
                }
            }
            cout<<"Tie"<<endl;
        }
    }
    else if((id>6)&&(id<=9))
    {
        for(int t=0;t<T;t++)
        {
            flag=0;
            int n,m;
            cin>>n>>m;
            int board[n+2];
            int rpx[2],bpx;
            for(int i=0;i<n+2;i++)
            {
                if(i==0){board[i]=0;continue;}
                if(i==n+1){board[i]=0;continue;}
                char s;
                cin>>s;
                if(s=='.')board[i]=0;
                if(s=='#')board[i]=1;
                if(s=='O')
                {
                    board[i]=2;
                    rpx[flag]=i;
                    flag++;
                    continue;
                }
                if(s=='X')
                {
                    board[i]=3;
                    bpx=i;
                    continue;
                }
            }
            for(int i=1;;i++)
            {
                if(board[i]==3)
                {
                    flag=1;
                    break;
                }
                if(board[i]==1)
                {
                    flag=0;
                    break;
                }
                if(board[i]==2)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<"Black "<<bpx-1<<endl;
                continue;
            }
            board[bpx+1]=4;
            board[bpx-1]=4;
            if(o(board[rpx[0]+1]==4,board[rpx[0]+1]==1)&&o(board[rpx[0]-1]==4,board[rpx[0]-1]==1)&&o(board[rpx[1]+1]==4,board[rpx[1]+1]==1)&&o(board[rpx[1]-1]==4,board[rpx[1]-1]==1))
            {
                cout<<"Black 2"<<endl;
                continue;
            }
            if((board[bpx+2]==2)&&(board[bpx-3]==2))
            {
                cout<<"Red 3"<<endl;
                continue; 
            }
            if((board[bpx+3]==2)&&(board[bpx-2]==2))
            {
                cout<<"Red 3"<<endl;
                continue;
            }
            if((board[bpx+1]==1)&&(board[bpx-2]==2))
            {
                cout<<"Red 3"<<endl;
                continue;
            }
            if((board[bpx+2]==2)&&(board[bpx-1]==1))
            {
                cout<<"Red 3"<<endl;
                continue;
            }
            cout<<"Tie"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}