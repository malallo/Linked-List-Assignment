#ifndef __CDLL_H__
#define __CDLL_H__

#ifndef NULL
#define NULL 0x00
#endif

#include <string>

class CDLLNode {
    private:
        // these will contain the timestamp and content of the tweet as strings
        std::string time;
        std::string tweet;

        // these are pointers to the next and previous nodes in the CDLL
        CDLLNode * next;
        CDLLNode * prev;

    public:
        CDLLNode(const char * ti, const char * tw);
        ~CDLLNode();

    friend class CDLL;
};

class CDLL {
    private:
        // pointer to the head/starting node in the CDLL
        CDLLNode * head;
        // this is a pointer to the 'current' node
        // allows methods to know the status of the 'current node'
        CDLLNode * current;

    public:
        CDLL();   // default constructor
        ~CDLL();  // default destructor (you are expected to destroy the linked list here)

        // makes an insertion at the front of the list
        void prepend(const char * time, const char * tweet);
        // makes an insertion at the end of the list
        void append(const char * time, const char * tweet);
        // moves 'current' to the next node
        void go_next();
        // moves 'current' to the previous node
        void go_prev();
        // moves 'current' to the head/first node
        void go_first();
        // moves 'current' to the last node
        void go_last();
        // moves 'current' n elements ahead (circularly)
        void skip(unsigned int n);
        // moves 'current' to the next occurrence of word
        void search(const char *word);
        // prints the 'current' tweet
        void print_current();
        // prints the times for all tweets
        void print_all();
};

#endif
