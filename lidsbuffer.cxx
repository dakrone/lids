#include <iostream>
#include <sys/time.h>

#include "lidsbuffer.h"
#include "lidsdebug.h"
/* for packet information */
#include "packet_wrap.h"

using namespace std;

LIDSBuffer::LIDSBuffer()
{
      raw_packet_num = 0;
      buff_seconds = 30; /* 0.5 minutes */
}

LIDSBuffer::LIDSBuffer(unsigned int seconds)
{
      raw_packet_num = 0;
      buff_seconds = seconds;
}

LIDSBuffer::~LIDSBuffer()
{
}

bool LIDSBuffer::buff_store(const struct pcap_pkthdr *header, const u_char *packet)
{
      IN();
      /*
       * gotta create a copy of our struct, otherwise we don't actually add
       * anything to the list
       */
      struct pcap_pkthdr* h = (pcap_pkthdr *)malloc(sizeof(const struct pcap_pkthdr));
      u_char* p = (u_char *)malloc(sizeof(const u_char));
      memcpy(h,header,sizeof(const struct pcap_pkthdr));
      memcpy(p,packet,sizeof(const u_char));

      /* push the new struct on the end of the list */
      this->pkt_hdr_list.push_back(h);
      this->pkt_list.push_back(p);

      /* increase our raw packet number */
      this->raw_packet_num++;

      /* cleanup old packets */
      this->buff_cleanup();
      //int cc = this->buff_cleanup();

      /*
       *cout << "there have been: " << raw_packet_num << " packets added." << endl;
       *cout << "total: " << get_packet_count() << " packets." << endl;
       *if (cc >= 1)
       *{
       *      cout << "cleaned: " << cc << " packets" << endl;
       *      cout << "after cleanup: " << get_packet_count() << " packets" << endl;
       *}
       */

      OUTd(0);
      return true;
}

/* 
 * Right now, this function does not have any kind of accuracy other
 * than second accuracy, I don't care about microseconds right now
 *
 * This function returns the number of packets that were cleaned from the list
 */
int LIDSBuffer::buff_cleanup()
{
      IN();
      int cc = 0;
      timeval tim;
      gettimeofday(&tim, NULL);

      while ((this->pkt_hdr_list.size() >= 1) && (this->pkt_list.size() >= 1)) {

            int diff = pkt_hdr_list.back()->ts.tv_sec - pkt_hdr_list.front()->ts.tv_sec;
            if(diff > this->buff_seconds) {

                  /* this is for the header */
                  pcap_pkthdr* h = (pcap_pkthdr *)this->pkt_hdr_list.front();
                  free(h);
                  this->pkt_hdr_list.pop_front();

                  /* this is for the packet contents*/
                  u_char* p = (u_char *)this->pkt_list.front();
                  free(p);
                  this->pkt_list.pop_front();
                  cc++;
            } else {
                  /*
                   * TODO: Fix this so it doesn't break automatically, maybe
                   * have a limit of X packets before we think we won't hit
                   * any more and break?
                   */

                  break;
            }
      }

      OUTd(cc);
      return cc;
}

unsigned int LIDSBuffer::get_packet_count()
{
      IN();
      OUTd((int)this->pkt_hdr_list.size());
      return this->pkt_hdr_list.size();
}

/*
 * Return a 2-dimensional array of all the ports in the file.
 * The first array will be a list of the ports, the second is the number of
 * occurrences in the buffer. Basically a hash? Maybe I'll change it to
 * actually be an STL hash in the future.
 */
int** LIDSBuffer::get_port_list()
{
      IN();
      unsigned int i = 0;

	for (i = 0; i < this->pkt_list.size(); i++) {

		const u_char* packet = this->pkt_list[i];
		/* The Ethernet header */
		const struct sniff_ethernet *ethernet;
		/* The IP header */
		const struct sniff_ip *ip;
		/* XDP details */
		const struct sniff_udp *Xdp;
		/* And define the size of the structures we're using */
		int size_ethernet = sizeof(struct sniff_ethernet);
		int size_ip = sizeof(struct sniff_ip);
		u_short sport = 0;
		u_short dport = 0;

		/* -- Define our packet's attributes -- */
		ethernet = (struct sniff_ethernet*)(packet);
		ip = (struct sniff_ip*)(packet + size_ethernet);
		Xdp = (struct sniff_udp*)(packet + size_ethernet + size_ip);

		/* TODO: find the right offset for source port. */

		sport = Xdp->th_sport;
		if (sport != 0)
			printf("sport: %d\n",sport);
		dport = Xdp->th_dport;
		if (dport != 0)
			printf("dport: %d\n",dport);

	}

	OUT();
	return NULL;
}

u_int LIDSBuffer::get_pps()
{
	IN();
	OUT();
	return 100;
}

