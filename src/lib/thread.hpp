#include <thread>
#include "threadcout.hpp"

/**
 * @brief Multithreads a function
 * The inputs of the function must be ( int threads , bool started )
 * \n Use @ cp
 * 
 * @param func Function to run 
 * @param threads Amount of threads
 */
void multithread(void(*func)(int, bool), int threads, bool print ) {
    bool started = false;

    int num_mt_threads = (4);

    std::thread mt_threads[num_mt_threads];

    int i = 0;

    while (i < num_mt_threads) {
        mt_threads[i] = std::thread(func, (int)i, &started);
        i++;
    }

    synccout << "Threads created!\n";
    started = true;

    for(int counter = 0; counter < num_mt_threads; counter = counter + 1) {
        started = true;
        if(mt_threads[counter].joinable()) {
            synccout << "Joining thread " << counter << "\n";
            mt_threads[counter].join();
        }
    }
}