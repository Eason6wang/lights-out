#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n):gridSize{n} {
  for(int i = 0; i < gridSize; ++i){
     vector<char> arr;
     for(int j = 0; j < gridSize; ++j){
       arr.emplace_back('_');
     }
     theDisplay.emplace_back(arr);
  }
}


void TextDisplay::notify(Subject &whoNotified) {
  Info information = whoNotified.getInfo();
  int r = information.row;
  int c = information.col;
  bool isOn = information.state;
  if(isOn){
    theDisplay[r][c] = 'X';
  } else {
    theDisplay[r][c] = '_';
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int i = 0; i < td.gridSize; ++i){
    for(int j = 0; j < td.gridSize; ++j){
      cout << td.theDisplay[i][j];
    }
    cout << endl;
  }
  return out;
}
