/*
 * This is the file to handle the linked-list of packet headers, it will also
 * calculate information about the packets contained in the buffer
 */

#ifndef __LIDSBUFFER__
#define __LIDSBUFFER__

#include <pcap.h>
#include <sys/types.h>
#include <list>

class LIDSBuffer
{
      public:
            LIDSBuffer();
            LIDSBuffer(unsigned int seconds);
            ~LIDSBuffer();
            bool buff_store(const struct pcap_pkthdr *header, const u_char *packet);
            int buff_cleanup();
            char** get_port_list();
            u_int get_pps();
            unsigned int get_packet_count();

      private:
 
            /* variables */
            std::list<const struct pcap_pkthdr *> pkt_hdr_list;
            std::list<const u_char *> pkt_list;

            unsigned int raw_packet_num;
            int buff_seconds;

};

#endif
