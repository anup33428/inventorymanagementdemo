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


        bool AddStock::addstock()
        {
                subOption='y';
                while(subOption=='y'||subOption=='Y')
                {
                        cout<<"\nPlease enter the item code: ";
                        cin>>itemCode;
                        cout<<"Please enter the quantity of stock to be increased: ";
                        cin>>quantity;
                        StockController SC1;
                        if(SC1.addStock(itemCode,quantity))
                                cout<<"Product found and Stock increased."<<endl;
                        else
                                cout<<"Product not found."<<endl;
                        cout<<"Do you want to add stock for another product? (Y/N): ";
                        cin>>subOption;
                }
                return 1;
        }
