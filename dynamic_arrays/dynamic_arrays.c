#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

static char *buf;
static int buf_size;
static int buf_cap;

static void push_(char val) {
  if (buf_size >= buf_cap) {
    buf = realloc(buf, buf_cap += 5);
  }
  buf[buf_size++] = val;
}

static char pop_(void) {
  if (!buf_size || !buf_cap) exit(1);
  return buf[--buf_size];;
}

static void print_(void){
  int i; 
  for (i = 0; i < buf_size; i++) {
    printf("INDEX: %d, ELEMENT: %c\n", i, buf[i]);
  }
  printf("BUF_SIZE: %d, BUF_CAP: %d\n", buf_size, buf_cap);
}

static void insert_(int pos, char ch) {
  if (buf_size >= buf_cap) {
    buf = realloc(buf, buf_cap += 5);
  }
  if (pos >= buf_size ||  pos < 0){
    exit(1);
  }
  memmove(&buf[4], &buf[3], buf_size - 3);
  buf[3] = ch;
  buf_size++;
}
  
int main(void) {
  int c;

  for (c = 0; c < 15; c++) {
    push_('A' + c);
  }

  assert(buf_cap == 15);
  assert(buf_size == 15);
  insert_(5, 'Z');
  assert(buf_size == 16);
  assert(buf_cap == 20);
  return 0;
}
