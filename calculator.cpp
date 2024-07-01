/*
 Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, 
 multiplication, and division. Allow the user to input two numbers and choose an operation to perform.
*/

#include<iostream>
using namespace std;

int main(){
    float a , b , c ;
    char x , s ;
    do
    {
        cout << "Do you want to calculate? (y/n) : " ;
        cin >>  s ;
        if (s == 'y')
        {
            cout << "Enter 1st number : " ;
            cin >> a ;
            cout << "Enter 2nd number : " ;
            cin >> b ;
            cout << "Enter the arithmetic operation : ";
            cin >> x ;

            switch (x)
            {
            case '+':
                c = a + b ;
                break;

            case '-':
                c = a - b ;
                break;

            case '*':
                c = a * b ;
                break;
        
            case '/':
                c = a / b ;
                break;

            default:
                cout << "Invalid operation" <<  endl;
                break;
            }

            if (c)
            {
                cout << a << x << b << " = " << c << endl;
            }
        }
        
    } while (s=='y');

    return 0 ;
}