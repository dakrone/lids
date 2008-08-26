#include <iostream>

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

      LIDSRunner *runner = new LIDSRunner();
      TestEvent *e = new TestEvent();

      pcore->register_event(e);



      runner->start();
      OUTd(0);
      return 0;
}



