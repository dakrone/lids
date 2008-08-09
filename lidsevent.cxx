#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "lidsevent.h"

LIDSEvent::LIDSEvent()
{
}

LIDSEvent::~LIDSEvent()
{
}

int LIDSEvent::process_packet(const struct pcap_pkthdr *header, const u_char *packet)
{
      return 0;
}

