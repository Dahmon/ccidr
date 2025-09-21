#include "/usr/local/include/CUnit/Basic.h"
#include <stdio.h>

void test_args();

CU_TestInfo args_tests[] = {
    {"test args", test_args},
    CU_TEST_INFO_NULL,
};

CU_SuiteInfo suites[] = {
    {"args", NULL, NULL, NULL, NULL, args_tests },
    CU_SUITE_INFO_NULL,
};

int main() {
  if (CU_initialize_registry()) {
    printf("CUnit init error: %d\n", CU_get_error());
    return 1;
  }

  if (CU_register_suites(suites)) {
    printf("CUNIT suite register error: %d\n", CU_get_error());
    return 1;
  }

  if (CU_basic_run_tests()) {
    printf("CUnit tests error: %d\n", CU_get_error());
    return 1;
  }

  CU_cleanup_registry();

  return 0;
}
