#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "FileEntityHeader.hpp"

using namespace std;


double PriceFileEntity::select(string iname)
{

  ifstream fin;
  char ch;
  fin.open("price.csv");
  if(!fin)
  {
    cout<<"\nprice.csv file not found..";
    exit(1);
  }
  while(!fin.eof())
  {
    fin>>itemCode;
    if(itemCode==iname)
      {
         fin.get(ch);
         fin>>price;
         return price;
      }
 }
 fin.close();
 return -1;
}


