#include <iostream>
using namespace std;
void fun(string s1,string s2,int n1,int n2)
{
    int mat[n1+1][n2+1];
    for(int i=0;i<n1+1;i++)
    {
        for(int j=0;j<n2+1;j++)
        {
            mat[i][j] = 0;
        }
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
            {
                mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
            }
        }
    }
    cout<<mat[n1][n2]<<endl;
    return;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1, n2;
	    cin>>n1>>n2;
	    string s1, s2;
	    cin>>s1>>s2;
	    fun(s1,s2,n1,n2);
	}
	return 0;
}