#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int h)
{
	int n1 = m-l+1;
	int n2 = h-m;
	int a1[n1], a2[n2];
	for(int i = 0; i<n1;i++)
		a1[i] = a[l+i];
	for(int i=0; i<n2;i++)
		a2[i] = a[m+i+1];
	int p = 0;
	int q = 0;
	int k = l;
	while(p<n1 && q<n2)
	{
		if(a1[p]>a2[q])
			a[k] = a2[q++];
		else a[k] = a1[p++];
		k++;
	}
	while(p<n1)
		a[k++] = a1[p++];
	while(q<n2)
		a[k++] = a2[q++];
	
}
void mergeSort(int a[], int l, int h)
{
	if(l<h)
	{
		int m = (h-l)/2 + l;
		mergeSort(a,l,m);
		mergeSort(a,m+1,h);
		merge(a,l,m,h);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}