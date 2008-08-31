/* This is the class interface for being an event */

#ifndef __LIDS_EVENT__
#define __LIDS_EVENT__

#include <pcap.h>

#include "lidsbuffer.h"

class LIDSEvent {
      public:
            LIDSEvent();
            /* virtual functions to be implemented by inheritors */
            virtual ~LIDSEvent();
            virtual int process_packet(LIDSBuffer* buff);
            virtual char* get_event_name();
};

#endif
