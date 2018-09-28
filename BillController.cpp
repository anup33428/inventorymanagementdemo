#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "ControllerHeader.hpp"
#include "FileEntityHeader.hpp"
using namespace std;

double BillController::generateRetailBill(string ino, long quan)
       {
          PriceFileEntity P1;
          StockFileEntity SE1;
          price=P1.select(ino);
          SE1.update(ino,-quan);
          if(price==-1)
           {
             cout<<"\nProduct not found in price.csv"<<endl;
             return 0;
           }
          else
           {
              cout<<"Product found. Price of the product is: "<<price<<endl;
              itemAmount=quan * price;
               fstream fs;
              fs.open("bill.csv",ios::ate | ios::app |ios::out);
               date=__DATE__;
               fs<<ino<<" "<<quan<<" "<<date<<"\n";
               fs.clear();
               fs.close();

           }
         return itemAmount;
       }
 double BillController::generateWholesaleBill(string ino, long quan)
      {
          PriceFileEntity P1;
          price=P1.select(ino);
          StockFileEntity SE2;
          SE2.update(ino,-quan);
          if(price==-1)
           {
             cerr<<"\nProduct not found in price.csv"<<endl;
             return 0;
           }
          else
           {
              cout<<"Product found. Price of the product is: "<<price<<endl;
              itemAmount=quan * price;
               fstream fs;
               fs.open("bill.csv",ios::ate | ios::app |ios::out);
               date=__DATE__;
               fs<<ino<<" "<<quan<<" "<<date<<"\n";
               fs.clear();
               fs.close();
          }
         return itemAmount;
       }


