#include "time.hpp"

int64_t getTimeUnix() {
        std::time_t result = std::time(nullptr);
        int64_t millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        return millisec_since_epoch;
}
 