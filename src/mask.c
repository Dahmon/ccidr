#include "../includes/ccidr.h"
#include <stdio.h>

void get_base_ip(Config *config, IP *ip) {
  for (int i = 0; i < 4; i++) {
    int end_bit = (i + 1) * 8;
    int free_bits = config->range >= end_bit ? 0 : MIN(8, end_bit - config->range);
    int mask = 0xFF << free_bits;
    *ip[i] = config->ip[i] & mask;
  }
}
