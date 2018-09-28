#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
#include "ControllerHeader.hpp"
#include "FileEntityHeader.hpp"
using namespace std;

StockFileEntity SF1;

int ReportController::convert_date(char *m, int dd)
{
                int i=0,j,k;
                char array[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
                for(i=0;i<12;i++)
                {
                        if(strcmp(m,array[i])==0)
                        {
                                for(j=i-1;j>=0;j--)
                                {
                                        dd=dd+month[j];
                                }
                        }
                }
                return ((dd/7)+1);
        }

        void ReportController::generatedailyreport(string icode)
        {
                char array[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                flag=0;
                int dd,yyyy,i,k;
                billedquantity=0;
                cout<<"\n**********************Daily Report**********************"<<endl;
                cout<<"\n\nEnter the date (DD MM YYYY): ";
                cin>>day>>month>>year;
                if(day>=1 && day<=31 && month>= 1 && month<= 12 && year>=1)
                {
                fstream f1;
                f1.open("BillFile.csv",ios::in);
  while(f1>>itemCode)
                {
                        f1.get(ch);
                        if(icode==itemCode)
                        {
                                f1>>quantity;
                                f1.get(ch);  //to fetch space between the data
                                f1>>mon;
                                f1.get(ch);
                                f1>>dd;
                                f1.get(ch);
                                f1>>yyyy;
                                if(strcmp(mon,array[month-1])==0)
                                {
                                        if( dd==day && yyyy==year)
                                        {
                                                flag=1;
                                                billedquantity+=quantity;
                                        }
                                }

                        }
                }
                f1.clear();
                f1.close();
                rem_quan=SF1.select(icode);      //Calling Select function from StockFileEntity class ruturns quantity
                if(flag==0)
                        cout<<"Product not found."<<endl;
                else
                {
                        system("clear");
                        cout<<"******************************* DAILY REPORT ******************************"<<endl<<endl;
                        cout<<"\n************************************************************************"<<endl;
                        cout << "\t\t    Date: "<<day<<"/"<<month<<"/"<<year<<endl;
                        cout << "Item code: " << icode<<endl;
                        cout << "Quantity billed: " <<billedquantity<<endl;
                        cout << "Remaining stock: " <<rem_quan<<endl;
                        cout<<"\n*************************************************************************"<<endl;

                }
             }
             else
              cout<<"Invalid Date."<<endl;
 }
        void ReportController::generateweeklyreport(string icode)
        {
                flag=0;
                cout<<"\n***************Weekly Report**************"<<endl;
                cout<<"\n\nEnter the Week Number (1-52): ";
                cin>>wkno;
                if(wkno>=1 && wkno <=53)
                {
                billedquantity=0;
                fstream f1;
                f1.open("BillFile.csv",ios::in);
                while(f1>>itemCode)
                {
                        f1.get(ch);
                        if(icode==itemCode)
                        {
                                f1 >> quantity;
                                f1.get(ch);
                                f1 >> mon;
                                f1.get(ch);
                                f1 >> day;
                                week=convert_date(mon,day);
                                if(wkno==week)
                                {
                                        flag=1;
                                        billedquantity+=quantity;
                                }
                        }
                }
                f1.clear();
                f1.close();
                rem_quan=SF1.select(icode); //Calling Select function from StockFileEntity class ruturns quantity
                if(flag==0)
                        cout<<"\nProduct not found. "<<endl;
                else
                {
                        system("clear");
                       cout<<"******************************* WEEKLY REPORT ******************************"<<endl<<endl;
                       cout<<"\n***********************************************************************"<<endl;
                        cout << "\t\t     Week: "<<wkno<<endl;
                        cout << "Item code: " << icode<<endl;
                        cout << "Quantity billed: " <<billedquantity<<endl;
  cout << "Remaining Stock: " <<rem_quan<<endl;
                        cout<<"\n***********************************************************************"<<endl;
                }
               }
                else
                 cout<<"Invalid Week."<<endl;
        }
        void ReportController::generatemonthlyreport(string icode)
        {
                char array[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                flag=0;
                int i;
                billedquantity=0;
                cout<<"\n**********************Monthly Report**********************"<<endl;
                cout<<"\n\nEnter the Month (1-12): ";
                cin>>month;
                if(month>=1 && month<=12)
                {
                fstream f1;
                f1.open("BillFile.csv",ios::in);
                while(f1>>itemCode)
                {
                        f1.get(ch);
                        if(icode==itemCode)
                        {
                                f1>>quantity;
                                f1.get(ch);
                                f1>>mon;
                                if(strcmp(mon,array[month-1])==0)
                                {
                                        flag=1;
                                        billedquantity+=quantity;
                                }
                        }
                }
                f1.clear();
                f1.close();
                rem_quan=SF1.select(icode);    //Calling Select function from StockFileEntity class ruturns quantity
                if(flag==0)
                        cout<<"\nProduct not found."<<endl;
                else
                {
 system("clear");
                       cout<<"******************************* MONTHLY REPORT ******************************"<<endl<<endl;                        cout<<"\n*******************************************************************"<<endl;
                        cout << "\n\t\t       Month: "<<array[month-1]<<endl;
                        cout << "Item code: " << icode<<endl;
                        cout << "Quantity billed: " <<billedquantity<<endl;
                        cout << "Remaining stock: " <<rem_quan<<endl;
                        cout<<"\n*******************************************************************"<<endl;
                }
               }
               else
                cout<<"Invalid Month."<<endl;

         }
