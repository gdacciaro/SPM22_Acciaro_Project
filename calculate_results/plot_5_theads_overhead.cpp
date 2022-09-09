#include "plot_5_theads_overhead.h"


long long get_create_join_thread_time(int n, int num_of_workers){
    vector<thread> threads;
    auto dummy_function = [&](int id, int start, int end) { // A dummy function to be executed by the threads, just to simulate the work.
        return;
    };

    {
        uTimer utimer("overhead"); // Start the timer

        int chunk = (int) ceil(n / num_of_workers); // Calculate the chunk size

        for (int i = 0; i < num_of_workers-1; i++){ // Create the threads
            int start = i * chunk;
            int end = (i + 1) * chunk;
            threads.emplace_back(dummy_function, i, start, end);
        }
        threads.emplace_back(dummy_function, num_of_workers, (num_of_workers-1) * chunk, n); // Create the last thread

        for (auto& thread : threads) { // Wait for all the threads to finish.
            thread.join();
        }
        threads.clear();

        auto result = utimer.stop_timer();
        return result;
    }
}

void plot_5_threads_overhead(int n, int max_num_of_workers, int num_of_trial /*per la media*/){
    string TAG = "[RESULTS][PLOT_5][n="+to_string(n)+"]";
    string file_name = "./plot_5_theads_overhead_"+ to_string(n)+".csv";

    ofstream csv;
    csv.open (file_name);
    int index = 0;

    csv << "num_of_worker" << "\t" << "thead_creation_join_time" << "\n";


    for(int num_of_worker=1; num_of_worker<=max_num_of_workers; num_of_worker++){ // For each number of workers
        long total_time = 0;

        for(int trial=0; trial<num_of_trial; trial++) {// For each trial
            total_time+=get_create_join_thread_time(n, num_of_worker);
        }
        float mean = (float)total_time / (float)num_of_trial;

        csv << num_of_worker << "\t" << mean << "\n";
        cout << num_of_worker << "\t" << mean << "\n";

        cout <<TAG<< " Writing result "<<index+1<<"/"<<max_num_of_workers<<" done."<< endl;
        index++;
    }


    csv.close();
}