#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float f(float x)
{
  return(sin(x));
}

int main(void)
{
  int n,i;
  float a,b,h,x[100],y[100],s,s1,s2=0,s3=0;
  cout<<"Give the \n lower limit: ";
  ofstream out1("simp13.out");
  cin>>a;
  cout<<"Upper limit: ";
  cin>>b;
  cout<<"Enter the even number of interval:";
  cin>>n;
  h=(b-a)/n;
  for(i=0;i<n;i++)
  {
    x[i]=a+i*h;
    y[i]=f(x[i]);
    out1<<x[i]<<" \t"<<y[i]<<endl;
  }
  s1=f(a)+f(b)+4*f(a+h);
  for(i=3;i<=n;i=i+2)
  {
    s2=s2+4*f(a+i*h);
    s3=s3+2*f(a+(i-1)*h);
  }
  s=s1+s2+s3;
  s=(h/3.0)*s;
  cout<<"The resultent integral value: "<<s<<endl;
  return 0;
}