//Bisection rule to find the root of an equation
//Basic code devoloped by Toton Sarkar

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

//Function to calculate the equation
float func(float x)
{
    return(x*x-5*x+6);
}

//Main programme
int main(void)
{
    float a, b, epsilon, x;
    ofstream outfile("bisection.out");
    outfile<<"Summery of the result"<<endl;
    outfile<<"------------------------------------------"<<endl;
    cout<<"Enter the accuracy(epsilon): ";
    cin>>epsilon;

    do
    {
        cout<<"Enter the guess Value A: ";
        cin>>a;
        cout<<"Enter the guess value B: ";
        cin>>b;
        if(func(a)*func(b)>0)
        {
            cout<<"Your inputs are invalid, please try again..."<<endl;
        }
    }
    while(func(a)*func(b)>0);
    outfile<<"Equation: x2-5x+6"<<endl;
    outfile<<"Initial Guess values:"<<endl;
    outfile<<"A: "<<a<<endl;
    outfile<<"B: "<<b<<endl;
    outfile<<"Iterrations....."<<endl;
    do
    {
        x=(a+b)/2.0;
        if(func(a)*func(x)<0)
        {
            b=x;
        }
        else if(func(b)*func(x)<0)
        {
            a=x;
        }
        outfile<<x<<"\t"<<func(x)<<endl;
    }
    while(abs(a-b)>epsilon);
    cout<<"The one of root is : "<<x<<endl;
    outfile<<"The one of root is : "<<x<<endl;
    cout<<"Summery of the iterration can be found in bisection.out file"<<endl;
}
