//
// Created by HP on 12/17/2023.
//

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);
int n_game ;
cout<<"please enter the number of the game that you want to play : \n"
      "1)pyramid_x_oboard\n"
      "2)four_x_o_board\n"
      "3)five_x_o_board\n";
cin>>n_game ;
if(n_game==1) {
    GameManager x_o_game(new pyramid_x_o_board(), players);
    x_o_game.run();
}
else if (n_game==2){
    GameManager x_o_game(new X_O_Board(), players);
    x_o_game.run();
}
else if(n_game ==3){
    GameManager x_o_game(new X_O_Board(), players);
    x_o_game.run();
}

    system ("pause");
}