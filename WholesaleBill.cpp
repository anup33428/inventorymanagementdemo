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

long WholesaleBill::generateWholesaleBill()
                {
                        cout<<"In wholesale bill products can be billed only in multiples of 50.\n\n"<<endl;
                        subOption='y';
                        char quan[10];int i=0;
                        while (subOption == 'y'|| subOption=='Y')
                        {
                         system("clear");
                         subOption1='y';
                         billAmount=0;
                         itemAmount=0;
                        while (subOption1 == 'y' || subOption1 == 'Y')
                        {
                        cout<<"\nEnter the item code: ";
                        cin>>itemCode;
                        cout<<"Enter the quantity required: ";
                        cin>>quan;
                        quantity=atoi(quan);
                        while(quan[i]>='A' && quan[i]<='z')
                        {
                          cout<<"Incorrect Quantity. Please Enter a valid quantity: ";
                          cin>>quan;
                          quantity=atoi(quan);
                        }

                        StockController s2;
                        if((quantity % 50) != 0)
                        cout<<"Quantity invalid...Product cannot be billed"<<endl;
                        else if(s2.checkstock(itemCode,quantity)== -1)
                        cout<<"Product not found"<<endl;
                        else if(s2.checkstock(itemCode,quantity)== 0)
  cout<<"Product found. Stock available is "<<s2.viewStock(itemCode)<<". Product Cannot be billed."<<endl;

                        else
                        {
                        BillController B1;
                        itemAmount=B1.generateWholesaleBill(itemCode,quantity);
                        cout<<"Total amount for the item"<<" "<<itemCode<<" is Rs"<<itemAmount<<endl;
                        billAmount+=itemAmount;
                        }
                         cout<<"\nDo you wish to add another product to the bill? (Y/N) ";
                        cin>>subOption1;
                        }
                        if(billAmount!=0)
                        {
                        cout<<"Your Total bill amount is: Rs."<<billAmount<<endl;
                        cout<<"Enter the percentage of discount: ";
                        cin>>discount;
                        billAmount=(billAmount - (billAmount * (discount/100.0)));
                        cout<<"Your discounted amount to be paid is: "<<billAmount<<endl;
                        cout<<"Name of the person: ";
                        cin>>name;
                        cout<<"Address: ";
                        cin>>address;
                        cout<<"Products billed. Please receive Rs "<<billAmount<<" and close the bill."<<endl;
                        }
                        cout<<"\nDo you want to generate another bill? (Y/N) ";
                        cin>>subOption;
                        }

                }
