#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}
void calc(double* p, const int N, const double xmin, const double dx){
  for(int i=0; i<N; i++){
   double x=xmin+i*dx; 
  p[i]=exp(-x*x);
  }  
}
void der(double* p, const int N, const double dx){
  double p0=0;
  double p1=p[0];
  double pp=p[1];
  
  p[0]=(p[1]-p0)/(2*dx);
  
  for(int i=1; i<N; i++){
    pp=p[i];
    p[i]=(p[i+1]-p1)/(2*dx);
    p1=pp;
    
    
  }
  p[N-1]=(p0-p1)/(2*dx);
}
  


int main(){
  const int N = 100;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  // call to functio which calculates the derivative
  calc(p,N,xmin,dx);
  der(p,N,dx);
  print(p,N,dx,xmin);

  return 0;
}
