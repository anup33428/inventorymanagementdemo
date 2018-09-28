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

bool StockController::addStock(string itemc, long quan)
 {
    bool res;
    StockFileEntity s1;
    res= s1.update(itemc,quan);
    if(res)
     return true;
    else
     return false;
 }

 long StockController::viewStock(string itemc)
 {
   StockFileEntity s1;
   quantity= s1.select(itemc);
   return quantity;
 }
long StockController::checkstock(string itemc, long quan)
  {
   StockFileEntity s1;
   quantity= s1.select(itemc);
   if(quantity==-1)
      return -1;
   else if(quantity < quan)
      return 0;
   else
    return quantity;
  }
