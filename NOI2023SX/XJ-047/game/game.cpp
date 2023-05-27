#include<stdio.h>
int n,m,k,total,ans=0,min,min1=-1,l,s[1005][3],t[1005][3],s1[1005],t1[1005],s2[1005],t2[1005],t3[1005],s3[1005];
void gl()
{
	int i,j;
	n=0;m=0;total=0;ans=0;min1=-1;
	for(i=1;i<=1004;i++)
	{
		for(j=1;j<=2;j++)
		{
			s[i][j]=0;
			t[i][j]=0;
		}
		s1[i]=0; 
		t1[i]=0;
		s2[i]=0;
		t2[i]=0;
		s3[i]=0;
		t3[i]=0;
	}
}
void pdt(int w)
{
	int i,j,f;
	if(w>n)
	{
		ans=1;
		return ;
	}
	for(i=t[w][1];i<=t[w][1]+t3[w];i++)
	{
		f=0;
		for(j=1;j<w;j++)
		{
			if(t2[j]==i)
			{
				f=1;
			}
		}
		if(f==0)
		{
			t2[w]=i;
			pdt(w+1);
		}
	}
}
void findt(int w)
{
	int i,j,f=0;
	if(w>n)
	{
		total=0;
		for(i=1;i<=n;i++)
		{
			if(s2[i]==t2[i])
			{
				total++;
			}
		}
		if(total<min)
		{
			min=total;
		}
		return ;
	}
	for(i=t[w][1];i<=t[w][1]+t3[w];i++)
	{
		f=0;
		for(j=1;j<w;j++)
		{
			if(t2[j]==i)
			{
				f=1;
			}
		}
		if(f==0)
		{
			t2[w]=i;
			findt(w+1);
		}
	}
}
void makes(int w)
{
	int i,j;
	if(w>n)
	{
		min=99999999;
		findt(1);
		if(min>min1)
		{
			min1=min;
		}
		return ;
	}
	for(i=s[w][1];i<=s[w][1]+s3[w];i++)
	{
		s2[w]=i;
		makes(w+1);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j,p,jiao,o;
	scanf("%d",&p);
	for(o=1;o<=p;o++)
	{
		gl();
		min1=-1;
		scanf("%d%d",&n,&m);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&l);
			for(k=1;k<=l;k++)
			{
				scanf("%d",&s[j][++s1[j]]);
			}
			if(l==2 && s[j][s1[j]]<s[j][s1[j]-1])
			{
				jiao=s[j][s1[j]];
				s[j][s1[j]]=s[j][s1[j]-1];
				s[j][s1[j]-1]=jiao;
			}
		}
		for(j=1;j<=n;j++)
		{
			scanf("%d",&l);
			for(k=1;k<=l;k++)
			{
				scanf("%d",&t[j][++t1[j]]);
			}
			if(l==2)
			{
				if(t[j][t1[j]]<t[j][t1[j]-1])
				{
					jiao=t[j][t1[j]];
					t[j][t1[j]]=t[j][t1[j]-1];
					t[j][t1[j]-1]=jiao;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(t1[i]==2)
			{
				t3[i]=t[i][2]-t[i][1];
			}
			else
			{
				t3[i]=0;
			}
			if(s1[i]==2)
			{
				s3[i]=s[i][2]-s[i][1];
			}
			else
			{
				s3[i]=0;
			}
		}
		ans=0;
		pdt(1);
		if(ans==0)
		{
			printf("-1");
			return 0;
		}
		makes(1);
		printf("%d\n",min1);
	}
	return 0;
}
