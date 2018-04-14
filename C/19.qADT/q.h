#ifndef Q_H
#define Q_H

#include <stdbool.h>

typedef char *Item;
typedef struct q_type *Q;

Q q_create(void);
bool q_destroy(Q q);
bool q_insert_item(Q q, Item it);
Item q_pop_item(Q q);
Item q_first_item(Q q);
Item q_last_item(Q q);
bool q_is_empty(Q q);

#endif
