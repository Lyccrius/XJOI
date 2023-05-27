	#include<bits/stdc++.h>
	using namespace std;
	struct type
	{
		int from;
		int to;
	};
	type line[5010];//train way
	int go[5010][5010][2];//a_b
	int sta,tra,fir;//number of station,number of train way,the first station
	int used[5010];
	int need[5010];
	int find(int line_n,int forword)
	{
		if(forword)
		{
			need[line[line_n].to]=1;
		}
		else
		{
			need[line[line_n].from]=1;
		}
		for(int i=1;i<=tra;i++)
		{
			if(used[i]==0&&go[line_n][i][forword])
			{
				used[i]=1;
				find(i,forword);
				used[i]=0;
			}
		}
		return 0;
	}
	int main()
	{
		freopen("station.in","r",stdin);
		freopen("station.out","w",stdout);
		cin>>sta>>tra>>fir;
		for(int i=1;i<=tra;i++)
		{
			int from,to;
			cin>>from>>to;
			line[i].from=from;
			line[i].to=to;
		}
		for(int i=1;i<=tra;i++)
		{
			for(int j=i+1;j<=tra;j++)
			{
				if(line[j].from>=line[i].from&&line[j].from<=line[i].to)
				{
					//be the forword
					go[i][j][1]=1;
				}
				if(line[j].to>=line[i].from&&line[j].to<=line[i].to)
				{
					//be the back
					go[i][j][0]=1;
				}
				
			}
		}
		for(int i=1;i<=tra;i++)
		{	
			if(line[i].from<=fir&&line[i].to>=fir)
			{
				find(i,1);
				find(i,0);
			}
		}
		for(int i=1;i<=sta;i++)
		{
			if(need[i]&&i!=fir)
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
