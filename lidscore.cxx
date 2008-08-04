#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "lidsevent.h"
#include "lidscore.h"

using namespace std;

/*
 * Temporary code, this is the beginning template for  code that will
 * eventually kick off all the pcap captures, threading and packet-hand-
 * offing to the event handlers, which will generate alert messages.
 *
 * This, of course, assumes that everything works like I want it to, but hey,
 * aren't all projects like that?
 */
LIDSCore::LIDSCore()
{
}

LIDSCore::~LIDSCore()
{
}

int LIDSCore::setup()
{
      return 0;
}

int LIDSCore::register_event(LIDSEvent *e)
{
      return 0;
}

void LIDSCore::callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
      return;
}

int LIDSCore::store(const struct pcap_pkthdr *header, const u_char *packet)
{
      return 0;
}

int LIDSCore::run()
{
      char *dev;
      char *net;
      char *mask;
      int ret;
      char errbuf[PCAP_ERRBUF_SIZE];
      bpf_u_int32 netp;
      bpf_u_int32 maskp;
      struct in_addr addr;

      dev = pcap_lookupdev(errbuf);

      if(dev == NULL) {
            cout << errbuf << endl;
            exit(1);
      }

      /* print out device name */
      cout << "DEV: " << dev << endl;

      /* ask pcap for the network address and mask of the device */
      ret = pcap_lookupnet(dev,&netp,&maskp,errbuf);

      if(ret == -1) {
            cout << errbuf << endl;
            exit(1);
      }

      /* get the network address in a human readable form */
      addr.s_addr = netp;
      net = inet_ntoa(addr);

      if(net == NULL) {
            perror("inet_ntoa");
            exit(1);
      }

      cout << "NET: " << net << endl;

      /* do the same as above for the device's mask */
      addr.s_addr = maskp;
      mask = inet_ntoa(addr);

      if(mask == NULL) {
            perror("inet_ntoa");
            exit(1);
      }

      cout << "MASK: " << mask << endl;

      return 0;
}

