#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "MainHeader.hpp"

using namespace std;

int main()
{
        system("clear");
        const char *pass="admin";
        int count=4;
        cout<<"\n********************* WELCOME TO STOCK MANAGEMENT SYSTEM ***********************    "<<endl;
        while(count--)
        {
                char *password=getpass("\nPlease Enter the password: ");
                if(strcmp(pass,password)!= 0)
                {
                        if(count==0)
                        {
                                cout<<"\nMaximum Attempts reached.. Application closing....... "<<endl;
                                exit(1);
                        }
                        else
                                cout<<"Incorrect password.. Login failed.. "<<count<< " attempt(s) left.."<<endl;
                }

                else
                        break;
        }
        system("clear");
        cout<<"\nHello Admin."<<endl;
        cout<<"Date: "<<__DATE__<<endl;
        MainMenu M1;
        M1.checkUserOptionAndInvoke();
        system("clear");
        return 0;
}
