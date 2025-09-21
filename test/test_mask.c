#include "../includes/ccidr.h"
#include "/usr/local/include/CUnit/CUnit.h"
#include <stdio.h>
#include <stdlib.h>

void test_base_ip() {
  Config *config = malloc(sizeof(Config));
  IP *ip = malloc(sizeof(IP));

  config->ip[0] = 123;
  config->ip[1] = 255;
  config->ip[2] = 82;
  config->ip[3] = 76;
  config->range = 19;

  get_base_ip(config, ip);

  CU_ASSERT(*ip[0] == 123);
  CU_ASSERT(*ip[1] == 255);
  CU_ASSERT(*ip[2] == 64);
  CU_ASSERT(*ip[3] == 0);
}
