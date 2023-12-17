#include"../include/BoardGame_Classes.hpp"
#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;
char row_win[3], col_win, diag_win[2];
int n=0;
int xc =0 ,oc=0;

pyramid_x_o_board::pyramid_x_o_board(){
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }


};
 bool pyramid_x_o_board:: update_board (int x, int y, char mark){
// Only update if move is valid
     if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
         board[x][y] = toupper(mark);
         n_moves++;
         return true;
     }
     else
         return false;
 }

void pyramid_x_o_board:: display_board(){
    for (int i: {0,1,2}) {

        cout<<"\n/ ";
        for (int j: {0,1,2,3,4}) {
            if(i==0 && j==0) {
                cout << "(" << i << "," << j << ")";
                cout  << board[i][j] ;
            }
            if(i==1&&j<=2){
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] ;

            }
            if(i==2&& j<=4){
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] ;
            }
        }
        cout << "\\\n"<< "  " <<setw(4);

    }
    cout << endl;
}
bool pyramid_x_o_board:: is_winner(){
   //loop on the third row

        for (int i = 0; i < 5; i++) {

            if (board[2][i] == 'X')xc++;
            else if (board[2][i] == 'O')oc++;
            if(xc==3||oc==3) {
                if (xc > oc) row_win[n] = 'X';
                else row_win[n] = 'O';

            }
        xc= 0 ;
        oc =0 ;
        n++;
    }

//check the columns
    if  (board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')  col_win='X';
    else if  (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')  col_win='O';

// check the diagonals
   else  if(board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X') diag_win[0]='X';
    else if(board[0][0]=='X' && board[1][2]=='X' && board[2][4]=='X') diag_win[0]='X';
    else if (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O') diag_win[1]='O';
    else if(board[0][0]=='O' && board[1][2]=='O' && board[2][4]=='O') diag_win[1]='O';



    for (int i:{0,1,2}) {
        if ( row_win[i] =='X' ||row_win[i]=='O')
                return true;
    }
    for(int i:{0,1}){
    if (diag_win[i] == 'X'||diag_win[i] =='O')
         return true;
    }
    if(col_win=='X'||col_win=='O')
         return true ;

    return false;
 }
bool pyramid_x_o_board:: is_draw(){
    return (n_moves == 9 && !is_winner());
 }
bool pyramid_x_o_board::game_is_over(){
    return n_moves >= 9;
 }
