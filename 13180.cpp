#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int str[1000],i,c,x;
    while(1)
    {
        int str[1000]={},i=0,c=0;
        while(1)
        {
            cin >> x;
            str[i]=x;
            i++;
            if(x==0)
                break;
        }
        if(str[0]==0)
            break;
        sort(str,str+i);
        for(int j=1;j<i;j=j+2)
            if(str[j]==str[j+1])
                c++;
        if((i/2)-1==c&&i>2&&i%2==0)
        {
            for(int j=1;j<i;j=j+2)
                cout << str[j] << ' ';
            for(int k=i-2;k>2;k=k-2)
                cout << str[k] << ' ';
            cout << str[2] << endl;
        }
        else if(i==2&&c==0)
            cout << str[1] << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
