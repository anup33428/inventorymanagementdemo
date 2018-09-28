#include <iostream>
using namespace std;

class StockController
{

 string itemCode;
 long quantity;

public:

 bool addStock(string, long);
 long viewStock(string);
 long checkstock(string, long);
};

class BillController
{
 string itemCode,date;
 long quantity;
 char suboption;
 double price;
 double itemAmount;
 double billAmount;
 string name;
 string address;
 float discount;
public:
    double generateRetailBill(string,long);
    double generateWholesaleBill(string,long);
 };

class ReportController
{
        string itemCode,date,date1;
        long billedquantity,rem_quan,quantity,quan;
        int week,w;
        int month,flag,year,day;
        char type[4],ch;
        public:
        int convert_date(string);
        void generatemonthlyreport(string);
        void generatedailyreport(string);
        void generateweeklyreport(string);
};
