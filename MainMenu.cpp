#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "MainHeader.hpp"
#include "classname.hpp"
using namespace std;

AddStock A1;
ViewStock V1;
RetailBill R1;
WholesaleBill W1;
GenerateReports G1;

  void MainMenu::displayMainMenu()
  {

      cout<<"\n|******************************************************************|"<<endl;
      cout<<"|############               MAIN MENU                ############# | "<<endl;
      cout<<"|******************************************************************|"<<endl;
      cout<<"\n                        1. Add Stock.  "<<endl;
      cout<<"                        2. Retail Bill.  "<<endl;
      cout<<"                        3. Wholesale Bill.  "<<endl;
      cout<<"                        4. View Stock. "    <<endl;
      cout<<"                        5. Generate Report.  "<<endl;
      cout<<"                        6. Exit.           "<<endl;
  }

   void MainMenu::checkUserOptionAndInvoke()
    {
      while(1)
      {
       displayMainMenu();
       cout<<"\n\nPlease Enter your choice? ";
       cin>>choice;

      switch(choice)
      {
        case '1':
               system("clear");
               cout<<"\n****************** ADD STOCK PAGE *********************\n\n"<<endl;
               A1.addstock();
break;

        case '2':
                 system("clear");
                cout<<"\n****************** RETAIL BILL PAGE *********************\n\n"<<endl;
                R1.generateRetailBill();
                break;
        case '3':
                 system("clear");
               cout<<"\n****************** WHOLESALE BILL PAGE *********************\n\n"<<endl;
               W1.generateWholesaleBill();
               break;
        case '4':
                 system("clear");
                cout<<"\n****************** VIEW STOCK PAGE *********************\n\n"<<endl;
                V1.viewStock();
                break;
        case '5':
                 system("clear");
                cout<<"\n****************** GENERATE REPORT PAGE *********************\n\n"<<endl;
                G1.checkUserOptionAndInvoke();
                break;
        case '6':
                 system("clear");
                 exit(1);
        default:
         cout<<"\n Sorry.. Incorrect choice..."<<endl;
                 sleep(1);
                 break;
     }
 system("clear");

    }
 }
