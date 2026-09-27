#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

typedef struct Header Header;

struct Header {
  size_t count;
  size_t cap;
  char* buf;
};

static void push_ (Header* head ,char val) {
  if (head->count >= head->cap) {
    head->buf = realloc(head->buf, head->cap += 5);
  }
  head->buf[head->count++] = val;
}

static char pop_(Header* head) {
  if (!head->count || !head->cap) exit(1);
  return head->buf[--head->count];
}

static void print_(Header* head){
  size_t i; 
  for (i = 0; i < head->count; i++) {
    printf("INDEX: %ld, ELEMENT: %c\n", i, head->buf[i]);
  }
  printf("BUF_SIZE: %ld, BUF_CAP: %ld\n", head->count, head->cap);
}

static void insert_(Header* head, size_t pos, char ch) {
  if (head->count >= head->cap) {
    head->buf = realloc(head->buf, head->cap += 5);
  }
  if (pos >= head->count) {
    exit(1);
  }
  memmove(&head->buf[pos+1], &head->buf[pos], head->count++ - pos);
  head->buf[pos] = ch;
}
  
int main(void) {
  int c;
  Header arr = {0};
  for (c = 0; c < 15; c++) {
    push_(&arr,'A' + c);
  }
  assert(arr.cap == 15);
  assert(arr.count == 15);

  insert_(&arr, 5, 'Z');

  assert(arr.count == 16);
  assert(arr.cap == 20);
  return 0;
}
