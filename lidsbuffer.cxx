#include <iostream>

#include "lidsbuffer.h"

LIDSBuffer::LIDSBuffer()
{
      type = 0;
      port = 0;
      src  = 0;
      dst  = 0;
      time = 0;
      size = 0;
      next = NULL;
}

LIDSBuffer::~LIDSBuffer()
{
      if (next != NULL) {
            free(next);
      }
}

bool LIDSBuffer::store(const struct pcap_pkthdr *header)
{
      return true;
}

int LIDSBuffer::cleanup()
{
      return 0;
}

char** LIDSBuffer::get_port_list()
{
      return NULL;
}

u_int LIDSBuffer::get_pps()
{
      return 100;
}

bool LIDSBuffer::unshift()
{
      return true;
}

bool LIDSBuffer::push(char type, int port, int src, int dst, int time, int size)
{
      return true;
}
