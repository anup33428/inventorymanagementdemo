#include <iostream>
using namespace std;

class PriceFileEntity
{

 string itemCode;
 double price;
 double billedAmount;

public:

double select(string);

};

class StockFileEntity
{

 string itemCode;
 long quantity;
 long billedQuantity;

public:

bool update(string,long);
long select(string);

};
