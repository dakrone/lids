/*
 * LIDSCore will be the core of the lids system. Eventually it will be able to
 * capture packets using pcap, hand them off the event handlers and manage
 * threads
 */

#ifndef __LIDS_CORE__
#define __LIDS_CORE__

#include "lidsevent.h"
#include "lidsbuffer.h"

/* for u_char */
#include <sys/types.h>
#include <vector>

class LIDSCore {
      public:
            /* initializer */
            LIDSCore();
            /* destructor */
            ~LIDSCore();

            /* register an event handler with the Core */
            int core_register_event(LIDSEvent *e);
            std::vector<LIDSEvent*> core_get_registered_events();
            void core_process(const struct pcap_pkthdr *header, const u_char *packet);
            void core_dispatch();
            void core_store(const struct pcap_pkthdr *header, const u_char *packet);
      private:
            std::vector<LIDSEvent*> eventlist;
            LIDSBuffer* buff;
};

#endif
