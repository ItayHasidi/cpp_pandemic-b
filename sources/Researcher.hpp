#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class Researcher : public Player{
        public:
            // Board b;
            // City c;
            Researcher(Board _b, City _c) : Player(_b, _c){}
            // static std::string role();
            const std::string role(){
                return "Researcher";
            }
    };
}