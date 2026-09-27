#include<stdlib.h>

#include<stdio.h>

#include<string.h>

#include<assert.h>



Header header = {.size = 69, .count = 420};
Header header = {69,420}


typedef struct Header {

  size_t count;           

  size_t cap;               

} Header;



 //`Header* ptr = ptr` with `Header* header = (Header*)(ptr - 1)` and replace `(tptr + 1)` with `ptr`

#define PUSH(T, ptr, val)                                                                                           \
  Header* header;                                                                                                   \
  if (ptr == NULL) {                                                                                                \
    header = (Header*) malloc(sizeof(Header) + sizeof(val) * 5);                                                     \
    header->count = 0;                                                                                               \
    header->cap = 5;                                                                                                 \
    ptr = (T*) (header + 1);                                                                                       \
  }                                                                                                                \
  if (header->count >= header->cap) {                                                                              \
    header = (Header*) realloc( ptr, sizeof(Header) + sizeof(val) * (header->count + 5));                                \
    header->cap+=5;                                                                                                    \
  }                                                                                                                 \
  ((T*)(ptr))[header->count] = val;                                                                                    \
    (header->count++);                                                                                                 \

int main(void) {
  nt* buf = NULL;
  PUSH(int, buf, 12);
   assert(buf[0] == 12);
  return 0;

}

