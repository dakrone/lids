#include <iostream>

#include "lidsevent.h"
#include "lidsdebug.h"

LIDSEvent::LIDSEvent()
{
}

LIDSEvent::~LIDSEvent()
{
}

int LIDSEvent::process_packet(const struct pcap_pkthdr *header, const u_char *packet)
{
      IN();
      OUT();
      return 0;
}

