#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() {}

Grid::~Grid() {
  delete td;
}

void Grid::clearGrid() {
  for(int i = 0; i < gridSize; ++i){
    theGrid.pop_back();
  }
  gridSize = 0;
  delete td;
  td = nullptr;
}

bool Grid::isWon() const {
  for(int i = 0; i < gridSize; ++i){
    for(int j = 0; j < gridSize; ++j){
      if(theGrid[i][j].getState() == true) return false;
    }
  }
  return true;
}

void Grid::init(int n) {
  clearGrid(); 
  gridSize = n;
  td = new TextDisplay{gridSize};
  // initialize all the cells
  for(int i = 0; i < gridSize; ++i){
    vector<Cell> arr;
    for(int j = 0; j < gridSize; ++j){
      arr.emplace_back(Cell{false, 0, 0});
    }
    theGrid.emplace_back(arr);
  }
 // make the neighbors become observers
  for(int i = 0; i < gridSize; ++i){
    for(int j = 0; j < gridSize; ++j){
      theGrid[i][j].setCoords(i, j);
      theGrid[i][j].attach(td);
      theGrid[i][j].attach(&theGrid[i][j]);
      theGrid[i][j].notifyObservers(SubscriptionType::SwitchOnly);
      int north = i - 1;
      int south = i + 1;
      int east = j + 1;
      int west = j - 1;
      if(north >= 0){
	theGrid[i][j].attach(&theGrid[north][j]);
      }
      if(east < gridSize){
        theGrid[i][j].attach(&theGrid[i][east]);
      } 
      if(south < gridSize){
	theGrid[i][j].attach(&theGrid[south][j]);
      } 
      if(west >= 0){
	theGrid[i][j].attach(&theGrid[i][west]);
      }
    }
  }
}



void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);

}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  int north = r - 1;
  int south = r + 1;
  int east = c + 1;
  int west = c - 1;
  if(north >= 0){
    theGrid[north][c].toggle();
  }
  if(east < gridSize){
    theGrid[r][east].toggle();
  }
  if(south < gridSize){
    theGrid[south][c].toggle();
  } 
  if(west >= 0){
    theGrid[r][west].toggle();
  }	
  theGrid[r][c].notifyObservers(SubscriptionType::All);
}

void Grid::init(int r, int c) {
  theGrid[r][c].setCoords(r, c);
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *(g.td);
  return out;
}
