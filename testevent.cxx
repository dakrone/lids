#include <iostream>
#include <pcap.h>
#include <sys/types.h>

#include "lidsbuffer.h"
#include "testevent.h"
#include "lidsdebug.h"

using namespace std;

TestEvent::TestEvent()
{
      /*
       * the minimum number of packets to have in the buffer before generating
       * any alerts, this is to make sure we don't generate alerts for every
       * single new packet when lids is first run
       */
      pktbuffcount = 50;
}

TestEvent::~TestEvent()
{
}

/* returns true or false depending on whether an alert was generated */
bool TestEvent::process_packet(LIDSBuffer *buff)
{
      IN();
      bool alerted = false;
      /* only alert if we've reached the count threshold */
      if (buff->get_packet_count() > this->pktbuffcount) {
            puts("Alert! Received packet! (test event)");
            alerted = true;
      }

      OUTd(alerted);
      return alerted;
}

char* TestEvent::get_event_name()
{
      IN();
      char* c = "Test Event";
      OUTp(c);
      return c;
}

