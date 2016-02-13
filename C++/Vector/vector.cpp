/* 
    Vector class, operators overloading, friends
    
    Created by Qiu on 7/14
    All rights are reserved
*/


#include <cmath>
#include "vector.h"
#include <fstream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    // transfer degrees to radian
    const double Rad_to_deg = 45 / atan(1.0);  // about 57.295779   (-90 90)
    
    // private methods
    // calculates magnitude from x and y
    void Vector::set_mag(){
        mag = sqrt(x * x + y * y);
    }
    
    void Vector::set_ang(){
        if (x == 0.0 && y == 0.0) {
            ang = 0.0;
        }else{
            ang = atan2(y,x);    // (-180, 180)
        }
    }
    
    // set x from polar coordinate
    void Vector::set_x(){
        x = mag * cos(ang);
    }
    
    // set y from polar coordinate
    void Vector::set_y(){
        y = mag * sin(ang);
    }
    
    //public methods
    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    
    // construct vector from rectangular coordinates if form is r
    // (the default) else constrct vector from polar coordinates
    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if(form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
            
        }else{
            cout << "Incorrect 3rd argument to Vector()  --> vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    
    //reset
    void Vector::reset(double n1, double n2, Mode form){
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if(form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
            
        }else{
            cout << "Incorrect 3rd argument to Vector()  --> vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    
    Vector::~Vector(){   // destructor
    }
    
    void Vector::polar_mode(){
        mode = POL;
    }
    
    void Vector::rect_mode(){
        mode = RECT;
    }
    
    // operator overloading
    // add two vectors
    Vector Vector::operator+(const Vector & b)const{
        return Vector(x + b.x, y + b.y);
    }
    
    Vector Vector::operator-(const Vector & b)const{
        return Vector(x - b.x, y - b.y);
    }
    
    // reverse sign of Vector
    Vector Vector::operator-() const{
        return Vector(-x, -y);
    }
    
    Vector Vector::operator*(double n) const{
        return Vector(n * x, n * y);
    }
    
    Vector operator*(double n, const Vector & a){       // friend method
        return a * n;
    }
    
    // display rect or polar
    std::ostream & operator<<(std::ostream & os, const Vector & v){
        if (v.mode == Vector::RECT) {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        }else if(v.mode == Vector::POL){
            os << "(m, p) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        }else{
            os << "Vector object mode is invalid";
        }
        return os;
    }
}



#include <cstdlib>
#include <ctime>


int main(){
    using namespace std;
    using VECTOR::Vector;
    
    
    // output
    ofstream fout;
    fout.open("thewalk.txt");
    
    srand(time(0));    // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);  //ini
    
    unsigned long steps = 0;
    double target;
    double dstep;
    
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        
        cout << "After " << steps << " steps, the subject has the following location: \n";
        cout << result << endl;
        
        result.polar_mode();
        cout << " or \n" <<result << endl;
        cout << " Average outward distance per step = " << result.magval() / steps << endl;
        
        //output
        fout << result << endl;
        
        
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit) : ";
    }
    
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }

    
    return 0;
}





















