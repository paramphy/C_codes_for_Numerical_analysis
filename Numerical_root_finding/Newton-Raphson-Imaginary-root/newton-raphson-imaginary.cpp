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
  float x0,x,y,y0,x1,y1,denom,del_x,del_y,x3,y3;
  ofstream out1("newrap_z2reg1.out");
  ofstream out2("newrap_z2reg2.out");
  for(x=-2.0;x<=2.0;x=x+0.01)
  {
    for(y=-2.0;y<=2.0;y=y+0.01)
    {
      x3 = x;
      y3 = y;
      x0 = x;
      y0 = y;
      do
      {
        denom = dgx(x0,y0)*dhy(x0,y0)-dgy(x0,y0)*dhx(x0,y0);
        del_x = (dgx(x0,y0)*h(x0,y0)-g(x0,y0)*dhy(x0,y0))/denom;
        del_y = (g(x0,y0)*dhx(x0,y0)-dgy(x0,y0)*h(x0,y0))/denom;
        x1 = x0 + del_x;
        y1 = y0 + del_y;
        x0 = x1;
        y0 = y1;
        cout<<x0<<'\t'<<y0<<endl;
      }
      while(abs(del_x)>0.00001 || abs(del_y)>0.00001);
      cout<<'End of itteration 1'<<endl;
    }
    cout<<'end of itteration 2'<<endl;
  }
  cout<<"the root is "<<x0<<" +i("<<y0<<") "<<denom<<endl;
  if(abs(x0+0.0)<0.001 && abs(y0)<0.001)
  out1<<x3<<" "<<y3<<endl;
  if(abs(x0+0.0)<0.001 && abs(y0)<0.001)
  out2<<x3<<" "<<y3<<endl;
}

