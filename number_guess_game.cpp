#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
   
    srand(static_cast<unsigned int>(time(nullptr)));

    int randomNumber = rand() % 100 + 1; 
    int guess;
    int numberOfGuesses = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        numberOfGuesses++;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number!" << endl;
            cout << "It took you " << numberOfGuesses << " guesses." << endl;
        }
    } while (guess != randomNumber);

    return 0;
}
