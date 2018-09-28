#include <iostream>
using namespace std;

class AddStock
{
        string itemCode;
        long int quantity;
        char subOption;
        public:

        bool addstock();
 };

class ViewStock
{
 string itemcode;
       long int quantity;
       char suboption;
 public:

      long viewStock();
};

class RetailBill
{
        string itemCode;
        long quantity;
        char subOption,subOption1;
        double itemAmount;
        double billAmount;
        string name,address;
        public:
        long generateRetailBill();
};
class WholesaleBill
{
private :
            string itemCode;
            long quantity;
            char subOption;
            char subOption1;
            double price;
            double itemAmount;
 double billAmount;
            string name;
            string address;
            float discount;
public :
            long generateWholesaleBill();
};

class GenerateReports
{
private:
        string itemCode;
        char subOption;
        int Option;
public:
        void displaySubMenu();
        void generateReport();
        void checkUserOptionAndInvoke();
};

