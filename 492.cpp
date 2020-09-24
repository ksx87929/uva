#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char x,output[10000]={};
    int i=0;
    while(cin.get(x))
    {
        if(isalpha(x))
        {
            output[i]=x;
            i++;
        }
        else
        {
            if(i>0)
            {
                if(output[0]=='A'||output[0]=='E'||output[0]=='I'||output[0]=='O'||output[0]=='U'||output[0]=='a'||output[0]=='e'||output[0]=='i'||output[0]=='o'||output[0]=='u')
                {
                    for(int j=0;j<i;j++)
                        cout << output[j];
                    cout << "ay";
                }
                else
                {
                    for(int j=1;j<i;j++)
                        cout << output[j];
                    cout << output[0] << "ay";
                }
                i=0;
            }
            cout << x;
        }
    }
}
