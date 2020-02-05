#include "ticTacToeBoard.h"
#include <iostream>
using namespace std;

void printBoard(ticTacToeBoard board) {
	for (int y=0; y<4; y++) {
		cout << "|";
	for (int x=0; x<4; x++) {
	    if (board.points[x+4*y]==0)
	    		cout << " ";
	    else if (board.points[x+4*y]==1)
	    		cout << "X";
	    else if (board.points[x+4*y]==-1)
	    		cout << "O";

	      cout << "|";
	}
	cout << endl;
	}
}

void initBoard(ticTacToeBoard& board) {
//makes all values in the board array 0, so that the board is empty
	board.curr_player=1;
	for (int i=0; i<16; i++)
		board.points[i]=0;

}

bool isEmpty(ticTacToeBoard board, int x, int y) {
//if the values of the array are 0, that means player X and O hasn't made any moves yet
	if (board.points[(x-1)+4*(y-1)]==0)
		return true;
	else
		return false;
}

void mark(ticTacToeBoard& board, int x, int y) {
//if the current player is X, whatever coordinate player X marks will have a value of 1
	while (board.points[(x-1)+4*(y-1)]==0 && board.curr_player == 1) {
		board.points[(x-1)+4*(y-1)]=1;
	}
//if the current player is O, whatever coordinate player X marks will have a value of -1
	while (board.points[(x-1)+4*(y-1)]==0 && board.curr_player == -1) {
		board.points[(x-1)+4*(y-1)]=-1;
	}

}

bool boardFull(ticTacToeBoard board) {
//if there's any values in the board array that equals 0, that means that board isn't full yet
	for (int i=0; i<16; i++) {
		if (board.points[i] == 0)
			return false;
	}

	return true;
}

int winner(ticTacToeBoard board) {

	int temp = board.curr_player;

//if any of the rows are filled with a value of 1, X is the winner
	if (board.points[0]==1 && board.points[1]==1 && board.points[2]==1 && board.points[3]==1)
		temp=1;
	else if (board.points[4]==1 && board.points[5]==1 && board.points[6]==1 && board.points[7]==1)
		temp=1;
	else if (board.points[8]==1 && board.points[9]==1 && board.points[10]==1 && board.points[11]==1)
		temp=1;
	else if (board.points[12]==1 && board.points[13]==1 && board.points[14]==1 && board.points[15]==1)
		temp=1;
//if any of the columns are filled with a value of 1, X is the winner
	else if (board.points[0]==1 && board.points[4]==1 && board.points[8]==1 && board.points[12]==1)
		temp=1;
	else if (board.points[1]==1 && board.points[5]==1 && board.points[9]==1 && board.points[13]==1)
		temp=1;
	else if (board.points[2]==1 && board.points[6]==1 && board.points[10]==1 && board.points[14]==1)
		temp=1;
	else if (board.points[3]==1 && board.points[7]==1 && board.points[11]==1 && board.points[15]==1)
		temp=1;
//if any of the diagonals are filled with a value of 1, X is the winner
	else if (board.points[0]==1 && board.points[5]==1 && board.points[10]==1 && board.points[15]==1)
		temp = 1;
	else if (board.points[3]==1 && board.points[6]==1 && board.points[9]==1 && board.points[12]==1)
		temp = 1;
//if any of the rows are filled with a value of -1, O is the winner
	else if (board.points[0]==-1 && board.points[1]==-1 && board.points[2]==-1 && board.points[3]==-1)
		temp=-1;
	else if (board.points[4]==-1 && board.points[5]==-1 && board.points[6]==-1 && board.points[7]==-1)
		temp=-1;
	else if (board.points[8]==-1 && board.points[9]==-1 && board.points[10]==-1 && board.points[11]==-1)
		temp=-1;
	else if (board.points[12]==-1 && board.points[13]==-1 && board.points[14]==-1 && board.points[15]==-1)
		temp=-1;
//if any of the columns are filled with a value of -1, O is the winner
	else if (board.points[0]==-1 && board.points[4]==-1 && board.points[8]==-1 && board.points[12]==-1)
		temp=-1;
	else if (board.points[1]==-1 && board.points[5]==-1 && board.points[9]==-1 && board.points[13]==-1)
		temp=-1;
	else if (board.points[2]==-1 && board.points[6]==-1 && board.points[10]==-1 && board.points[14]==-1)
		temp=-1;
	else if (board.points[3]==-1 && board.points[7]==-1 && board.points[11]==-1 && board.points[15]==-1)
		temp=-1;
//if any of the diagonals are filled with a value of -1, O is the winner
	else if (board.points[0]==-1 && board.points[5]==-1 && board.points[10]==-1 && board.points[15]==-1)
		temp = -1;
	else if (board.points[3]==-1 && board.points[6]==-1 && board.points[9]==-1 && board.points[12]==-1)
		temp = -1;
//otherwise, there is no winner yet
	else {
		for (int i = 0; i<16; i++) {
			if (board.points[i] == 0) {
				return 0;
				}
			}
		}

	return temp;

}


int main() {
  ticTacToeBoard b1;
  initBoard(b1);
  printBoard(b1);
  int x, y;
  //while board is not full
  cout << "Column = first number input, Row = second number input.\n";
  while (!boardFull(b1)) {
    //Ask for current player to make move
    if (b1.curr_player == 1) cout << "Player X";
    else cout << "Player O";
    cout << ", what is your move?\n";

    //loop to get valid move.
    do {
      cin >> x; cin >> y;
      //if move out of bound, get input agin
      if ( !((1<=x)&&(x<=4)&&(1<=y)&&(y<=4)) ) {
	cout << "Out of bounds.\n";
	continue;
      }
      //If empty make move
      if (isEmpty(b1,x,y)) {
	mark(b1,x,y);
	break; //done with this move
      } else {
	cout << "You can't play there.\n";//get input again
      }
    } while(true);

    printBoard(b1);
    if (winner(b1)!=0) break;//if there is a winner, exit

    //Swap player
    b1.curr_player *= -1;

  }

  //We're done either because there's a winner
  //or because the board is full.
  if (winner(b1)==1)
    cout << "X is the winner!\n";
  else if (winner(b1)==-1)
    cout << "O is the winner!\n";
  else
    cout << "The game is a tie!\n";

  return 0;
}
