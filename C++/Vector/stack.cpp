/* 
 
    Simulate stack 
    Created by Qiu on 7/9/15
    All rights are reserved
*/

#include <iostream>
#include <cctype>

typedef unsigned  long Item;

class Stack{
    private:
    
    enum {MAX = 10};   // constant specific to class
    Item items[MAX];    // hold stack item
    int top;           // index for top stack item
    
    public:
    
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);    // add item to stack
    bool pop(Item & item);           // pop top into item
};



Stack::Stack(){    // create a empty stack
    top = 0;
}

bool Stack::isfull() const{
    return top == MAX;
}

bool Stack::isempty() const{
    return top == 0;
}

bool Stack::push(const Item & item){
    if (top < MAX){
        items[top++] = item;
        return true;
    }else{
        return false;
    }
}

bool Stack::pop(Item & item){
    if(top > 0){
        item = items[--top];
        return true;
    }else{
        return false;
    }
}

int main(){
    using namespace std;
    
    Stack st;
    char ch;
    unsigned long po;
    cout << "enter A to add a purchase order,\n" << "P to process a po, or Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q'){
        while (cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':    // A or a to add
            case 'a':
            
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull()) {
                cout << "Stack already full\n";
            }else{
                st.push(po);
            }
            break;
            
            case'P':      // p or P to pop
            case'p':
            
            if (st.isempty()){
                cout << "stack already empty\n";
            }else{
                st.pop(po);
                cout << "po #" << po << " popped\n";
            }
            break;
            
            
            default:
            break;
        }
        cout << "Please enter A to add a purchase order, \n" << " P to precess a PO, or Q to quit.\n";
    }
    cout << "End\n";
    return 0;
}













