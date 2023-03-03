
#include "queue.h"

static void node_init(struct node **node, void *data)
{
  if (node == NULL)
    return;

  *node = malloc(sizeof(struct node));

  if ((*node) == NULL)
    return;

  (*node)->next = NULL;
  (*node)->prev = NULL;
  (*node)->data = data;
}

void queue_init(struct queue **queue)
{
  if (queue == NULL)
    return;

  *queue = malloc(sizeof(struct queue));

  if ((*queue) == NULL)
    return;

  (*queue)->head = NULL;
  (*queue)->tail = NULL;
}

void queue_push(struct queue *queue, void *data)
{
  if (queue == NULL)
    return;

  if (queue->head == NULL)
  {
    node_init(&(queue->head), data);
    queue->tail = queue->head;
  }
  else
  {
    struct node *node = NULL;
    node_init(&node, data);
    node->next = queue->tail;
    queue->tail->prev = node;
    queue->tail = node;
  }
}

void queue_pop(struct queue *queue, void **data)
{
  if (data == NULL)
    return;

  *data = NULL;

  if (queue == NULL || queue->head == NULL)
    return;

  struct node *head = queue->head;
  *data = head->data;
  queue->head = queue->head->prev;
  free(head);

  if (queue->head == NULL)
    queue->tail = NULL;
  else
    queue->head->next = NULL;
}

void queue_free(struct queue **queue, void (*data_free)(void *))
{
  if (queue == NULL || *queue == NULL)
    return;

  struct node *iter = (*queue)->tail;
  struct node *next = NULL;

  while (iter != NULL)
  {
    next = iter->next;

    if (data_free != NULL)
      data_free(iter->data);

    free(iter);
    iter = next;
  }

  free(*queue);
  *queue = NULL;
}
