/*
    Created by Qiu on 7/6/15
    All right reserved
*/

#include <iostream>
#include <string>

struct free_throws{
    std::string name;   // not declare using namespace std yet
    int made;
    int attempts;
    float percent;
};

// an inline function definition test
inline double square(double x) { return x * x;}

// Function Reference test
void swapr(int & a, int & b){ // use references
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int * p, int * q){     // use pointers
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

//structure references test/////////////////
void display(const free_throws & ft){
    using std::cout;
    
    cout <<"Name: " << ft.name << '\n';
    cout <<"  Made: "<< ft.made << '\t' <<"Attempts: " << ft.attempts << '\t' << "Percent: " << ft.percent <<'\n';
}

void set_pc(free_throws &ft){
    if (ft.attempts != 0){
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    }else{
        ft.percent = 0;
    }
}

free_throws & accumulate(free_throws & target, const free_throws & source){
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc (target);
    return target;
}


// test main function
int main(){
    using namespace std;
    
    // inline function test
    double c = 13.0;
    cout << "c squared = " << square(c) << "\n";
    
    // first reference
    int rats = 101;
    int & rodents = rats;      // rodents is the reference of rats! same address
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats << ", rodents address = " << &rodents << endl;  // same address
    
    // swap test
    int wallet1 = 200;
    int wallet2 = 300;
    cout << "wallet1 = " << wallet1 << "  wallet2 = " << wallet2 << endl;
    
    cout << "Using reference to swap contents: \n";
    swapr(wallet1, wallet2);
    cout << "wallet1 = " << wallet1 << "  wallet2 = " << wallet2 << endl;
    cout << "Using pointers to swap contents: \n";
    swapp(& wallet1, & wallet2);
    cout << "wallet1 = " << wallet1 << "  wallet2 = " << wallet2 << endl;
    
    // structure references test
    free_throws one = {"Tian", 13, 14};    // initialize struct
    free_throws two = {"Qiu", 10, 16};
    free_throws team = {"Throwgoods", 0, 0};
    
    free_throws dup;
    
    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    
    dup = accumulate(team, two);
    display(team);
    
    
    
    
    
}
