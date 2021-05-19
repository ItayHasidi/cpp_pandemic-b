#include <ostream>
#include <iterator>
#include <map>
#include <string>
#include <array>

#include "City.hpp"
#include "Player.hpp"
#include "City_Class.hpp"

using namespace std;

#ifndef BOARD_H
#define BOARD_H

#include "City.hpp"
#include "Player.hpp"
#include "City_Class.hpp"

namespace pandemic{
    const int ColorNum = 4;
    
    class Board{
        public:

            std::map<pandemic::City, City_Class> cities;// = City_Class::init();
            // City_Class cur_city;
            std::array<bool, ColorNum> cure_level{};
            //  = (
            //     {pandemic::Color::Black , false},
            //     {pandemic::Color::Blue , false},
            //     {pandemic::Color::Red , false},
            //     {pandemic::Color::Yellow , false}
            // );
            
            // cure_level.insert({pandemic::Color::Black , false});
            // cure_level.insert({pandemic::Color::Blue , false});
            // cure_level.insert({pandemic::Color::Red , false});
            // cure_level.insert({pandemic::Color::Yellow , false});

            // pandemic::Player pl;

            Board();

            int& operator[](City c);

            friend std::ostream& operator<<(std::ostream& out, const Board& b);

            bool is_clean();

            void remove_cures();
            
            void remove_stations();
    };
}

#endif
