// #ifdef City.hpp
// #endif

// #ifdef Board.hpp
// #endif

// #ifdef Color.hpp
// #endif


#ifndef PLAYER_H
#define PLAYER_H

#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic{

    const int default_cards_number = 5;

    class Player{
        // protected:
        //     pandemic::Board& board;
        //     pandemic::City city;
        public:
            // City_Class cur_city;
            
            pandemic::Board& board;
            pandemic::City city;

            map<pandemic::City, bool> takenCards;
            std::string player_role;
            int num_of_cards = default_cards_number;
            
            Player(Board& b, City c): board(b), city(c){}

            Player drive(pandemic::City c);
            Player fly_direct(pandemic::City c);
            Player fly_charter(pandemic::City c);
            Player fly_shuttle(pandemic::City c);
            Player build();
            Player discover_cure(pandemic::Color col);
            Player treat(pandemic::City c);

            void remove_a_card(pandemic::City c);
            pandemic::Player treat_helper(pandemic::City c);

            virtual const std::string role(){
                return "Player";
            }
            Player take_card(pandemic::City c);

            void remove_cards();
    };
}

#endif