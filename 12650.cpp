#include <iostream>
using namespace std;
int main()
{
    int N,R,x,c;
    while(cin >> N >> R)
    {
        c=N;
        int volunteers[10000]={0};
        for(int i=1;i<=R;i++)
        {
            cin >> x;
            volunteers[x]=1;
        }
        for(int i=1;i<=N;i++)
            if(volunteers[i]==0)
            {
                c--;
                cout << i << ' ';
            }
        if(c==N)
            cout << '*';
        cout << endl;
    }
}
