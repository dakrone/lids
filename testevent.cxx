#include <iostream>
#include <pcap.h>
#include <sys/types.h>

#include "testevent.h"

TestEvent::TestEvent()
{
}

TestEvent::~TestEvent()
{
}

int TestEvent::process_packet(const struct pcap_pkthdr *header, const u_char *packet)
{
      return 0;
}

