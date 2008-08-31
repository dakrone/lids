#include <iostream>
#include <string>

#include "lidsevent.h"
#include "lidsdebug.h"

LIDSEvent::LIDSEvent()
{
}

LIDSEvent::~LIDSEvent()
{
}

int LIDSEvent::process_packet(LIDSBuffer* buff)
{
      IN();
      OUT();
      return 0;
}

char* LIDSEvent::get_event_name()
{
      IN();
      char* c = "LIDSEvent";
      OUTp(c);
      return c;;
}
