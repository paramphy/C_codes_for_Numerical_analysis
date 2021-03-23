#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

struct two_numbers{
  float x,y;
};

//Function to calculate real part of the equation
float g(float x,float y)
{
  return(x*x*x-3*x*y*y-1.0);
}

//Function to calculate imaginary part of the equation
float h(float x,float y)
{
  return(3*x*x*y-y*y*y);
}

//Function to calculate differential(wrt x) of real part of the equation
float dgx(float x,float y)
{
  return(3*x*x-3*y*y);
}
//Function to calculate differential(wrt y) of real part of the equation
float dgy(float x,float y)
{
  return(-6*x*y);
}

//Function to calculate differential(wrt x) of imaginary part of the equation
float dhx(float x,float y)
{
  return(6*x*y);
}

//Function to calculate differential(wrt y) of imaginary part of the equation
float dhy(float x,float y)
{
  return(3*x*x-3*y*y);
}

two_numbers new_rap_img(float x, float y)
{
  two_numbers two;
  float x1,y1,del_x, del_y,denom,x0,y0;
  x0 = x;
  y0 = y;
  denom = dgx(x0,y0)*dhy(x0,y0)-dgy(x0,y0)*dhx(x0,y0);
  if(denom!=0){
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
  while(abs(g(x0,y0))>0.000001 && abs(h(x0,y0))>0.000001);
  }
  two.x = x0;
  two.y = y0;
  return(two);
}

//Main code

int main()
{
  float x,y;
  two_numbers two;
  ofstream out0("newton_fractal0.out");
  ofstream out1("newton_fractal1.out");
  ofstream out2("newton_fractal2.out");
  //two = new_rap_img(.5, -4);
  //ofstream out2("newrap_z2reg2.out");
  for(x=-2;x<=2;x=x+0.1)
  {
    for(y=-2;y<=2;y=y+0.1)
    {
      two = new_rap_img(x, y);
      if(two.x==1)
        out0<<x<<"\t"<<y<<"\t"<<two.x<<"\t"<<two.y<<endl;
      else if(two.x!=1 && two.y<0)
        out1<<x<<"\t"<<y<<"\t"<<two.x<<"\t"<<two.y<<endl;
      else
        out2<<x<<"\t"<<y<<"\t"<<two.x<<"\t"<<two.y<<endl;

    }
  }
  //cout<<two.x<<"\t"<<two.y<<endl;
}
