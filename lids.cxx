#include <iostream>
#include <vector>

#include "lidsrunner.h"
#include "lidscore.h"
#include "testevent.h"
#include "lidsevent.h"
#include "lidsdebug.h"

using namespace std;

/* global var to our dispatcher */
LIDSCore *pcore = new LIDSCore();

int main(int argc, char** argv) {
      IN();
      cout << "-= LIDS =-" << endl;
      vector<LIDSEvent*> events;

      LIDSRunner *runner = new LIDSRunner();

      /* let's register 2 test events */
      TestEvent *e = new TestEvent();
      TestEvent *e2 = new TestEvent();

      /* register the two test events */
      pcore->core_register_event(e);
      pcore->core_register_event(e2);

      events = pcore->core_get_registered_events();

      vector<LIDSEvent*>::const_iterator i;
      for(i=events.begin(); i!=events.end(); i++)
      {
            cout << "Event: ";
            cout << (*i)->get_event_name();
            cout << endl;
      }

      /* start the capture */
      runner->start();
      OUTd(0);
      return 0;
}



