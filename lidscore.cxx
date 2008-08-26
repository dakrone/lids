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
      for(cii=eventlist.begin();cii!=eventlist.end();cii++)
      {
            delete *cii;
      }
}

int LIDSCore::register_event(LIDSEvent *e)
{
      IN();
      this->eventlist.push_back(e);
      cout << "Registered event." << endl;
      OUTd(0);
      return 0;
}

void LIDSCore::process(const struct pcap_pkthdr *header)
{
      IN();
      this->store(header);
      this->dispatch();
      OUT();
}

void LIDSCore::dispatch()
{
      IN();
      OUT();
}

void LIDSCore::store(const struct pcap_pkthdr *header)
{
      IN();
      buff->store(header);
      OUT();
}

