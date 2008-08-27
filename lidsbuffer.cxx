#include <iostream>

#include "lidsbuffer.h"
#include "lidsdebug.h"

using namespace std;

LIDSBuffer::LIDSBuffer()
{
      type = 0;
      port = 0;
      src  = 0;
      dst  = 0;
      time = 0;
      size = 0;
      next = NULL;
      head = NULL;
      packet_num = 0;
}

LIDSBuffer::~LIDSBuffer()
{
      if (next != NULL) {
            free(next);
      }
}

bool LIDSBuffer::buff_store(const struct pcap_pkthdr *header)
{
      IN();
      if (packet_num <= 0) {
            head = this;
      }
      else
      {
            packet_num++;
            cout << "there are now: " << packet_num << " packets" << endl;
      }

      OUTd(0);
      return true;
}

int LIDSBuffer::buff_cleanup()
{
      IN();
      OUT();
      return 0;
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

bool LIDSBuffer::unshift()
{
      IN();
      OUT();
      return true;
}

bool LIDSBuffer::push(char type, int port, int src, int dst, int time, int size)
{
      IN();
      OUT();
      return true;
}
