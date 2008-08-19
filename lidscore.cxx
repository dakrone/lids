#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
      static int count = 0;
      printf(".");
      fflush(stdout);
      count++;
      if (count >= 10) {
            printf("NrNrNrNr\n");
            fflush(stdout);
            exit(0);
      }
      return;
}

int LIDSCore::store(const struct pcap_pkthdr *header, const u_char *packet)
{
      return 0;
}

int LIDSCore::run()
{
      char *dev;
      char errbuf[PCAP_ERRBUF_SIZE];
      pcap_t* descr;
      bpf_program filter;
      bpf_u_int32 net;
      bpf_u_int32 mask;

      dev = pcap_lookupdev(errbuf);

      if(dev == NULL) {
            cout << "pcap_lookupdev(): " << errbuf << endl;
            exit(1);
      }

      /* print out device name */
      cout << "Dev: " << dev << endl;

      pcap_lookupnet(dev,&net,&mask,errbuf);

      descr = pcap_open_live(dev,BUFSIZ,1,0,errbuf);

      if(descr == NULL) {
            cout << "pcap_open_live(): " << errbuf << endl;
            exit(1);
      }

      if(pcap_compile(descr,&filter,"tcp",0,net) == -1) {
            cout << "Error calling pcap_compile" << endl;
            exit(1);
      }

      /* set the compiled program as the filter */
      if(pcap_setfilter(descr,&filter) == -1) {
            cout << "Error calling pcap_setfilter" << endl;
            exit(1);
      }

      pcap_loop(descr,-1,(pcap_handler)callback,NULL);

      return 0;
}

