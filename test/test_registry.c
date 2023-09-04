#include <check.h>
#include "src/util/registry.h"

START_TEST(test_registry_create_successful)
{
    Registry *registry = registry_create();
    ck_assert_ptr_nonnull(registry);
}
END_TEST

TCase *registry_tests(void)
{
    TCase *tc = tcase_create("Registry");
    tcase_add_test(tc, test_registry_create_successful);
    // Add more registry tests as needed
    return tc;
}
