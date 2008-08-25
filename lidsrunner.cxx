#include <pcap.h>
#include <iostream>
#include <sys/types.h>

#include "lidsrunner.h"

using namespace std;

/* global pointer to our core, declared in lids.cxx*/
extern LIDSCore *pcore;

LIDSRunner::LIDSRunner()
{
}

LIDSRunner::~LIDSRunner()
{
}

void LIDSRunner::callback(u_char *args, const struct pcap_pkthdr *header,
            const u_char *packet)
{
      cout << ".";
      fflush(stdout);
      pcore->process();
}

void LIDSRunner::start()
{
      /* initialize the class static core class */
      pcap_t* handle;
      char errbuf[PCAP_ERRBUF_SIZE];
      bpf_program filter;
      bpf_u_int32 net;
      bpf_u_int32 mask;
      char *dev;

      dev = pcap_lookupdev(errbuf);

      if(dev == NULL) {
            cout << "pcap_lookupdev(): " << errbuf << endl;
            exit(1);
      }

      /* print out device name */
      cout << "Dev: " << dev << endl;

      pcap_lookupnet(dev,&net,&mask,errbuf);

      handle = pcap_open_live(dev,BUFSIZ,1,0,errbuf);

      if(handle == NULL) {
            cout << "pcap_open_live(): " << errbuf << endl;
            exit(1);
      }

      if(pcap_compile(handle,&filter,"tcp",0,net) == -1) {
            cout << "Error calling pcap_compile" << endl;
            exit(1);
      }

      /* set the compiled program as the filter */
      if(pcap_setfilter(handle,&filter) == -1) {
            cout << "Error calling pcap_setfilter" << endl;
            exit(1);
      }

      pcap_loop(handle,-1,(pcap_handler)callback,NULL);

      free(handle);
      free(dev);
}

