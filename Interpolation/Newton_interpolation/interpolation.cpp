#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(void)
{
  int i,j,n=0;
  float x[100],y[100][100],h,xnew,ynew,p,term=1.0,change;
  ifstream filein("input.txt");
  ofstream out("output.txt");

  //Data input from file
  while(filein>>x[n]>>y[0][n])
    n++;
  //Console print the input data
  cout<<"No of data point n = "<<n<<endl;
  for(i=0;i<n;i++)
    cout<<x[i]<<" "<<y[0][i]<<endl;
  //Calculation of deltas
  cout<<"Calculated deltas(Yo):"<<endl;
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
  cout<<"The equal spacing = "<<h<<endl;
  p=(xnew-x[0])/h;
  //Calculation of the new value of y
  ynew=y[0][0];
  for(i=0;i<n-1;i++)
  {
    term=term*(p-i)/(i+1);//Calculation of term
    change=term*y[i+1][0];
    ynew = ynew + change;//new value of y continuing iteration
  }
  cout<<"----------------------------------"<<endl;
  cout<<"Result:"<<endl;
  cout<<"x = "<<xnew<<"\t y = "<<ynew<<endl;
  return 0;
}