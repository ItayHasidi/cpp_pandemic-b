#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class Medic : public Player{
        public:
            // Board b;
            // City c;
            Medic(Board _b, City _c) : Player(_b, _c){}
            // static std::string role();
            const std::string role(){
                return "Medic";
            }


    };

}