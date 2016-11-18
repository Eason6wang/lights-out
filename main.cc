#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

void showMove(int &moves, bool begin, bool isWon, bool &isbreak){
  cout << moves;
  if(moves == 1){
     cout << " move left" << endl;
  } else {
  cout << " moves left" << endl;
  }
  if(isWon && begin){
    cout << "Won" << endl;
    isbreak = true;
  }
  if(moves == 0){
    if(isWon){ 
      cout << "Won" << endl;
    } else {
      cout << "Lost" << endl;
    }
    isbreak = true;
  }
  --moves;
}



int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = -1;
  bool begin = false;
  bool isbreak = false;
  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n);
	continue;
      }
      else if (cmd == "init") {
	int row;
	int col;
	while(cin >> row >> col){
	  if(row == -1 || col == -1) break;
	  g.turnOn(row, col);
	}
        cout << g;
	continue;
      }
      else if (cmd == "game") {
	begin = false;
        cin >> moves;
	showMove(moves, begin, g.isWon(), isbreak);
	if(isbreak) break;
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
	g.toggle(r, c);
	cout << g;
        begin = true;
	showMove(moves, begin, g.isWon(), isbreak);
	if(isbreak) break;
      }
    }
  }
  catch (ios::failure &) {
  }
}
