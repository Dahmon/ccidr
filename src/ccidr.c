#include "../includes/ccidr.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Config *config = parse_args(argc, argv);
  IP *ip = malloc(sizeof(IP));

  if (config == NULL || ip == NULL) {
    return EXIT_FAILURE;
  }

  get_base_ip(config, ip);

  printf("ip: %d.%d.%d.%d\n", config->ip[0], config->ip[1], config->ip[2],
         config->ip[3]);
  printf("range: %d\n", config->range);
  printf("base ip: %d.%d.%d.%d\n", *ip[0], *ip[1], *ip[2], *ip[3]);

  free(config);
}
