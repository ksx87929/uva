#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int T,N,M,a,b;
    cin >> T;
    for(int q=0;q<T;q++)
    {
        char matrix[10][10]={{}},outputmatrix[10][10]={{}};
        string opera;
        cin >> N;
        for(int i=0;i<N;i++)
            for( int j=0;j<N;j++)
            {
                cin >> matrix[i][j];
                outputmatrix[i][j]=matrix[i][j];
            }
        cin >> M;
        for(int p=0;p<M;p++)
        {
            cin >> opera;
            if(opera=="row")
            {
                cin >> a >> b;
                for(int i=0;i<N;i++)
                    swap(outputmatrix[a-1][i],outputmatrix[b-1][i]);
            }
            else if(opera=="col")
            {
                cin >> a >> b;
                for(int i=0;i<N;i++)
                    swap(outputmatrix[i][a-1],outputmatrix[i][b-1]);
            }
            else if(opera=="inc")
            {
                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(outputmatrix[i][j]<'9')
                            outputmatrix[i][j]=outputmatrix[i][j]+1;
                        else if(outputmatrix[i][j]=='9')
                            outputmatrix[i][j]='0';
                    }
            }
            else if(opera=="dec")
            {
                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(outputmatrix[i][j]>'0')
                            outputmatrix[i][j]=outputmatrix[i][j]-1;
                        else if(outputmatrix[i][j]=='0')
                            outputmatrix[i][j]='9';
                    }
            }
            else if(opera=="transpose")
            {
                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                        matrix[i][j]=outputmatrix[j][i];
                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                        outputmatrix[i][j]=matrix[i][j];
            }
        }
            cout << "Case #" << q+1 << endl;
            for(int i=0;i<N;i++)
                cout << outputmatrix[i] << endl;
            cout << endl;
    }
}
