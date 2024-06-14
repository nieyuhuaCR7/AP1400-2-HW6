#ifndef Q3_H
#define Q3_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>  
#include <iostream>

namespace q3 {
    struct Flight
    {
        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times;
        size_t price;

        Flight(std::string num, size_t dur, size_t conn, size_t conn_times, size_t pri) 
            : flight_number(num), duration(dur), connections(conn), connection_times(conn_times), price(pri) {}

        bool operator<(const Flight& other) const {
            size_t weight_this = duration + connection_times + 3 * price;
            size_t weight_other = other.duration + other.connection_times + 3 * other.price;
            return weight_this > weight_other; // Greater than for min-heap
        }
    };
}

#endif //Q3_H