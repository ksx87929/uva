#include<iostream>
#include<cstring>
using namespace std;
char maze[30][81];
void DFS(int x,int y)
{
    if(maze[x][y]!=' ')
        return;
    maze[x][y]='#';
    DFS(x+1,y);
    DFS(x-1,y);
    DFS(x,y+1);
    DFS(x,y-1);
}
int main()
{
    int N,i,num[30];
    string line;
    cin>>N;
    cin.ignore();
    for(int q=0;q<N;q++)
    {
        i=0;
        line="";
        while(cin.getline(maze[i],81))
        {
            num[i]=strlen(maze[i]);
            if(maze[i][0]=='_')
            {
                for(int j=0;j<num[i];j++)
                    line+='_';
                break;
            }
            i++;
        }
        for(int k=0;k<i;k++)
            for(int j=0;j<num[k];j++)
                if(maze[k][j]=='*')
                {
                    maze[k][j]=' ';
                    DFS(k,j);
                }
        for(int k=0;k<i;k++)
        {
             for(int j=0;j<num[k];j++)
                cout<<maze[k][j];
            cout<<endl;
        }
        cout << line << endl;
    }
}
