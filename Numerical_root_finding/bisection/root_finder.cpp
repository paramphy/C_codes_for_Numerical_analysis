#include <iostream>
#include<cmath>

using namespace std;

//root guessing function
struct two_numbers{
  float x,y;
};

float func(float x)
{
  return(x*x-5*x+6);
}

two_numbers root_ini()
{
  float x;
  int count=0;
  two_numbers two;
  two.x=0;
  two.y=0;
  for(x=-1000;x<=1000;x=x+.5)
  {
    if(func(x-.1)*func(x+.1)<0)
    {
      cout<<"Guess value is: "<<x<<endl;
      count++;
      if(count == 1)
        two.x = x;
      else  
        two.y = x;
    }
  }
return(two);
}

int main()
{
  two_numbers two;
  two = root_ini();
  cout<<two.x<<endl;
  cout<<two.y<<endl;
}
