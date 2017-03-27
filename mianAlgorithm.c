#include<stdio.h>

int sup=3;
int NowLength=0;
int maxlength=0;
int a[100];
int b[100][100];
int c[100][100];
FILE *r;
FILE *w;
int Count(int *a)
{
    for (int i=0;i<100000;i++)
       {
          int x;int p=0;
          while ((scanf("%d",&x)!=EOF))
          {
             if (a[p]==x)  p++;
             if (a[p]<x) {p=0;continue;}
             if (p==NowLength) return 1;
          }
       }

}
int init()
{
    int t;
    for (int i=0;i<10;i++)
    {
		int l=0;
		char c=' ';
		while  (c!='\n')
		{
			l++;
			fscanf(r,"%d%c",&t,&c);
			a[t]++;
		}
		if (l>maxlength) maxlength=l;
	}
	for (int i=0;i<10;i++)
	{
	   if (a[i]>sup) 
	   {
		    b[0][0]++;
			b[b[0][0]][1]=i;
	   } 
	}
   return 0;
}
int countSim(int *a,int *b)// 计算两个数组的最大相似长度(认为是有序数组)
{
	return 0;
}
int countDiff(int *a,int *b)//计算两个数组的不相似度
{
   return 0;
}
int movc2b()
{
  for (int i=0;i<100;i++)
	  for (int j=0;j<100;j++)
		  b[i][j]=c[i][j];

}
void mergaTest(int *a,int *b)
{
	//merga
	int cc[100];
	int i=0,j=0;
	cc[0]=0;
	while (cc[0]<NowLength)
	{
		if (a[i]==b[j]){ cc[0]++;cc[cc[0]]=a[i];}
		else
		{
			cc[0]++;cc[cc[0]]=a[i];
			if (a[i]<b[j]) i++;
		     else j++;
		}
	    if(i=NowLength) break;
	}
	int count=Count(cc);
	if (count>=sup)
	{
		c[0][0]++;
	    int tmp=c[0][0];
		for (int i=1;i<100;i++) c[tmp][i]=cc[i];
	}
	i=0;j=0;
	cc[0]=0;
	while (cc[0]<NowLength)
	{
		if (a[i]==b[j]){ cc[0]++;cc[cc[0]]=a[i];}
		else
		{
			cc[0]++;cc[cc[0]]=b[j];
			if (a[i]<b[j]) i++;
		     else j++;
		}
	    if(i=NowLength) break;
	}
	int count=Count(cc);
	if (count>=sup)
	{
		c[0][0]++;
	    int tmp=c[0][0];
		for (int i=1;i<100;i++) c[tmp][i]=cc[i];
	}
}
void get()
{
	for (int i=1;i<=b[0][0]-NowLength+1;i++)
		 for (int j=i+1;j<b[0][0];j++)
		 {
			int simlength=countSim(b[i],b[j]);
			if (simlength==NowLength-2)
			{

			}
			if (countDiff(b[i],b[j])==1)
			{
			    mergaTest(b[i],b[j]);
			}
		 }
	

}
int main()
{
	FILE *r=fopen("asdasdas","r");
	FILE *w=fopen("asdad","w");
    init();
    for (NowLength=2;NowLength<=maxlength;NowLength++)
	{
		get();
	}
	fprintf(w,"%d",1);
	fclose(r);
	fclose(w);
	return 0;
}
