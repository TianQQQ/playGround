/*
    test redefine operators
    test friend
 
    Created by Qiu on 7/9/15
    All rights are reserved
*/


#include <iostream>


class Time{
    private:
    
    int hours;
    int minutes;
    
    public:
    
    Time();          // initialization
    Time(int h, int m = 0);
    void addMin(int m);
    void addHr(int h);
    void Reset(int h = 0, int m = 0);
    
    
    // member version                     a = c.operator+(b)
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    void Show() const;
    
    // non-member version                 a = operator+(b,c)
    
    // method 1 2  to solve 1.5 * time
    //friend Time operator* (double m, const Time & t);    // friend port （接口）
    // method 3
    friend Time operator*(double m, const Time & t) { return t * m; } // inline definition
    
    // redefine <<
    friend std::ostream & operator<< (std::ostream & os, const Time & t);
    
    
};



Time::Time(){      // initialization
    hours = minutes = 0;
}

Time::Time(int h, int m){   // new time
    hours = h;
    minutes = m;
}

void Time::addMin(int m){
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::addHr(int h){
    hours += h;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;     // minus
    tot2 = minutes + 60 * hours;         // original
    
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    
    return diff;
}

Time Time::operator*(double mult) const{               // for A * 1.5
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}



// method 1
// friend input function
// 1.5 is friend of time
/*
Time operator*(double mult, const Time & t){           // friend for 1.5 * A
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
 */


// method 2
/*Time operator*(double mult, const Time & t){
    return t * mult;        // use t.operator*(m)
}
 */


void Time::Show() const{
    std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Time  &   t){
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}





int main(){
    using std::cout;
    using std::endl;
    
    //test redefine operators
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;
    
    cout << "Weeding time = ";
    weeding.Show();
    
    cout << "Waxing time = ";
    waxing.Show();
    

    total = weeding + waxing;
    diff = weeding - waxing;
    adjusted = 1.5 * total;        // cannot be 1.5 * total
                                   // a = b.operator*(2.75)    1.5 is not type of time
                                   // solve this problem by friend
    
    cout << "Total work time = ";
    total.Show();
    cout << "Weeding - Waxing = ";
    diff.Show();
    cout << "adjusted total work time = ";
    adjusted.Show();

    // test friend
    Time A (3, 35);
    Time B (2, 48);
    Time temp;
    
    cout << "A and B: \n";
    cout << A << "; " << B << endl;
    temp = A + B;
    cout << "A + B = " << temp << endl;
    cout << "A * 1.7 = " << 2.0 * A << endl;
    
    
    return 0;
    
}











