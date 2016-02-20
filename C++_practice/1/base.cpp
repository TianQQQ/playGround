/*
    Test fundamentals for c++.
    Created by Qiu on 7/6/15
    All copyright reserved
*/

#include <iostream>
#include <limits.h>

const int kmonths = 12;
const float kmillion = 1.0e6;

int main(){
    using namespace std;
    
    // limits test
    int n_int = INT_MAX;
    long long n_llong = LLONG_MAX;

    
    cout << "int is " << sizeof(int) << " Bytes " << endl;
    cout << "long is " << sizeof(long) << " Bytes " << endl;
    cout << "long long is " << sizeof(long long) << " Bytes" << endl;
    cout << "long long is " << sizeof(char) << " Bytes" << endl;
    
    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Max int value = " << INT_MAX << endl;
    cout << "Bits per byte = " <<  CHAR_BIT << endl;
    cout << "Max long long value = " << LLONG_MAX << endl;
    cout << "Max unsigned char value = " << UCHAR_MAX << endl;
    cout << "Max signed char value = " << SCHAR_MAX << endl;
    
    // hexadecimal integer test
    int hexa = 0x42;
    int octal = 042;
    int dec = 34;
    
    cout << "0x42 in decimal is :" << hexa << endl;
    cout << "042 in decimal is :" << octal << endl;
    
   // cout << oct;                                       // change all the dec to oct
    cout << "Change decimal 34 to octal: " << dec << endl;
    
    cout.put(65) << " test ASCII code 65 "<< endl;
    
    cout << "Constant months every year is :" << kmonths << endl;
    cout << "Constant million is :" << kmillion << endl;
    
    // bondini BEL test
    cout << "\nOperation \"HyperHype\" is now activated!\n";      // \" is "  \a is BEL
    cout << "\aEnter your agent code: ________\b\b\b\b\b\b\b\b";  // \b is backspace

    long code;
    cin >> code;
    
    cout << "You entered " << code << "...\n";
    cout << "code verified! Proceed with plan Z3!\n\n";
    
    // String initialization
    int size = 10;
    int arr[20] = {0};   // fill all elements by 0 autoly
    char name[size];       // empty
    cout << "Not initialized string, garbage right now: " << name << endl;
    cout << "Input the original name: __________\b\b\b\b\b\b\b\b\b\b";
    cin >> name;
    cout << "Original name is : " << name << endl;
    name[3] = '\0';
    cout << "First three char of string is " << name << endl << endl;
    
    string str1;
    string str2 = "aaa";
    cout << "Input New String ";
    cin >> str1 ;
    string str = str1 + str2;
    cout <<"new string + aaa : " << str << endl;
    
    //
    
    
    
    




    
    
    
    
    

}