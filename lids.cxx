#include <iostream>

#include "lidscore.h"

using namespace std;

int main(int argc, char** argv) {
      cout << "Hello World" << endl;

      LIDSCore* c = new LIDSCore();

      c->run();

      return 0;
}



