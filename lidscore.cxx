#include <iostream>
#include <vector>

#include "lidscore.h"
#include "lidsbuffer.h"
#include "lidsdebug.h"

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
      this->buff = new LIDSBuffer();
}

LIDSCore::~LIDSCore()
{
      delete buff;
      vector<LIDSEvent*>::const_iterator cii;
      for(cii=eventlist.begin();cii!=eventlist.end();cii++) {
            delete *cii;
      }
}

vector<LIDSEvent*> LIDSCore::core_get_registered_events()
{
      IN();
      /* debug pointer for OUTp */
#ifdef DEBUG
      vector<LIDSEvent*>* p = &this->eventlist;
      OUTp(p);
#endif
      return this->eventlist;
}

int LIDSCore::core_register_event(LIDSEvent *e)
{
      IN();
      this->eventlist.push_back(e);
      cout << "Registered event: " << e->get_event_name() << endl;
      OUTd(0);
      return 0;
}

void LIDSCore::core_process(const struct pcap_pkthdr *header, const u_char *packet)
{
      IN();
      this->core_store(header, packet);
      this->core_dispatch();
      OUT();
}

void LIDSCore::core_dispatch()
{
      IN();
      for (u_int i = 0; i < this->eventlist.size(); i++) {
            //cout << "dispatching to: ";
            //cout << this->eventlist[i]->get_event_name() << endl;
            this->eventlist[i]->process_packet(this->buff);
      }
      OUT();
}

void LIDSCore::core_store(const struct pcap_pkthdr *header, const u_char *packet)
{
      IN();
      buff->buff_store(header, packet);
      OUT();
}

