#include "../includes/ccidr.h"
#include "/usr/local/include/CUnit/CUnit.h"
#include <stdio.h>
#include <stdlib.h>

void test_args() {
  Config *config = malloc(sizeof(Config));

  char *ip = "123.456.789.876/16";
  parse_ip(ip, config);

  CU_ASSERT(config->ip[0] == 123);
  CU_ASSERT(config->ip[1] == 456);
  CU_ASSERT(config->ip[2] == 789);
  CU_ASSERT(config->ip[3] == 876);
  CU_ASSERT(config->range == 16);
}
