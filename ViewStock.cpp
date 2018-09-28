#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "classname.hpp"
#include "ControllerHeader.hpp"

using namespace std;

long ViewStock::viewStock()
      {
      do
      {
       cout<<"\nPlease enter the item code: ";
       cin>>itemcode;
       StockController s;
       quantity=s.viewStock(itemcode);
       if(quantity==-1)
             cout<<"\nProduct not found."<<endl;
       else
            cout<<"\nProduct found and the current stock is: "<<quantity<<endl;

       cout<<"\nDo you want to view stock for another product? (Y/N): ";
       cin>>suboption;

      }while (suboption=='Y' || suboption=='y');

       return 1;

       }
