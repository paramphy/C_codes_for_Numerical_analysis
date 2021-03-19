//Integration of sin(x) 
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

//Function to calculate the equation
float func(float x)
{
  return(sin(x));
}

//Main function
int main(void)
{
  int N,i;
  float a,b,sum=0,area,h,x;
  cout<<"Input lower and upper limit of Integration"<<endl;
  cout<<"Lower limit: ";
  cin>>a;
  cout<<"Upper limit: ";
  cin>>b;
  cout<<"Enter the value of N:";
  cin>>N;
  h=(b-a)/N;
  for(i=1;i<N;i++)
  {
    x=a+h*i;
    sum=sum+func(x);
  }
  area=h*(func(a)+func(b)+2*sum)/2;
  cout<<"The resultent area: "<<area<<endl;
}
