//Bisection rule to find the root of an equation
//Basic code devoloped by Paramesh Chandra

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

//two number structure
struct two_numbers{
  float x,y;
};

//Function to calculate the equation
float func(float x)
{
    return(x*x-100);
}

//root guessing function
two_numbers root_ini()
{
  float x;
  int count=0;
  two_numbers two;
  two.x=0;
  two.y=0;
  for(x=-10000;x<=10000;x=x+.5)
  {
    if(func(x-.1)*func(x+.1)<0)
    {
      cout<<"One of the guess value is: "<<x<<endl;
      count++;
      if(count == 1)
        two.x = x;
      else  
        two.y = x;
    }
  }
return(two);
}

//Main programme
int main(void)
{
    float a,b,epsilon, x, arr[10];
    two_numbers two;
    int i;
    ofstream outfile("bisection_w_root_finder.out");
    outfile<<"Summery of the result"<<endl;
    outfile<<"------------------------------------------"<<endl;
    cout<<"Enter the accuracy(epsilon): ";
    cin>>epsilon;
    two = root_ini();
    arr[0] = two.x;
    arr[1] = two.y;
    for(i = 0;i<2;i++)
    {
      a=arr[i]-.5;
      b=arr[i]+.5;
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
    while(abs(func(x))>epsilon);
    cout<<"The one of root is : "<<x<<endl;
    outfile<<"The one of root is : "<<x<<endl;
    }
    cout<<"Summery of the iterration can be found in bisection.out file"<<endl;
}
