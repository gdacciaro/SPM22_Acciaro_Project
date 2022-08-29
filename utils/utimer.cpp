#include "utimer.h"
#include "../setup/runtime_steps.h"

//constructor
uTimer::uTimer(const std::string& m) {
    message = m;
    us_elapsed = (long *)NULL;
    start = std::chrono::system_clock::now();
}

//destructor
uTimer::~uTimer() {
    if(!is_stopped){ //if the timer is not stopped, then we stop it
        auto musec = stop_timer();

        if(IS_UNIT_TEST_RUNNING == false) //if unit test is running, don't print the message
            cout << message << ": " << musec << " us" << endl;
    }
}

//stop timer and return elapsed time in microseconds
long long uTimer::stop_timer() {
    stop = chrono::system_clock::now(); //get the current time
    chrono::duration<double> elapsed = stop - start; //calculate the elapsed time

    auto musec = chrono::duration_cast<chrono::microseconds>(elapsed).count(); //convert to microseconds
    if (us_elapsed != NULL)
        (*us_elapsed) = musec;

    is_stopped = true;
    return musec; //return the elapsed time in microseconds
}