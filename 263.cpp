#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    string num="";
    while(cin >> num)
    {
        if(num=="0")
            break;
        string compare="";
        vector <string> LIST;
        int c=0;
        LIST.push_back(num);
        cout << "Original number was " << num << endl;
        while(1)
        {
            string asstr="",desstr="",TEMP="",num1="";
            long long int descend[5000]={0},ascend[5000]={0},place=0,temp,C=0,des,as;
            sort(num.begin(),num.end());
            for(int i=0;i<num.size();i++)
            {
                if(num[i]=='0')
                    place++;
                else
                    break;
            }
            for(int i=place,z=0;i<num.size();i++,z++)
            {
                ascend[z]=num[i]-'0';
                asstr+=num[i];
            }
            if(asstr=="")
                asstr+='0';
            for(int i=num.size()-1,z=0;i>=0;i--,z++)
            {
                descend[z]=num[i]-'0';
                desstr+=num[i];
            }
            stringstream SStream;
            SStream << desstr;
            SStream >> des;
            SStream.str("");
            SStream.clear();
            SStream << asstr;
            SStream >> as;
            SStream.str("");
            SStream.clear();
            temp=des-as;
            SStream << temp;
            SStream >> num1;
            SStream.str("");
            SStream.clear();
            cout << des << " - " << as << " = " << num1 << endl;
            c++;
            for(int i=0;i<LIST.size();i++)
                if(num1==LIST[i])
                    C++;
            if(C==0)
            {
                num.clear();
                num+=num1;
                LIST.push_back(num1);
            }
            else
                break;
        }
        cout << "Chain length " << c << endl;
        cout << endl;
    }
}
