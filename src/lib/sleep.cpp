#include "sleep.hpp"

namespace sleeps {

    void seconds(long long s) {
        std::this_thread::sleep_for(std::chrono::seconds(s));
    }

    void milliseconds(long long ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    void nanoseconds(long long ns) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
    }

    void microseconds(long long us) {
        std::this_thread::sleep_for(std::chrono::microseconds(us));
    }

}