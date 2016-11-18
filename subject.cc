#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) { 
  observers.emplace_back(o);  
}

void Subject::notifyObservers(SubscriptionType t) {
  if(t == SubscriptionType::All){
    for(auto ob: observers){
      if(ob->subType() != SubscriptionType::All){
	ob->notify(*this);
      }
    }
  }// below is SwitchOnly case 
  else {
    observers[0]->notify(*this);
  }
}

Subject::~Subject(){}
