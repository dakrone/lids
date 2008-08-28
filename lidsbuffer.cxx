#include <iostream>

#include "lidsbuffer.h"
#include "lidsdebug.h"

using namespace std;

LIDSBuffer::LIDSBuffer()
{
      raw_packet_num = 0;
      buff_seconds = 300; /* 5 minutes */
}

LIDSBuffer::LIDSBuffer(unsigned int seconds)
{
      raw_packet_num = 0;
      buff_seconds = seconds;
}

LIDSBuffer::~LIDSBuffer()
{
}

bool LIDSBuffer::buff_store(const struct pcap_pkthdr *header)
{
      IN();
      this->pkt_hdr_list.push_back(header);
      this->raw_packet_num++;
      int cc = this->buff_cleanup();
      cout << "there have been: " << raw_packet_num << " packets added." << endl;
      cout << "cleaned: " << cc << " packets" << endl;
      cout << "after cleanup: " << get_packet_count() << " packets" << endl;

      OUTd(0);
      return true;
}

int LIDSBuffer::buff_cleanup()
{
      IN();
      int cc = 0;

      u_int i;
      for(i=0; i<this->pkt_hdr_list.size(); i++)
      {
            /* TODO business logic for removing packets that are expired */
            cc++;
      }

      OUTd(cc);
      return cc;
}

unsigned int LIDSBuffer::get_packet_count()
{
      IN();
      OUTd(this->pkt_hdr_list.size());
      return this->pkt_hdr_list.size();
}

char** LIDSBuffer::get_port_list()
{
      IN();
      OUT();
      return NULL;
}

u_int LIDSBuffer::get_pps()
{
      IN();
      OUT();
      return 100;
}

