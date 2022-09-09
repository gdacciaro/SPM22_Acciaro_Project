#include "utils/initializations.h"
#include "utils/argument_parser.h"
#include "solutions/sequential.h"
#include "solutions/parallel_threads.h"
#include "solutions/fast_flow.h"
#include "setup/constants.h"
#include "calculate_results/calculate_results.h"
#include "unit_tests/UnitTestManager.h"

using namespace std;

int main(int argc, char** argv){
    srand(RANDOM_SEED ? time(NULL) : 42);

    auto args = ArgumentParser::parse_arguments(argc, argv);

    const int n = args.n;
    const int number_of_worker = args.num_of_worker;
    const bool calc_results = args.calc_results;
    const int number_of_iteration = args.num_of_iteration;
    const bool early_stopping = args.early_stopping;
    const bool execute_unit_test = args.execute_unit_test;

    {
        UnitTestManager unit_test_manager(execute_unit_test); // Run the unit tests if necessary
    }

    if(n>0){
        if (DEBUG){
            cout << "====== PARAMS ======"<< endl;
            cout<<"\t n: "<<n<<"\n";
            cout<<"\t number_of_worker: "<<number_of_worker<<"\n";
            cout<<"\t calc_results: "<<(calc_results==1?"true":"false")<<"\n";
            cout<<"\t number_of_iteration: "<<number_of_iteration<<"\n";
            cout<<"\t early_stopping: "<<(early_stopping==1?"true":"false")<<"\n";
        }

        cout<<"[INIT] Running initialization..."<<endl;
        cout<<"[INIT] Generating a matrix of "<<n<<"*"<<n<<"..."<<endl;
        vector<vector<float>> A = init_matrix_random_strictly_dominant(n);
        vector<float> b = init_vector_random(n);
        cout<<"[INIT] Initialization completed."<<endl<<endl<<endl;

        auto result_sequential= solve_jacobi_sequentially(A, b, number_of_iteration, early_stopping);
        auto result_parallel = solve_jacobi_with_threads(A, b, number_of_worker, number_of_iteration, early_stopping);
        auto result_parallel_just_one_thread = solve_jacobi_with_threads(A, b, 1);
        auto result_fast_flow = solve_jacobi_with_fastflow(A, b, number_of_worker, number_of_iteration, early_stopping);

        /* Prediction phase */
        auto time_seq = result_sequential.time;
        auto overhead1_start_join_thread = (float) get_create_join_thread_time(n, number_of_worker);
        auto overhead2_barrier = (result_parallel.total_barrier_time/(float)number_of_worker);
        float total_overheads = overhead1_start_join_thread + overhead2_barrier;
        cout<<" ========================= "<<endl;
        cout<<"Thread Overhead = "<<overhead1_start_join_thread<<endl;
        cout<<"Barrier Overhead = "<<overhead2_barrier<<endl;
        cout<<"Total Overheads = "<<total_overheads<<endl;

        auto time_ideal = (float) time_seq/(float)number_of_worker;
        auto predicted_speedup = (float)time_seq/(time_ideal+total_overheads);

        cout<<" ========================= "<<endl;
        cout<<"\tPredicted speedup\t\t"<<predicted_speedup<<endl;
        cout<<" ========================= "<<endl;

        cout << "barrier time Par(N) " << result_parallel.total_barrier_time << endl;
        cout << "barrier time Par(1) " << result_parallel_just_one_thread.total_barrier_time << endl;

        cout<<" ======== Metrics ======== "<<endl;
        cout<<"SEQ:\t\t\t"<< result_sequential.time<<endl;
        cout<<"PAR("<<number_of_worker<<"):\t\t\t"<<  result_parallel.time<<endl;
        cout<<"PAR("<<1<<"):\t\t\t"<<  result_parallel_just_one_thread.time<<endl;
        cout<<"FASTFLOW:\t\t"<< result_fast_flow.time<<endl;
        cout<<" ========================= "<<endl;

        auto speedup = ((float)result_sequential.time/(float) result_parallel.time);
        cout<<"Speedup:\t\t"<<speedup<<endl;
        cout<<"Scalability:\t"<<((float)result_parallel_just_one_thread.time/(float) result_parallel.time)<<endl;
        cout<<"Efficiency:\t\t"<<(speedup/(float)number_of_worker)<<endl;
        cout<<" ========================= "<<endl;
        cout<<"\tPredicted speedup\t\t"<<predicted_speedup<<endl;
        cout<<"\tMeasured speedup\t\t"<<speedup<<endl;
        cout<<" ========================= "<<endl;
    }

    if(calc_results){
        calculate_results();
        system("./msg.sh");
    }
    return 0;
}