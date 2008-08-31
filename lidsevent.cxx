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

bool LIDSEvent::process_packet(LIDSBuffer* buff)
{
      IN();
      OUTd(false);
      return false;
}

char* LIDSEvent::get_event_name()
{
      IN();
      char* c = "LIDSEvent";
      OUTp(c);
      return c;;
}
