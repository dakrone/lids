#include <iostream>
#include <pcap.h>
#include <sys/types.h>

#include "lidsbuffer.h"
#include "testevent.h"
#include "lidsdebug.h"

using namespace std;

TestEvent::TestEvent()
{
}

TestEvent::~TestEvent()
{
}

int TestEvent::process_packet(LIDSBuffer *buff)
{
      IN();
      puts("processing with: ");
      cout << buff->get_packet_count();
      puts(" packets in buffer");
      OUT();
      return 0;
}

char* TestEvent::get_event_name()
{
      IN();
      char* c = "Test Event";
      OUTp(c);
      return c;
}

