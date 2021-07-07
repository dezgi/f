/* Ezgi Diþbudak 2243400
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only. */

#include <iostream>
#include "Fighter.h"

using namespace std;

int main()
{
    int GenjuroAttack, GenjuroHealth, HaohmaruAttack, HaohmaruHealth,input;

    cout << "Genjuro's attack power: ";
    cin >> GenjuroAttack;

    cout << "Genjuro's max health(healthbar): ";
    cin >> GenjuroHealth;

    cout << "Haohmaru's attack power: ";
    cin >> HaohmaruAttack;

    cout << "Haohmaru's max health(healthbar): ";
    cin >> HaohmaruHealth;

    Genjuro genjuro(GenjuroAttack, GenjuroHealth);
    Haohmaru haohmaru(HaohmaruAttack, HaohmaruHealth);
    
    //genjuro.print();
    cout << "\n";
    //haohmaru.print();
    
    char playAgain = 'a';

    while (playAgain != 'n'){

        cout << "Who goes first?";
        cout << "  \nGenjuro(1), Haohmaru(2) ";
        cin >> input;

        while (haohmaru.isLost() != 1 || genjuro.isLost() != 1) { // check haohmaru or genjuro is lost

            if (input == 1) {
                cout << "\nGenjuro's attack!";
                haohmaru.updateHealthBar(GenjuroAttack);
                haohmaru.print();
                if (haohmaru.isLost() == 1) { // if Haohmaru lost the game
                    cout << "\n\nHaohmaru lost!";
                    cout << "\nGenjuro won!.";
                    break;
                }

                cout << "\nHaohmaru's attack!";
                genjuro.updateHealthBar(HaohmaruAttack);
                genjuro.print();
                if (genjuro.isLost() == 1) { // if Genjuro lost the game
                    cout << "\n\nGenjuro lost.";
                    cout << "\nHaohmaru won!";
                    break;
                }
            }

            else if (input == 2) {
                cout << "\nHaohmaru's attack!";
                genjuro.updateHealthBar(HaohmaruAttack);
                genjuro.print();
                if (genjuro.isLost() == 1) { // if Haohmaru lost the game
                    cout << "\n\nGenjuro lost!";
                    cout << "\nHaohmaru won!";
                    break;
                }

                cout << "\nGenjuro's attack!";
                haohmaru.updateHealthBar(GenjuroAttack);
                haohmaru.print();
                if (haohmaru.isLost() == 1) { // if Genjuro lost the game
                    cout << "\n\nHaohmaru lost!";
                    cout << "\nGenjuro won!";
                    break;
                }
            }
            else {
                cout << "Wrong choice";
            }
        }

        cout << "\n\nWould you like to play again(y/n): ";
        cin >> playAgain;

        if (playAgain == 'y') {
            cout << "\n";
            cout << "Genjuro's attack power: ";
            cin >> GenjuroAttack;

            cout << "Genjuro's max health(healthbar): ";
            cin >> GenjuroHealth;


            cout << "Haohmaru's attack power: ";
            cin >> HaohmaruAttack;

            cout << "Haohmaru's max health(healthbar): ";
            cin >> HaohmaruHealth;

            genjuro.setAttackValue(GenjuroAttack);
            genjuro.setHealthbar(GenjuroHealth);
            haohmaru.setAttackValue(HaohmaruAttack);
            haohmaru.setHealthbar(HaohmaruHealth);
        }

        if (playAgain == 'n') {
            cout << "Goodbye!";
        }

    }
}
