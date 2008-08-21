#ifndef __LIDS_RUNNER__
#define __LIDS_RUNNER__

#include <sys/types.h>

#include "lidscore.h"

class LIDSRunner
{
      public:
            LIDSRunner();
            ~LIDSRunner();
            /* the callback must be static in order for pcap_loop to work */
            static void callback(u_char *args, const struct pcap_pkthdr *header,
                        const u_char *packet);
            /* setup function to initialize pcap setup */
            void setup();
            /* start the capture */
            void run();
      private:
            static LIDSCore* core;
            static pcap_t* handle;
            char errbuf[PCAP_ERRBUF_SIZE];
            bpf_program filter;
            bpf_u_int32 net;
            bpf_u_int32 mask;
            char *dev;

};

/* initialize the class static core class */
LIDSCore* LIDSRunner::core = new LIDSCore();
pcap_t* LIDSRunner::handle = NULL;

#endif
