#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(void)
{
  int i,j,n=0;
  float x[100],y[100],xnew,ynew, term = 1, change;
  ifstream in("input.txt");
  while(in>>x[n]>>y[n])
    n++;
  cout<<"No of data point n = "<<n<<endl;
  for(i=0;i<n;i++)
  cout<<x[i]<<"\t"<<y[i]<<endl;
  cout<<"Enter the value of x where we want to calculate y: ";
  cin>>xnew;
  ynew=0.0;
  for(i=0;i<n;i++)
  {
    term=1.0;
    for(j=0;j<n;j++)
    {
      if(i!=j)
      term=term*((xnew-x[j])/(x[i]-x[j]));
    }
    change=term*y[i];
    ynew = ynew + change;
  }
  cout<<"-----------------------------------------"<<endl;
  cout<<"Result"<<endl;
  cout<<"x = "<<xnew<<"\t y = "<<ynew<<endl;
  return 0;
}
