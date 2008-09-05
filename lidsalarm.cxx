#include <iostream>

#include "lidsalarm.h"
#include "lidsdebug.h"

using namespace std;

LIDSAlarm::LIDSAlarm()
{
}

LIDSAlarm::~LIDSAlarm()
{
}

void LIDSAlarm::throw_alarm(int urgency, char* message)
{
      IN();
      OUT();
      cout << "[" << urgency << "]: " << message << endl;
}

