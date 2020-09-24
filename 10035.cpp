#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    int a,b;
    while(cin >> a >> b)
    {
        int c=0,ans=0;
        if(a==0&&b==0)
            break;
        while(a!=0||b!=0)
        {
            if(a%10+b%10+c>=10)
            {
                ans++;
                c=1;
            }
            else
                c=0;
            a/=10;
            b/=10;
        }
        if(ans==0)
            cout << "No carry operation." << endl;
        else if(ans==1)
            cout << "1 carry operation." << endl;
        else
            cout << ans <<" carry operations." << endl;
    }
}
