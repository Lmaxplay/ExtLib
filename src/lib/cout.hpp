#include <iosfwd>
#include <string.h>
#include "ansi.hpp"

#ifndef COUT_DECPRECATED_BYPASS
#error Library deprecated, use COUT_DEPRECATED_BYPASS to bypass this error
#endif
namespace ecout {
    struct _coutbase {
    public:
    template<class T>
    std::ostream& operator <<(const T &v) {
        return std::cout << this->value << v;
    }

    _coutbase (char* input) {
        this->value = input;
    }
    
    _coutbase (const char* input) {
        this->value = input;
    }

    private:
        const char* value;
    };

    _coutbase coutred = _coutbase(ansi::fg_red);
}