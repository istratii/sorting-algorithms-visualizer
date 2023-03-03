
#include <criterion/criterion.h>
#include <stdlib.h>

#include "../src/queue/queue.h"

Test(test_queue, test_0)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  queue_free(&queue, NULL);
}

Test(test_queue, test_1)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  int data = 42;

  queue_push(queue, &data);

  cr_assert_not_null(queue->head);
  cr_assert_not_null(queue->tail);
  cr_expect_null(queue->head->next);
  cr_expect_null(queue->tail->next);
  cr_expect_null(queue->head->prev);
  cr_expect_null(queue->tail->prev);
  cr_expect_eq(queue->head->data, &data);

  queue_free(&queue, NULL);
}

Test(test_queue, test_2)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  int this_data = 42;
  int that_data = 21;

  queue_push(queue, &this_data);
  queue_push(queue, &that_data);

  cr_assert_not_null(queue->head);
  cr_assert_not_null(queue->tail);
  cr_expect_null(queue->head->next);
  cr_expect_null(queue->tail->prev);
  cr_expect_eq(queue->head->prev, queue->tail);
  cr_expect_eq(queue->tail->next, queue->head);
  cr_expect_eq(queue->head->data, &this_data);
  cr_expect_eq(queue->tail->data, &that_data);

  queue_free(&queue, NULL);
}

Test(test_queue, test_3)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  int data = 42;

  queue_push(queue, &data);

  void *out = NULL;
  queue_pop(queue, &out);

  cr_expect_not_null(out);
  cr_expect_null(queue->head);
  cr_expect_null(queue->tail);
  cr_expect_eq(out, &data);

  queue_free(&queue, NULL);
}

Test(test_queue, test_4)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  int this_data = 42;
  int that_data = 21;

  queue_push(queue, &this_data);
  queue_push(queue, &that_data);

  void *out = NULL;
  queue_pop(queue, &out);

  cr_expect_not_null(out);
  cr_expect_not_null(queue->head);
  cr_expect_not_null(queue->tail);
  cr_expect_eq(queue->head, queue->tail);
  cr_expect_eq(queue->head->data, &that_data);
  cr_expect_eq(out, &this_data);

  queue_free(&queue, NULL);
}

Test(test_queue, test_5)
{
  struct queue *queue = NULL;

  queue_init(&queue);
  cr_assert_not_null(queue);

  int *data = malloc(sizeof(int));

  queue_push(queue, data);
  queue_free(&queue, free);
}
