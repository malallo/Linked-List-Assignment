#include "cdll.h"
#include <iostream>
#include <algorithm>

CDLLNode::CDLLNode(const char *ti, const char *tw) {
    time = ti;
    tweet = tw;
    next = NULL;
    prev = NULL;
}

CDLLNode::~CDLLNode() {
    // no dynamic memory allocation, nothing to destroy
}

CDLL::CDLL() {
    head=NULL;
    current=NULL;
}

CDLL::~CDLL() {
    current = head->next;
    while(current->next != head){
        CDLLNode *n = current;
        current = current->next;
        delete n;
    }
    delete head;
}
void CDLL::prepend(const char *time, const char *tweet) {
    if(head==NULL){
        CDLLNode *add=new CDLLNode(time, tweet);
        add->next=add;
        add->prev=add;
        head=add;
        return;
    }
    CDLLNode *add=new CDLLNode(time, tweet);
    add->next=head;
    add->prev=head->prev;
    head->prev->next=add;
    head->prev=add;
    head=add;
}

void CDLL::append(const char * time, const char * tweet) {
    if(head==NULL){
        CDLLNode *add=new CDLLNode(time, tweet);
        add->next=add;
        add->prev=add;
        head=add;
        return;
    }
    CDLLNode *add=new CDLLNode(time, tweet);
    add->next=head;
    add->prev=head->prev;
    head->prev->next=add;
    head->prev=add;
}

void CDLL::go_next() {
    if(!head){
        return;
    }
    current = current->next;
}

void CDLL::go_prev() {
    if(!head){
        return;
    }
    current = current->prev;
}

void CDLL::go_first() {
    if(!head){
        return;
    }
    current = head;
}

void CDLL::go_last() {
    if(!head){
        return;
    }
    current = head->prev;
}

void CDLL::skip(unsigned int n) {
    if(!head || n <= 0){
        return;
    }
    for(unsigned int i = 0; i < n; i++){
        current = current->next;
    }
}

void CDLL::search(const char *word) {
    std::string check = word;
    if (check=="s\0") {
        current=current->next;
        return;
    }

    CDLLNode *spot=current;
    current=current->next;

    int space=check.find(" ");
    check=check.substr(space+1);
    for (int i=0; check[i]; i++){
        check[i]=tolower(check[i]);
    }

    while (current!=spot){
        std::string twet=current->tweet;
        for (int j=0; twet[j]; j++){
            twet[j]=tolower(twet[j]);
        }
        if(twet.find(check)!=std::string::npos){
            return;
        }
        current=current->next;
    }
}

void CDLL::print_current() {
    if (current) {
        std::cout << current->time.substr(0,19) << "    " << current->tweet << std::endl;
    }
}

void CDLL::print_all() {
    if (head) {
        CDLLNode *p = head;
        while (1) {
            std::cout << p->time << " ";
            if (p->next == head) {
                break;
            } else {
                p = p->next;
            }
        }
    }
    std::cout << std::endl;
}
