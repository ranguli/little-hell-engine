#include <check.h>

/* Prototypes for setup functions from other test files */
TCase *registry_tests(void);
//TCase* foo_tests(void);

int main(void)
{
    Suite *s;
    SRunner *sr;
    int number_failed;

    s = suite_create("Little Hell Engine Tests");

    // Add test cases to the suite
    suite_add_tcase(s, registry_tests());
    //suite_add_tcase(s, foo_tests());

    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
