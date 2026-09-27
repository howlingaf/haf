#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

typedef struct Header {
  size_t count;           
  size_t cap;               
} Header;

#define PUSH(T, ptr, val)                                                                   \
  Header* header;                                                                           \
  if (ptr == NULL) {                                                                        \
    header = (Header*) malloc(sizeof(Header) + sizeof(val) * 5);                            \
    header->count = 0;                                                                      \
    header->cap = 5;                                                                        \
  }                                                                                         \
  ptr = (T*) (header + 1);                                                                  \
  header = ((Header*) ptr) - 1;                                                             \
  if (header->count >= header->cap) {                                                       \
    header = (Header*) realloc(header, sizeof(Header) + sizeof(val) * (header->count + 5)); \
    header->cap+=5;                                                                         \
  }                                                                                         \
  ptr = (T*) (header + 1);                                                                  \
  ((T*)(ptr))[header->count] = val;                                                         \
    (header->count++);                                                                      \

int main(void) {
  int* buf = NULL;
  PUSH(int, buf, 12);
   assert(buf[0] == 12);

  return 0;
}
