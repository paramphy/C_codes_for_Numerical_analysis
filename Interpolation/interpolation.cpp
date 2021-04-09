#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(void)
{
  int i,j,n=0;
  float x[100],y[100][100],h,xnew,ynew,p;
  ifstream in("input.txt");
  ofstream out("output.txt");
  while(in>>x[n]>>y[0][n])
    n++;
  cout<<"No of data point n = "<<n<<endl;
  for(i=0;i<n;i++)
    cout<<x[i]<<" "<<y[0][i]<<endl;
  cout<<"Calculate delta(Yo):"<<endl;
  for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      y[i][j]=y[i-1][j+1]-y[i-1][j];
      cout<<y[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<"Enter the value of x where we want to calculate y: ";
  cin>>xnew;
  h=x[1]-x[0];
  cout<<"The equal spacing h = "<<h<<endl;
  p=(xnew-x[0])/h; cout<<"P = "<<p<<endl;
  float term=1.0,chenge;
  ynew=y[0][0];
  for(i=0;i<n-1;i++)
  {
    term=term*(p-i)/(i+1);
    chenge=term*y[i+1][0];
    ynew = ynew + chenge;
  }
  cout<<"xnew = "<<xnew<<"\t ynew = "<<ynew<<endl;
  return 0;
}