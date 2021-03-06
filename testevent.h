/* this will be a test event, that will generate a message for every packet
 * that it handles, just to make sure everything is working.
 */

#ifndef __TEST_EVENT__
#define __TEST_EVENT__

#include <pcap.h>
#include <sys/types.h>

#include "lidsbuffer.h"
#include "lidsevent.h"
#include "lidsalarm.h"

class TestEvent: public LIDSEvent
{
      public:
            TestEvent();
            ~TestEvent();
            bool process_packet(LIDSBuffer* buff);
            char* get_event_name();
      private:
            unsigned int pktbuffcount;
            LIDSAlarm* ap;
};

#endif
