#include<iostream>
using namespace std;
void printElements(int elements[], int index, int a[])
{
	int i = index;
	while(elements[i]!=i)
	{
		cout<<a[i]<<" ";
		i = elements[i];
		
	}
	cout<<a[i]<<" ";
	cout<<endl;
	return;
}
void lis(int a[], int n)
{
	int lis[n];
	int prev[n];
	for(int i=0;i<n;i++)
	{
		lis[i] = 1;
		prev[i] = i;
	}
	for(int i=1;i<n;i++)
	{
		int prevElem = a[i];
		int len = 0;
		int pre = i;
		for(int j=0;j<i;j++)
		{
			if(len<=lis[j] && a[i]>a[j])
			{
				if(len==lis[j] && a[j]<prevElem)
				{
					prevElem = a[j];
					
				}
				len = lis[j];
				pre = j;
			}
		}
		lis[i] = len+1;
		prev[i] = pre;
	}
	int maxlen = 0;
	int maxIndex = -1;
	for(int i=0;i<n;i++)
	{
		if(maxlen<lis[i])
		{
			maxlen = lis[i];
			maxIndex = i;
		}
		cout<<lis[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<prev[i]<<" ";
	cout<<endl;
	printElements(prev,maxIndex,a);
	
	return;
}
void lis1(int a[], int n)
{
	int lis[n];
	for(int i=0;i<n;i++)
		lis[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[i]>a[j] && lis[j]+1>lis[i])
				lis[i] = lis[j] + 1;
		}
	}
	int max = 1;
	for(int i=0;i<n;i++)
	{
		if(lis[i]>max)
			max= lis[i];
	}
	cout<<max<<endl;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	lis1(a,n);
}