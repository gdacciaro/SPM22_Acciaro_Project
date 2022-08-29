#ifndef SPM22_ACCIARO_PROJECT_UTIMER_H
#define SPM22_ACCIARO_PROJECT_UTIMER_H

#include <chrono>
#include <iostream>

using namespace std;

class uTimer{
    chrono::system_clock::time_point start;
    chrono::system_clock::time_point stop;
    string message;
    bool is_stopped = false;

private:
    long *us_elapsed;

public:
    uTimer(const string& m);
    ~uTimer();
    long long stop_timer();
};

#endif //SPM22_ACCIARO_PROJECT_UTIMER_H
