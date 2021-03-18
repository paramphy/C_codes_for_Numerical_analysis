#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

//Function to calculate real part of the equation
float g(float x,float y)
{
  return(x*x-y*y+1.0);
}

//Function to calculate imaginary part of the equation
float h(float x,float y)
{
  return(2.0*x*y);
}

//Function to calculate differential(wrt x) of real part of the equation
float dgx(float x,float y)
{
  return(2.0*x);
}

//Function to calculate differential(wrt y) of real part of the equation
float dgy(float x,float y)
{
  return(-2.0*y);
}

//Function to calculate differential(wrt x) of imaginary part of the equation
float dhx(float x,float y)
{
  return(2.0*y);
}

//Function to calculate differential(wrt y) of imaginary part of the equation
float dhy(float x,float y)
{
  return(2.0*x);
}

//Main code

int main()
{
  float x0,x,y,y0,x1,y1,denom,del_x,del_y;
  //ofstream out1("newrap_z2reg1.out");
  //ofstream out2("newrap_z2reg2.out");
  cout<<"Input the guess value for real solution: ";
  cin>>x;
  cout<<"Input the guess value for imaginary solution: ";
  cin>>y;
  x0 = x;
  y0 = y;
  denom = dgx(x0,y0)*dhy(x0,y0)-dgy(x0,y0)*dhx(x0,y0);
  if(denom == 0)
    cout<<"Please change the initial guess values"<<endl;
  else{
    do
    {
      denom = dgx(x0,y0)*dhy(x0,y0)-dgy(x0,y0)*dhx(x0,y0);
      del_x = (dgy(x0,y0)*h(x0,y0)-g(x0,y0)*dhy(x0,y0))/denom;
      del_y = (g(x0,y0)*dhx(x0,y0)-dgx(x0,y0)*h(x0,y0))/denom;
      x1 = x0 + del_x;
      y1 = y0 + del_y;
      x0 = x1;
      y0 = y1;
      //cout<<x0<<"\t"<<y0<<endl;
      //cout<<del_x<<"\t"<<del_y<<endl;
    }
  while(abs(g(x0,y0))>0.000001 || abs(h(x0,y0))>0.000001);
  cout<<"the root is ("<<x0<<") + i ("<<y0<<")"<<endl;
  }
}
