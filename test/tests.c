#include <stdio.h>
#include "CUnit/CUnit.h"

void test_args();

int main() {
  printf("Running all tests:\n");
  test_args();
  return 0;
}
