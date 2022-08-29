#ifndef SPM22_ACCIARO_PROJECT_UNITTESTMANAGER_H
#define SPM22_ACCIARO_PROJECT_UNITTESTMANAGER_H

#include "test_utils/test_norm2.h"
#include "test_utils/test_eucl_dist.h"
#include "test_utils/test_init_matrix_random_strictly_dominant.h"
#include "solutions/test_sequential.h"
#include "solutions/test_parallel_threads.h"
#include "solutions/test_fastflow.h"
#include "../setup/constants.h"
#include "../setup/runtime_steps.h"

class UnitTestManager{
public:
    UnitTestManager(bool execute_unit_test);
    ~UnitTestManager();
    static void run_unit_test();
};


#endif //SPM22_ACCIARO_PROJECT_UNITTESTMANAGER_H
