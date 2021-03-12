#include<iostream>
#include<cmath>
using namespace std;
//function defining

float f(float x){
 return (x*x-5*x+6);
}
 
      float bisection(float a,float b){
            float x, epsilon=0.0001;
           if(f(a)*f(b)>0){
             cout<<"Inputs are not correct choose another inputs\n";
            }
         
    while(abs(b-a)>epsilon){
            x=(a+b)/2;
         if(f(x)==0){
             break;
         }
   else if(f(x)*f(a)<0){
               x=b;
          }
        else{
           x=a;
            }
     }
   return x;
}
    int main (void){
         float a,b;
       cout<<"Give the value of a\n";
          cin>>a;
          cout<<"Give the value of b\n";
          cin>>b;    
           cout<<"The value of the root is="<<bisection(a,b)<<endl;
           return 0;
     } 