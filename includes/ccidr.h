#if !defined(C_CIDR_H)
#define C_CIDR_H

#define MIN_CIDR_LEN 9  // 1.1.1.1/1
#define MAX_CIDR_LEN 18 // 255.255.255.255/32

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef int IP[4];

typedef struct Config {
  IP ip;
  int range;
} Config;

typedef struct Cidr {
  IP ip;
  int range;

  int ip_count;
  IP base_ip;
  IP mask;
  IP broadcast;
  IP first_ip;
  IP last_ip;
} Cidr;

Config *parse_args(int argc, char *argv[]);
int parse_ip(char *str, Config *config);
void get_base_ip(Config *config, IP *ip);

#endif
