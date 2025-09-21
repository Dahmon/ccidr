#include "../includes/ccidr.h"
#include <_ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Config *parse_args(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Missing CIDR argument\n");
    return NULL;
  }

  char *arg = argv[1];

  Config *config = malloc(sizeof(Config));

  if (config == NULL)
    return NULL;

  if (!parse_ip(arg, config)) {
    free(config);
    return NULL;
  }

  return config;
}

// TODO: Return specific values for specific issues, can be a global error code
int parse_ip(char *str, Config *config) {
  int j, i = 0;
  char range[3], c;

  // Check 1 character past expected length
  int cidr_len = strnlen(str, MAX_CIDR_LEN + 1);
  if (cidr_len < MIN_CIDR_LEN) {
    printf("CIDR argument is too short\n");
    return 0;
  }

  if (cidr_len > MAX_CIDR_LEN) {
    printf("CIDR argument is too long\n");
    return 0;
  }

  while (i < 4) {
    j = 0;
    char oct[4];

    while (isnumber(c = *str++) && j < 3)
      oct[j++] = c;
    oct[j] = '\0';

    if (i < 3 && c != '.') {
      printf("expected period. found: %c\n", c);
      return 0;
    }

    config->ip[i++] = atoi(oct);
  }

  if (c != '/') {
    printf("expected forward slash. found: %c\n", c);
    return 0;
  }

  j = 0;
  while (isnumber(c = *str++) && j < 2)
    range[j++] = c;
  range[j] = '\0';

  if (c != '\0') {
    printf("invalid char after CIDR range: %c\n", c);
    return 0;
  }

  config->range = atoi(range);

  return 1;
}
