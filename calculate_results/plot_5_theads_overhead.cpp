#include "plot_5_theads_overhead.h"

void plot_5_theads_overhead(int n, int max_num_of_workers, int num_of_trial /*per la media*/){
    string TAG = "[RESULTS][PLOT_5][n="+to_string(n)+"]";
    string file_name = "./plot_5_theads_overhead_"+ to_string(n)+".csv";

    ofstream csv;
    csv.open (file_name);
    int index = 0;

    csv << "num_of_worker" << "\t" << "thead_creation_join_time" << "\n";

    vector<thread> threads;

    auto dummy_function = [&](int id, int start, int end) { // A dummy function to be executed by the threads, just to simulate the work.
        return;
    };

    for(int num_of_worker=1; num_of_worker<=max_num_of_workers; num_of_worker++){ // For each number of workers
        long total_time = 0;

        for(int trial=0; trial<num_of_trial; trial++) {// For each trial
            {
                uTimer utimer("overhead"); // Start the timer

                int chunk = (int) ceil(n / num_of_worker); // Calculate the chunk size

                for (int i = 0; i < num_of_worker-1; i++){ // Create the threads
                    int start = i * chunk;
                    int end = (i + 1) * chunk;
                    threads.emplace_back(dummy_function, i, start, end);
                }
                threads.emplace_back(dummy_function, num_of_worker, (num_of_worker-1) * chunk, n); // Create the last thread

                for (auto& thread : threads) { // Wait for all the threads to finish.
                    thread.join();
                }
                threads.clear();

                auto result = utimer.stop_timer();
                total_time  +=  result;
            }
        }
        float mean = (float)total_time / (float)num_of_trial;
        csv << num_of_worker << "\t" << mean << "\n";

        cout <<TAG<< " Writing result "<<index+1<<"/"<<max_num_of_workers<<" done."<< endl;
        index++;
    }


    csv.close();
}