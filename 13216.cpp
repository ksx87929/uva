#include<iostream>
using namespace std;
int main()
{
    int n;
    string A;
    cin >> n;
    while(n--)
    {
        cin >> A;
        int S=0;
        S=A[A.size()-1]-'0';
        if(A=="0")
            cout << '1' << endl;
        else if(A=="1")
            cout << "66" << endl;
        else if(S%5==0)
            cout << "76" << endl;
        else if(S%5==1)
            cout << "16" << endl;
        else if(S%5==2)
            cout << "56" << endl;
        else if(S%5==3)
            cout << "96" << endl;
        else if(S%5==4)
            cout << "36" << endl;
    }
}
