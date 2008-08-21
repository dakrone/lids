#include <iostream>

#include "lidsrunner.h"

using namespace std;

int main(int argc, char** argv) {
      cout << "LIDS" << endl;

      LIDSRunner *r = new LIDSRunner();

      r->setup();
      r->run();

      return 0;
}



