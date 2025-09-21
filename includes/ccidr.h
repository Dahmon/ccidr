#if !defined(C_CIDR_H)
#define C_CIDR_H

#define MIN_CIDR_LEN 9  // 1.1.1.1/1
#define MAX_CIDR_LEN 18 // 255.255.255.255/32
// 3 * 4 for each segment, 3 periods, and a null terminator
#define MAX_IP_LEN 16

typedef int IP[4];

typedef struct Config {
  IP ip;
  int range;
} Config;

typedef struct Cidr {
  IP base_ip;
  int range;
  char *broadcast[MAX_IP_LEN];
  char *first_ip[MAX_IP_LEN];
  char *last_ip[MAX_IP_LEN];
  int ip_count;
} Cidr;

Config *parse_args(int argc, char *argv[]);
int parse_ip(char *str, Config *config);

#endif
