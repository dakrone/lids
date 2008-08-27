#include <iostream>
#include <pcap.h>
#include <sys/types.h>

#include "testevent.h"
#include "lidsdebug.h"

TestEvent::TestEvent()
{
}

TestEvent::~TestEvent()
{
}

int TestEvent::process_packet(const struct pcap_pkthdr *header, const u_char *packet)
{
      IN();
      OUT();
      return 0;
}

char* TestEvent::get_event_name()
{
      IN();
      char* c = "Test Event";
      OUTp(c);
      return c;
}

