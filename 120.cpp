#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    string ALLkrabby;
    while(getline(cin,ALLkrabby))
    {
        cout << ALLkrabby << endl;
        stringstream S;
        int num=0,krabby[30]={0},MAX=0,place,now=0,c=0,temp[30]={0};
        S << ALLkrabby;
        while(S >> krabby[num])
        {
            temp[num]=krabby[num];
            num++;
        }
        while(1)
        {
            MAX=0;
            c=0;
            for(int i=0;i<num-now;i++)
                if(MAX<krabby[i])
                {
                    MAX=krabby[i];
                    place=i;
                }
            if(place==num-now-1)
            {
                now++;
                continue;
            }
            if(place!=0)
                cout << num-place <<" ";
            else
                {

                }
            reverse(krabby,krabby+place+1);
            if(now>=num)
                break;
            else
                cout << now+1 << " ";
            reverse(krabby,krabby+num-now);
            if(MAX==krabby[num-now-1])
                now++;
            sort(temp,temp+num);
            for(int i=0;i<num;i++)
                if(krabby[i]!=temp[i])
                    c++;
            if(c==0)
                break;
        }
        cout << "0" << endl;
    }
}
