#include <iostream>
#include <vector>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
class History
{
private:

    string date;
    int check_number;
    double dollar;
    bool star;

public:

    History(string,int,double);
    void print_history();
    void set_star(bool);
    int get_check_number();
};

History :: History(string a,int b,double c)
{
    date = a;
    check_number = b;
    dollar = c;
    star = false ;
}

int History::get_check_number()
{
    return check_number;
}

void History :: set_star(bool a)
{
       star=a;
}

bool rule(History a, History b)
{
    return a.get_check_number() < b.get_check_number();
}

void History::print_history()
{
    if(star)
        cout<<setw(4)<<check_number<<"* "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
    else
        cout<<setw(4)<<check_number<<"  "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
}

int main()
{
    int N,number,c,row;
    double dollar;
    char enter;
    string check;
    stringstream temp;
    cin >> N;
    cin.get(enter);
    cin.ignore();
    for(int q=0;q<N;q++)
    {
        row=0;
        dollar=0;
        number=0;
        vector <History> STARNOTE;
        while(getline(cin,check))
        {
            c=0;
            string date="",NUM="",DOL="";
            if(check=="")
                break;
            for(int i=0;i<check.size();i++)
            {
                if(check[i]==' ')
                    c++;
                if(c==0)
                    date+=check[i];
                else if(c==1)
                    NUM+=check[i];
                else if(c==2)
                    DOL+=check[i];
            }
            temp.str("");
            temp.clear();
            temp << NUM;
            temp >> number;
            temp.str("");
            temp.clear();
            temp << DOL;
            temp >> dollar;
            History CHECK(date,number,dollar);
            STARNOTE.push_back(CHECK);
        }
        sort(STARNOTE.begin(),STARNOTE.end(),rule);
        for(int i=0;i<STARNOTE.size();i++)
        {
            if(STARNOTE[i+1].get_check_number()-STARNOTE[i].get_check_number()>1)
                STARNOTE[i+1].set_star(true);
            else
                STARNOTE[i+1].set_star(false);
        }
        row=STARNOTE.size()/3;
        if(STARNOTE.size()%3!=0)
            row++;
        for(int i=0;i<row;i++)
        {
            for(int j=i;j<STARNOTE.size();j=j+row)
            {
                if(j!=i)
                    cout << "   ";
                STARNOTE[j].print_history();
            }
            cout << endl;
        }
        if(q+1!=N)
        cout << endl;
    }
}
