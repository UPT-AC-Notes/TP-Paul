#include "list.h"

#define SIZE 10

int main(int argc, char *argv[]) {

  if (argc != 2) {
    perror("Invalid number of arguments -> need 1 -> LIST DEBUG");
    return 0;
  }

  LIST_DEBUG = atoi(argv[1]);

  list_t list = init_list();

  for (int i = 0; i < 100; i++)
    add_front_node(&list, i);

  for (int i = 0; i < 100; i++)
    add_rear_node(&list, i);

  for (int i = 0; i < 50; i++)
    pop_front(&list);

  for (int i = 0; i < 50; i++)
    pop_rear(&list);

  print_list(&list);

  free_list(&list);

  return 0;
}
