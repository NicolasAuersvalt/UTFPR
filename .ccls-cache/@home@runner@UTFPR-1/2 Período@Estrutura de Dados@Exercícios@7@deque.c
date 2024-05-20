#include "deque.h"

/* */
Deque* create_deque () {
  return NULL;
}

/* */
Point get_front (Deque *d) {
  if (d != NULL) {
    return d->p;
  }
}

/* */
Point get_back (Deque *d) {
  if (d != NULL) {
    Deque *aux = d; 
    while (aux->next != NULL) {
      aux = aux->next;
    }
    return aux->p;
  }
}

/* */
Deque* insert_front (Deque *d, Point p, char field[][SIZE]) {
  Deque *new_node = (Deque*)malloc(sizeof(Deque));
  new_node->p = p;
  new_node->prev = NULL;
  new_node->next = d;
  if (d != NULL) {
      d->prev = new_node;
  }
  return new_node;
}

/* */
Deque* insert_back (Deque *d, Point p, char field[][SIZE]) {
  Deque *new_node = (Deque*)malloc(sizeof(Deque));
  new_node->p = p;
  new_node->next = NULL;
  if (d == NULL) {
      new_node->prev = NULL;
      return new_node;
  }
  Deque *last = d;
  while (last->next != NULL) {
      last = last->next;
  }
  last->next = new_node;
  new_node->prev = last;
  return d;
}

/* */
Deque* delete_front (Deque *d, char field[][SIZE]) {
  if (d != NULL) {
    Deque *next_node = d->next;
    free(d);
    if (next_node != NULL) {
        next_node->prev = NULL;
    }
    return next_node;
  }
  return d;
}

/* */
Deque* delete_back (Deque *d, char field[][SIZE]) {
  if (d != NULL) {
    if (d->next == NULL) {
        free(d);
        return NULL;
    }
    Deque *last = d;
    while (last->next != NULL) {
        last = last->next;
    }
    Deque *prev_node = last->prev;
    prev_node->next = NULL;
    free(last);
  }
  return d;
}


