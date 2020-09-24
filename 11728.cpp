#include <iostream>
using namespace std;
int main()
{
    int S,factorsum[1001]={0},times=1,temp,c,place=0;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=i;j++)
            if(i%j==0)
                factorsum[i]+=j;
    while(cin >> S)
    {
        c=0;
        place=0;
        if(S==0)
            break;
        for(place=S;place>=1;place--)
            if(factorsum[place]==S)
                break;
        if(place==0)
            cout << "Case " << times << ": " << "-1" << endl;
        else
            cout << "Case " << times << ": " << place << endl;
        times++;
    }
}
