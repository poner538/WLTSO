/*
* FILNAMN:          fail.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Failklass
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

