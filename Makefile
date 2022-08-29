CXX			= g++ -std=c++2a
CXX11		= g++-11 -std=c++2a
INCLUDES	= -I ${HOME}/fastflow

LDFLAGS 	= -pthread
OPTFLAGS	= -O3


CONSTANTS 		=	./setup/constants.h
RUNTIME_STEPS 	=	./setup/runtime_steps.cpp
INIT 			=	./utils/initializations.cpp
ARGPARSER 		=	./utils/argument_parser.cpp
UTIL 			=	./utils/utility.cpp
UTIMER 			=	./utils/utimer.cpp
SOL_RES 		=	./utils/useful_classes/SolutionResult.h

UNIT_TESTS_MANAGER	=	./unit_tests/UnitTestManager.cpp
UNIT_TESTS_SOLUTIONS_TH =	./unit_tests/solutions/test_parallel_threads.cpp
UNIT_TESTS_SOLUTIONS_SEQ =	./unit_tests/solutions/test_sequential.cpp
UNIT_TESTS_SOLUTIONS_FF =	./unit_tests/solutions/test_fastflow.cpp
UNIT_TESTS_UTILS1 	=	./unit_tests/test_utils/test_eucl_dist.cpp
UNIT_TESTS_UTILS2 	=	./unit_tests/test_utils/test_init_matrix_random_strictly_dominant.cpp
UNIT_TESTS_UTILS3 	=	./unit_tests/test_utils/test_norm2.cpp
UNIT_TESTS_UTILITY	=	./unit_tests/unit_test_utils.cpp

SOLUTION_TH	=	./solutions/parallel_threads.cpp
SOLUTION_SEQ	=	./solutions/sequential.cpp
SOLUTION_FAST_FLOW	=	./solutions/fast_flow.cpp

RESULTS = ./calculate_results/calculate_results.cpp
PLOT1 = ./calculate_results/plot_1_speedup.cpp
PLOT2 = ./calculate_results/plot_2_scalability.cpp
PLOT3 = ./calculate_results/plot_3_efficiency.cpp
PLOT4 = ./calculate_results/plot_4_barrier_overhead.cpp
PLOT5 = ./calculate_results/plot_5_theads_overhead.cpp

ALL_TESTS = $(UNIT_TESTS_MANAGER) $(UNIT_TESTS_SOLUTIONS_TH) $(UNIT_TESTS_SOLUTIONS_SEQ) $(UNIT_TESTS_SOLUTIONS_FF) $(UNIT_TESTS_UTILS1) $(UNIT_TESTS_UTILS2) $(UNIT_TESTS_UTILS3) $(UNIT_TESTS_UTILITY)
ALL_SOLUTIONS = $(SOLUTION_TH) $(SOLUTION_SEQ) $(SOLUTION_FAST_FLOW)
ALL_UTILITY = $(INIT) $(ARGPARSER) $(UTIL) $(UTIMER)
ALL_RESULTS = $(RESULTS) $(PLOT1) $(PLOT2) $(PLOT3) $(PLOT4) $(PLOT5)

main.out: main.cpp
	$(CXX) $(ALL_UTILITY) $(ALL_TESTS) $(ALL_SOLUTIONS) $(ALL_RESULTS) $(RUNTIME_STEPS) $(OPTFLAGS) $^ $(LDFLAGS) -o $@


clean:
	rm -rf *.out