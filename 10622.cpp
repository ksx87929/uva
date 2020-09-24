#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector < vector < long long int > > ALL;
    long long int x;
    for(int i=2;i<=65536;i++)
    {
        long long int temp=1;
        vector<long long int> TEMP;
        while(temp<4294967297)
        {
            TEMP.push_back(temp);
            temp=temp*i;
        }
        ALL.push_back(TEMP);
    }
    while(cin >> x)
    {
        int BREAK=0;
        if(x==0)
            break;
        for(int i=0;i<65536;i++)
        {
            for(int j=0;j<ALL[i].size();j++)
            {
                if(j%2==0&&x==ALL[i][j])
                {
                    cout << j << endl;
                    BREAK++;
                    break;
                }
                else if(j%2==1&&x==-ALL[i][j])
                {
                    cout << j << endl;
                    BREAK++;
                    break;
                }
                else if(j%2==1&&x==ALL[i][j])
                {
                    cout << j << endl;
                    BREAK++;
                    break;
                }
            }
            if(BREAK!=0)
                break;
        }
        if(BREAK==0)
            cout << 1 << endl;
    }
}
