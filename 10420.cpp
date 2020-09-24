#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> A;
    while(n--)
    {
        string area,a;
        cin >> area;
        getline(cin,a);
        A.push_back(area);
    }
    sort(A.begin(),A.end());
    A.push_back("");
    int ans=1;
    for(int i=0;i<A.size()-1;i++)
    {
        /*cout << A[i] << endl ;*/
        if(A[i]==A[i+1])
            ans++;
        else
        {
            cout << A[i] << ' ' << ans << endl;
            ans=1;
        }
    }
}
