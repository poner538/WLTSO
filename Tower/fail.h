/*
* FILNAMN:          Game.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include <stdexcept>

class exception: public std::runtime_error
    {
    public:
        explicit expression_error (const std::string& what_arg) noexcept
            :runtime_error{what_arg} {}
    };

