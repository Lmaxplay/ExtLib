#include <iostream>
#include <thread>
#include <sstream>

/** Thread safe cout class
  * Exemple of use:
  *    PrintThread{} << "Hello world!" << std::endl;
  */
class PrintThread: public std::ostringstream
{
public:
    PrintThread() = default;

    ~PrintThread()
    {
        std::lock_guard<std::mutex> guard(_mutexPrint);
        std::cout << this->str();
    }

private:
    static std::mutex _mutexPrint;
};

std::mutex PrintThread::_mutexPrint{};

#define synccout PrintThread{}