#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string str1="",str2="";
    while(getline(cin,str1))
    {
        int letstr1[26]={0},letstr2[26]={0},fre[26]={0};
        getline(cin,str2);
        for(int i=0;i<str1.size();i++)
            letstr1[str1[i]-'a']++;
        for(int i=0;i<str2.size();i++)
            letstr2[str2[i]-'a']++;
        for(int i=0;i<26;i++)
            fre[i]=min(letstr1[i],letstr2[i]);
        for(int i=0;i<26;i++)
            if(fre[i]!=0)
                for(int j=0;j<fre[i];j++)
                    cout << char('a'+i);
        cout << endl;
    }
}
