cmake_minimum_required(VERSION 3.22)
project(SPM22_Acciaro_Project)

set(CMAKE_CXX_STANDARD 20)

include_directories("/Users/gennarodanieleacciaro/FF")

add_executable(main.cpp utils/utility.cpp
        utils/utility.h setup/constants.h utils/utimer.h solutions/sequential.cpp
        solutions/sequential.h solutions/parallel_threads.cpp solutions/parallel_threads.h
        unit_tests/UnitTestManager.cpp unit_tests/UnitTestManager.h
        unit_tests/test_utils/test_norm2.h unit_tests/test_utils/test_norm2.cpp
        unit_tests/test_utils/test_init_matrix_random_strictly_dominant.cpp unit_tests/test_utils/test_init_matrix_random_strictly_dominant.h
        unit_tests/test_utils/test_eucl_dist.cpp unit_tests/test_utils/test_eucl_dist.h
        utils/initializations.cpp utils/initializations.h utils/utimer.cpp
        unit_tests/solutions/test_sequential.cpp unit_tests/solutions/test_sequential.h
        unit_tests/solutions/test_fastflow.cpp unit_tests/solutions/test_fastflow.h
        unit_tests/solutions/test_parallel_threads.cpp unit_tests/solutions/test_parallel_threads.h
        utils/useful_classes/SolutionResult.h setup/runtime_steps.h setup/runtime_steps.cpp unit_tests/unit_test_utils.cpp unit_tests/unit_test_utils.h calculate_results/calculate_results.cpp calculate_results/calculate_results.h utils/argument_parser.cpp
        utils/argument_parser.h solutions/fast_flow.cpp solutions/fast_flow.h calculate_results/plot_1_speedup.cpp calculate_results/plot_1_speedup.h calculate_results/plot_2_scalability.cpp calculate_results/plot_2_scalability.h calculate_results/plot_3_efficiency.cpp calculate_results/plot_3_efficiency.h main.cpp calculate_results/plot_4_barrier_overhead.cpp calculate_results/plot_4_barrier_overhead.h calculate_results/plot_5_theads_overhead.cpp calculate_results/plot_5_theads_overhead.h)
