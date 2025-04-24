#include <stdlib.h>
#include "link.h"

Link* linkCreate(int id) {
    Link* l = (Link*)malloc(sizeof(Link));
    l->id = id;
    l->next = NULL;
    return l;
}

void linkAppend(Link** head, int id) {
    Link* newLink = linkCreate(id);
    if (!*head) {
        *head = newLink;
    } else {
        Link* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = newLink;
    }
}

void linkFree(Link* head) {
    while (head) {
        Link* tmp = head;
        head = head->next;
        free(tmp);
    }
}