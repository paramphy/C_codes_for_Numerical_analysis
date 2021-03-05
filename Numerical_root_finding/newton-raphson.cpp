#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float func(float x)
{
  return(x*x*x-5*x*x+6);
}
float funcprime(float x)
{
  return(3*x*x-10*x);
}

int main(void)
{
  float x1,x,fx,fx1,acc;
  int count=0;
  ofstream fileout("newrap.out");
  fileout<<"Summery of the result"<<endl;
  fileout<<"------------------------------------------"<<endl;
  cout<<"Enter the desired accuracy: ";
  cin>>acc;
  cout<<"Enter the initial guess value: ";
  cin>>x1;
  if(abs(func(x1))<acc)
  {
    cout<<"The root of the equation is : "<<x1<<endl;
  }
  else
  {
    fileout<<"Iterrations....."<<endl;
    fileout<<"x\tx1\t|x-x1|"<<endl;
    do
    {
      x=x1;
      fx=func(x);
      fx1=funcprime(x);
      x1=x-(fx/fx1);
      //cout<<x<<"\t"<<x1<<"\t"<<abs(x-x1)<<endl;
      fileout<<x<<"\t"<<x1<<"\t"<<abs(x-x1)<<endl;
      count++;
    }
  while(abs(func(x1))>acc);
  cout<<"The root is = "<<x1<<"\n";
  cout<<"Number of itterations  = "<<count<<"\n";
  fileout<<"The root is = "<<x1<<"\n";
  fileout<<"Number of itterations  = "<<count<<"\n";
  cout<<"Summery of the iterration can be found in newrap.out file"<<endl;
  }
}