#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

float f(float x)
{
  return(sin(x));
}

int main()
{
  int n,Ncount=0,i;
  float x,y,p,a,b,ymax=0, ymin=0, sum, random_no;
  ofstream fileout1("montea.out");
  ofstream fileout2("monteb.out");
  cout<<"give the lower & upper limit :"<<endl;
  cin>>a>>b;
  cout<<"Enter how many number are to be generated: ";
  cin>>n;

  //Calculation of maximum value of the function
  for(x=a;x<=b;x+=0.001)
  {
    if(f(x)>ymax)
      ymax=f(x);
  }

  //Calculation of minimum value of the function
  for(x=a;x<=b;x+=0.001)
  {
    if(f(x)<ymin)
      ymin = f(x);
  }

  cout<<"The maximum value of function: "<<ymax<<endl;
  cout<<"The minimum value of function: "<<ymin<<endl;
  
  time_t t;
  srand (time(&t));
  for(i=0;i<n;i++)
  {
    random_no = rand();
    x=(random_no/(float(RAND_MAX)))*(b-a);
    random_no = rand();
    y=(random_no/(float(RAND_MAX)))*(ymax-ymin);
    fileout1<<x<<"\t"<<y<<endl;
    if(y<=f(x))
    {
      Ncount++;
      fileout2<<x<<"\t"<<y<<endl;
    }
  }
  cout<<"Total no. of points: "<<n<<endl;
  cout<<"No. of points inside the curve: "<<Ncount<<endl;
  sum=((b-a)*(ymax-ymin)*Ncount)/(n*1.0);
  cout<<"The value of Intregration: "<<sum<<endl;
  return 0;
}
