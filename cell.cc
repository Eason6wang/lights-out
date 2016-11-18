#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell(bool on = false, int r = 0, int c = 0): isOn{on}, r{r}, c{c} {}


bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
  Info information {r, c, isOn};
  return information;
}

void Cell::setOn() {
  isOn = true;
}

void Cell::toggle() {
    isOn = !isOn;
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &thecell) {//why need param
  /*Info information = thecell.getInfo();
  int row = information.row;
  int col = information.col;
  if(row == r && col == c){
    return;
  } else {
   */ this->notifyObservers(SubscriptionType::SwitchOnly);
  
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
