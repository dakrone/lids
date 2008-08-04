/* This is the class interface for being an event */

class LIDSEvent {
      public:
            LIDSEvent();
            /* virtual functions to be implemented by inheritors */
            virtual ~LIDSEvent();
            virtual int process_packet(const struct pcap_pkthdr *header, const u_char *packet);
};
