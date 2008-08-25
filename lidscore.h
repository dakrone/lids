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
            int register_event(LIDSEvent *e);
            void process();
            void dispatch();
            void store();
      private:
            std::vector<LIDSEvent*> eventlist;
            LIDSBuffer* buff;
};

#endif
