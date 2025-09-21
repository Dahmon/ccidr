#include "../includes/ccidr.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Config *config = parse_args(argc, argv);

  if (config == NULL) {
    return EXIT_FAILURE;
  }

  printf("ip: %d.%d.%d.%d\n", config->ip[0], config->ip[1], config->ip[2],
         config->ip[3]);
  printf("range: %d\n", config->range);

  free(config);
}
