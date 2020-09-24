#include<iostream>
using namespace std;
int main()
{
    int n,humble[5842]={1},temp[4],minimum,countnum[4]={0},bubble[4],input[4]={2,3,5,7};;
    for(int i=1;i<5842;i++)
    {

        for(int j=0;j<4;j++)
        {
            temp[j] = humble[countnum[j]]*input[j];
            bubble[j] = humble[countnum[j]]*input[j];
        }
        for(int j=2;j>=0;j--)
            for(int k=0;k<=j;k++)
                if(bubble[k]>bubble[k+1])
                    swap(bubble[k],bubble[k+1]);
        minimum = bubble[0];
        if(minimum==temp[0])
            countnum[0]++;
        if(minimum==temp[1])
            countnum[1]++;
        if(minimum==temp[2])
            countnum[2]++;
        if(minimum==temp[3])
            countnum[3]++;
        humble[i]=minimum;
    }
    while(cin>>n)
    {
        if(n==0)
            break;
        else if (n%10==1&&n%100!=11)
            cout << "The " << n << "st humble number is " << humble[n-1] <<'.'<< endl;
        else if (n%10==2&&n%100!=12)
            cout << "The " << n << "nd humble number is " << humble[n-1] <<'.'<< endl;
        else if (n%10==3&&n%100!=13)
            cout << "The " << n << "rd humble number is " << humble[n-1] <<'.'<< endl;
        else
            cout << "The " << n << "th humble number is " << humble[n-1] <<'.'<< endl;
    }
}

