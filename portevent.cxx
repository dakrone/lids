#include <iostream>

#include "portevent.h"
#include "lidsdebug.h"

PortEvent::PortEvent()
{
}

PortEvent::~PortEvent()
{
}

bool PortEvent::process_packet(LIDSBuffer* buff)
{
      IN();
      OUTd(false);
      return false;
}

char* PortEvent::get_event_name()
{
      IN();
      OUT();
      return (char*)"Port Event";
}
