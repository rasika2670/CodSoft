#include<iostream>
#include<random>
#include <ctime>

using namespace std;

int main() {
    
    unsigned seed = time(0);
    mt19937 gen(seed);
    uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);

    cout << "A random number is generated between 1 to 100.\nCan you guess the number ?\n"<< endl;
    int guess = 0 ;
    while (random_number != guess)
    {
        cout << "Enter your guess : " ;
        cin >> guess ;

        if (guess < random_number)
        {
            cout << "The number is greater than your guess.\nTry Again !\n"<<endl;
        }
        else if (guess > random_number)
        {
            cout << "The number is smaller than your guess.\nTry Again !\n"<<endl;
        }
    } 
    cout << "Yayyy!!! You guessed correct number : " << guess << endl ;
    return 0 ;
}