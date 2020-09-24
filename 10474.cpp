#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N,Q,c=1;
    while(cin >> N >> Q)
    {
        if(N==0&&Q==0)
            break;
        int place[10000]={0},finding[10000]={0},ans[10000][2]={{0}},k=0;
        for(int i=0;i<N;i++)
            cin >> place[i];
        sort(place,place+N);
        for(int i=0;i<Q;i++)
            cin >> finding[i];
        for(int j=0;j<Q;j++)
            for(int i=0;i<N;i++)
                if(finding[j]==place[i])
                {
                    if(i==0)
                    {
                        ans[j][0]=finding[j];
                        ans[j][1]=i+1;
                    }
                    if(place[i]!=place[i-1])
                    {
                        ans[j][0]=finding[j];
                        ans[j][1]=i+1;
                    }
                }
        cout << "CASE# " << c << ":" << endl;
        c++;
        for(int i=0;i<Q;i++)
        {
            if(ans[i][1]!=0)
                cout << ans[i][0] << " found at " << ans[i][1] << endl;
            else
                cout << finding[i] << " not found" << endl;
        }
    }
}
