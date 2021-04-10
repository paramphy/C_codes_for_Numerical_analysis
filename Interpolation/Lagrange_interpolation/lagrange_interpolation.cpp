#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(void)
{
  int i,j,n=0;
  float x[100],y[100],h,xnew,ynew,p;
  ifstream in("lagrange.in");
  while(in>>x[n]>>y[n])
    n++;
  cout<<"No of data point n = "<<n<<endl;
  for(i=0;i<n;i++)
  cout<<x[i]<<" "<<y[i]<<endl;
  cout<<"Enter the value of x where we want to calculate y: ";
  cin>>xnew;
  float term,chenge;
  ynew=0.0;
  for(i=0;i<n;i++)
  {
    term=1.0;
    for(j=0;j<n;j++)
    {
      if(i!=j)
      term=term*((xnew-x[j])/(x[i]-x[j]));
    }
    chenge=term*y[i];
    ynew = ynew + chenge;
  }
  cout<<"xnew = "<<xnew<<"\t ynew = "<<ynew<<endl;
  return 0;
}
