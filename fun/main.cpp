#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;

// =====================
// ENUM FOR MACHINE STATE
// =====================
enum class ClockState {
    RUNNING,
    PAUSED,
    DEAD
};


// =====================
// MAIN FUNCTION
// =====================
int main() {
    SmartClock clock;

    clock.setTime(10, 58, 50);
    clock.setAlarm(10, 59);
    clock.startStopwatch();

    return 0;
}
