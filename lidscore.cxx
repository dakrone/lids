#include <iostream>
#include <vector>

#include "lidscore.h"
#include "lidsbuffer.h"

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
      for(cii=eventlist.begin();cii!=eventlist.end();cii++)
      {
            delete *cii;
      }
}

int LIDSCore::register_event(LIDSEvent *e)
{
      this->eventlist.push_back(e);
      cout << "Registered event." << endl;
      return 0;
}

void LIDSCore::process(const struct pcap_pkthdr *header)
{
      cout << "processing packet" << endl;
      this->store(header);
      this->dispatch();
}

void LIDSCore::dispatch()
{
      cout << "dispatching event" << endl;
}

void LIDSCore::store(const struct pcap_pkthdr *header)
{
      cout << "storing packet" << endl;
      buff->store(header);
}

