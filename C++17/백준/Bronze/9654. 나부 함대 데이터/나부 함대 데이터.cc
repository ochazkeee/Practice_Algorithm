#include <iostream>
#include <iomanip> // setw, left
using namespace std;

int main() {
   cout << left << setw(15) << "SHIP NAME" 
        << setw(15) << "CLASS" 
        << setw(11) << "DEPLOYMENT" 
        << setw(10) << "IN SERVICE" << endl;


   cout << left << setw(15) << "N2 Bomber" 
        << setw(15) << "Heavy Fighter" 
        << setw(11) << "Limited" 
        << setw(10) << "21" << endl;

   cout << left << setw(15) << "J-Type 327" 
        << setw(15) << "Light Combat" 
        << setw(11) << "Unlimited" 
        << setw(10) << "1" << endl;

   cout << left << setw(15) << "NX Cruiser" 
        << setw(15) << "Medium Fighter" 
        << setw(11) << "Limited" 
        << setw(10) << "18" << endl;

   cout << left << setw(15) << "N1 Starfighter" 
        << setw(15) << "Medium Fighter" 
        << setw(11) << "Unlimited" 
        << setw(10) << "25" << endl;

   cout << left << setw(15) << "Royal Cruiser" 
        << setw(15) << "Light Combat" 
        << setw(11) << "Limited" 
        << setw(10) << "4" << endl;

   return 0;
}