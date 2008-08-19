/*
 * This is the file to handle the linked-list of packet headers, it will also
 * calculate information about the packets contained in the buffer
 */

#ifndef __LIDSBUFFER__
#define __LIDSBUFFER__

#include <pcap.h>
#include <sys/types.h>

class LIDSBuffer
{
      public:
            LIDSBuffer();
            ~LIDSBuffer();
            bool store(const struct pcap_pkthdr *header);
            int cleanup();
            char** get_port_list();
            u_int get_pps();

      private:
            bool unshift();
            bool push(char type, int port, int src, int dst, int time, int size);
 
            /* variables */
            char type;
            int port;
            int src;
            int dst;
            int time;
            int size;
            LIDSBuffer* next;

};

#endif
