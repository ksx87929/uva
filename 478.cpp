#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape
{
public:
    virtual bool in_area(double,double) = 0;
};

class Rectangle : public Shape
{
private:
    double x1,y1,x2,y2;

public:
    Rectangle(double,double,double,double);
    bool in_area(double,double);
};

Rectangle :: Rectangle(double X1,double Y1,double X2,double Y2)
{
    x1=X1;
    y1=Y1;
    x2=X2;
    y2=Y2;
}

bool Rectangle :: in_area(double a,double b)
{
    if(x1<a&&x2>a&&y1>b&&y2<b)
        return true;
    else
        return false;
}

class Circle : public Shape
{
private:
    double x,y,r;

public:
    Circle(double,double,double);
    bool in_area(double,double);
};

bool Circle :: in_area(double a,double b)
{
    double dotR;
    dotR=(a-x)*(a-x)+(b-y)*(b-y);
    if(dotR-r*r>0.0000001)
        return false;
    else
        return true;
}
Circle :: Circle(double X,double Y,double R)
{
    x=X;
    y=Y;
    r=R;
}
class Triangle : public Shape
{
private:
    double x1,y1,x2,y2,x3,y3;

public:
    Triangle(double,double,double,double,double,double);
    bool in_area(double,double);
};

Triangle :: Triangle(double X1,double Y1,double X2,double Y2,double X3,double Y3)
{
    x1=X1;
    y1=Y1;
    x2=X2;
    y2=Y2;
    x3=X3;
    y3=Y3;
}

bool Triangle :: in_area(double a,double b)
{
    double ABC,DAB,DAC,DBC;
    ABC=(x2-x1)*(y3-y1)-((y2-y1)*(x3-x1));
    ABC=abs(ABC)/2;
    DAB=(x1-a)*(y2-b)-((x2-a)*(y1-b));
    DAB=abs(DAB)/2;
    DAC=(x1-a)*(y3-b)-((x3-a)*(y1-b));
    DAC=abs(DAC)/2;
    DBC=(x2-a)*(y3-b)-((x3-a)*(y2-b));
    DBC=abs(DBC)/2;
    if(abs(DAB+DAC+DBC-ABC)<0.000001)
    {
        if(DAB!=0&&DBC!=0&&DAC!=0)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    char SHAPE;
    double x1,y1,x2,y2,x3,y3,x,y,r,BREAK=0;
    vector <Shape*> v;
    while(cin >> SHAPE)
    {
        if(SHAPE=='r')
        {
            cin >> x1 >> y1 >> x2 >> y2;
            Shape *s=new Rectangle(x1,y1,x2,y2);
            v.push_back(s);
        }
        else if (SHAPE=='c')
        {
            cin >> x >> y >> r;
            Shape *s=new Circle(x,y,r);
            v.push_back(s);
        }
        else if (SHAPE=='t')
        {
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            Shape *s=new Triangle(x1,y1,x2,y2,x3,y3);
            v.push_back(s);
        }
        if (SHAPE=='*')
        {
            int dot=1;
            while (cin >> x >> y)
            {
                int c=0;
                if(x==9999.9&&y==9999.9)
                {
                    BREAK++;
                    break;
                }
                for(int i=0;i<v.size();i++)
                    if(v[i]->in_area(x,y))
                    {
                        cout << "Point " << dot << " is contained in figure " << i+1 << endl;
                        c++;
                    }
                if(c==0)
                    cout << "Point " << dot << " is not contained in any figure" << endl;
                dot++;
            }
        }
        if(BREAK==1)
            break;
    }
}
