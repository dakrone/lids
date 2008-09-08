/* This event hopes to be the first *actual* event for lids */

#ifndef __PORTEVENT__
#define __PORTEVENT__

#include "lidsevent.h"
#include "lidsbuffer.h"

class PortEvent: public LIDSEvent {
      public:
            PortEvent();
            ~PortEvent();
            bool process_packet(LIDSBuffer* buff);
            char* get_event_name();

      private:
            int low_port_threshold;


};

#endif
