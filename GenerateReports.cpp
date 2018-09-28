#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
#include "classname.hpp"
#include "ControllerHeader.hpp"

using namespace std;
int found=0;

void GenerateReports::displaySubMenu()
{
        cout<<"\n\n***************************************************"<<endl;
        cout<<"######              SUB-MENU                ####### "<<endl;
        cout<<"***************************************************"<<endl;
        cout<<"\t\t  1. Daily\n\t\t  2. Weekly\n\t\t  3. Monthly\n\t\t  4. Go to Main Menu";
        cout<<"\n\n***************************************************";
        cout<<"\n\nEnter the choice: ";
        cin>>Option;
}
void GenerateReports::generateReport()
{

        cout<<"\n\n*********************Generate Reports****************"<<endl;
        string item;
        long q;
        char ch;
        cout<<"\nEnter the ItemCode: ";
        cin>>itemCode;
        ifstream f1;
        f1.open("stock.csv");
        if(!f1)
        {
        cout<<"Not able to open stock.csv"<<endl;
        exit(1);
        }
        while(f1>>item)
          {
             f1.get(ch);
             f1>>q;
             if(item == itemCode)
              {
                found=1;
                break;
              }
          }
        f1.clear(); f1.close();

}
void GenerateReports::checkUserOptionAndInvoke()
{

        ReportController r1;
        subOption='y';
        int flag =1;
        while(subOption=='y'| subOption=='Y')
        {
                system("clear");
                found=0;
                generateReport();
                if(found)
                {
                cout<<"Please select the type of report to be generated: ";
                displaySubMenu();
                switch(Option)
                 {
                        case '1':
                                r1.generatedailyreport(itemCode);
                                break;
                        case '2':
                                r1.generateweeklyreport(itemCode);
                                break;
                        case '3':
                                r1.generatemonthlyreport(itemCode);
                                break;
                        case '4':
                                  subOption='N';
                                  flag=0;
                                  break;
                        default:
                                cout<<"Incorrect Choice\n";
                                break;
                 }
                }
   else
                 cout<<"Product not found."<<endl;

                if(flag)
                {
                cout<<"\nDo you want to continue (Y/N): ";
                cin>>subOption;
                }
        }
}
