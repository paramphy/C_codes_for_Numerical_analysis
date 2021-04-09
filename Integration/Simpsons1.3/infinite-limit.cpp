#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float f(float x)
{
  return(exp(-x*x));
}

int print_val(float n)
{
  float i;
  ofstream outf("values.out");
  for(i=1;i<=n;i=i+.01)
  outf<<i<<"\t"<<f(i)<<endl;
}

float simpson13(float a, float b, int n)
{
  int i=1;
  float s1=0,s2=0,h,s;
  h=(b-a)/n;
  for(i=1;i<=n;i++)
  {
    if(i%2!=0)
      s1=s1+f(a+i*h);
    if(i%2==0)
      s2=s2+f(a+i*h);
  }
  s=f(a)+4*s1+2*s2;
  s=(h/3.0)*s;
  return(s);
}
int main(void)
{
  int n,i=1;
  float a,b=100,h,s;
  cout<<"Give the \n lower limit: ";
  ofstream out1("simp13.out");
  cin>>a;
  print_val(1000);
  do
  {
    s = simpson13(a,b,1000);
    cout<<b<<"   The resultent integral value: "<<s<<endl;
    b++;
  }
  while(abs(s-simpson13(a,b+10,1000))>0.00001);
}