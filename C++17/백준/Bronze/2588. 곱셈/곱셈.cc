#include <iostream>
#include <iomanip> // setw, left
using namespace std;

int main() {
   int a;
   int b;
   int x100;
   int x10;
   int x;
   cin >> a >> b;
   x100 = b /100;
   b=b%100;
   x10 = b / 10;
   b=b%10;
   x=b;
   cout<<x*a<<endl;
   cout<<x10 * a <<endl;
   cout<<x100 * a <<endl;
   cout<< (x100 * a)*100 +(x10 * a)*10 + x*a <<endl;


   return 0;
}