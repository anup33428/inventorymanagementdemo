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

long RetailBill::generateRetailBill()
 {
                subOption1='y';
                char quan[11]; int i=0;
                billAmount=0,itemAmount=0;
                while(subOption1=='y' || subOption1=='Y')
                {
                   system("clear");
                   subOption='y';
                   billAmount=0;
                   itemAmount=0;
                        while(subOption=='y' || subOption=='Y')
                        {
                                cout<<"\nEnter the itemcode: ";
                                cin>>itemCode;
                                cout<<"Enter the quantity: ";
                                cin>>quan;
                                quantity=atoi(quan);
                                while(quan[i]>='A' && quan[i]<='z')
                                {
                                 cout<<"Incorrect Quantity. Please Enter a valid quantity: ";
                                 cin>>quan;
                                 quantity=atoi(quan);
                                }

                                StockController sc1;
                                if((sc1.checkstock(itemCode,quantity))==-1)
                                        cout<<"product not found"<<endl;
                                else if((sc1.checkstock(itemCode,quantity))==0)
                                {
                 cout<<"Product found. Stock Availble is "<<sc1.viewStock(itemCode)<<". Product Cannot be billed."<<endl;
  }
                                else
                                {
                                        BillController b1;
                                        itemAmount=b1.generateRetailBill(itemCode,quantity);
                                        cout<<"Total amount for the item "<<itemCode<<" is Rs"<<itemAmount<<endl;
                                         billAmount+=itemAmount;
                                }

                                cout<<"\nDo you wish to add another product to the bill? (Y/N) ";
                                cin>>subOption;

                        }
                        if(billAmount!=0)
                        {
                        cout<<"Your Total bill amount is: Rs"<<billAmount<<endl;
                        cout<<"Name of the person: ";
                        cin>>name;
                        cout<<"Address: ";
                        cin>>address;
                        cout<<"Products billed.Please receive Rs. "<<billAmount<<" and close the bill."<<endl;
                        }
                        cout<<"\nDo you want to generate another bill?(Y/N) ";
                        cin>>subOption1;
                }
    }
