/* 
 Created by Qiu on 7/7/15
 All copyright are reserved
 
*/

#include <string>
#include <iostream>

class Stock{
    private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val;}
    
    public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update (double price);
    void show();
};


void Stock::acquire(const std::string & co, long n, double pr){
    company = co;
    if (n < 0){
        std::cout << "Number of shares cannot be negative; " << company << "shares set to 0.\n";
        shares = 0;
    }else{
        shares = n;
    }
    share_val = pr;
    set_tot();               // calculate total value
}

void Stock::buy(long num, double price){
    if(num<0){
        std::cout << "Number of shares purchased cannot be negative";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
    if(num<0){
        cout << "number of shares sold cannot be negative \n";
    }else if (num > shares){
        cout << "You cannot sell more than you have!" << " Treansaction is aborted. \n";
    }else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

void Stock::show(){
    std::cout << "Company: " << company << " Shares: " << shares <<std::endl <<"share Price: "<< share_val
    << " Total Worth: " << total_val << std::endl;
}


int main(){
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("Nanosmart" , 20, 12.5);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
}





















