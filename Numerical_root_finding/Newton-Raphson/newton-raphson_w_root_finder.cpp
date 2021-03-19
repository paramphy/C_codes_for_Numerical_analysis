#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

//root guessing function
struct two_numbers{
  float x,y;
};

float funcprime(float x)
{
  return(3*x*x-10*x);
}

float func(float x)
{
  return(x*x-5*x+6);
}

two_numbers root_ini()
{
  float x;
  int count=0;
  two_numbers two;
  two.x=0;
  two.y=0;
  for(x=-1000;x<=1000;x=x+.5)
  {
    if(func(x-.1)*func(x+.1)<0)
    {
      cout<<"Guess value is: "<<x<<endl;
      count++;
      if(count == 1)
        two.x = x;
      else  
        two.y = x;
    }
  }
return(two);
}

int main(void)
{
  float x1,x,fx,fx1,acc, arr[10];
  two_numbers two;
  int count=0,i;
  ofstream fileout("newrap_w_root_finder.out");
  fileout<<"Summery of the result"<<endl;
  fileout<<"------------------------------------------"<<endl;
  cout<<"Enter the desired accuracy: ";
  cin>>acc;
  two = root_ini();
  arr[0] = two.x;
  arr[1] = two.y;
  for(i=0;i<=1;i++)
  { 
    x1 = arr[i]; 
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
}