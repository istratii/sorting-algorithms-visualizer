
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct node
{
  void *data;
  struct node *next;
  struct node *prev;
};

struct queue
{
  struct node *head;
  struct node *tail;
};

void queue_init(struct queue **queue);
void queue_push(struct queue *queue, void *data);
void queue_pop(struct queue *queue, void **data);
void queue_free(struct queue **queue, void (*data_free)(void *));

#endif /* ! QUEUE_H */
