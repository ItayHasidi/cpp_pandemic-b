#include "Player.hpp"
#include "City.hpp"

#include "Board.hpp"
#include "Color.hpp"
using namespace std;
using namespace pandemic;

// #ifdef CITY_H
#include "City_Class.hpp"
// #endif

// pandemic::Player::Player(Board& b, City c){
//     this->board = b;
// }

void Player::remove_a_card(pandemic::City c){
    if(board.cities[city].isCardTaken /*&& this->curent_cards.find(c) != this->curent_cards.end()*/){
        board.cities[city].isCardTaken = false;
        // this->curent_cards.erase(this->cur_city.city_name);
    }
    else{
        throw std::invalid_argument("the cities are not adjacent");
    }

}

pandemic::Player pandemic::Player::drive(pandemic::City c){
    if(board.cities[city].nei_city.find(c) != board.cities[city].nei_city.end()){
        board.cities[city] = board.cities[c];
        // for(auto itr : cities[c].nei_city){
        //     cout << itr.second << " , ";
        // }
        // cout << endl << "cities" << endl ;
    }
    else{
        throw std::invalid_argument("the player cannot travel to the chosen city.");
    }
    return *this;
}
pandemic::Player pandemic::Player::fly_direct(pandemic::City c){
    if(role() == "Dispatcher"){
        board.cities[city] = board.cities[c];

    }
    else if(board.cities[c].isCardTaken){
        remove_a_card(board.cities[city].city_name);
        board.cities[city] = board.cities[c];

        // for(auto itr : cities[c].nei_city){
        //     cout << itr.second << " , ";
        // }
        // cout << endl << "cities" << endl ;
    }
    else{
        throw std::invalid_argument("the player cannot travel to the chosen city.");
    }
    
    return *this;
}
pandemic::Player pandemic::Player::fly_charter(pandemic::City c){
    if(board.cities[city].isCardTaken){
        remove_a_card(board.cities[city].city_name);
        board.cities[city] = board.cities[c];

    }
    else{
        throw std::invalid_argument("the player cannot travel to the chosen city.");
    }
    return *this;

}
pandemic::Player pandemic::Player::fly_shuttle(pandemic::City c){
    if(board.cities[city].isStation && board.cities[c].isStation){
        city = board.cities[c].city_name;
    }
    else{
        throw std::invalid_argument("unable to fly shuttle.");
    }
    return *this;
}

// std::string pandemic::Player::role() const{
//     return this->player_role;
// }

pandemic::Player pandemic::Player::build(){
    if(role() == "OperationsExpert"){
        // cur_city.isStation = true; 
        board.cities[city].isStation = true;
        // cout << "#$#$ built #$#$ "<< cur_city.isStation<<endl;
    }
    else if(!board.cities[city].isStation && board.cities[city].isCardTaken){
        board.cities[city].isStation = true; 
        remove_a_card(board.cities[city].city_name);
    }
    else if(!board.cities[city].isCardTaken){
        throw std::invalid_argument("the player does not have cards to build station.");
    }
    return *this;
}
pandemic::Player pandemic::Player::discover_cure(pandemic::Color col){
    // City_Class cur_city = cur_city;
    int numOfCards = this->num_of_cards;
    // for (auto itr: *cure_level){
    //     cout<<"colors"<< itr.second<<endl;
    // }
    if(role() == "Researcher"){
        // throw std::invalid_argument("bla");
        board.cure_level.at(col) = true;
    }
    else if(!board.cure_level.at(col) 
    && board.cities[city].isStation){
        int count = 0;
        std::vector<City> toBeDeleted;
        for(const auto& itr : board.cities){
            if(itr.second.city_color == col 
            && itr.second.isCardTaken){
                toBeDeleted.push_back(itr.first);
                count++;
            }
            if(count == numOfCards){
                break;
            }
        }
        if(count == numOfCards){
            for(unsigned int i = 0; i < numOfCards; i++){
                remove_a_card(toBeDeleted[i]);
            }
            board.cure_level.at(col) = true;
        }
    }
    return *this;
}

pandemic::Player Player::treat_helper(pandemic::City c){
    if(board[c] == 0){
        throw std::invalid_argument("the sickness has already been cured!");
    }
    if((board.cure_level.at(board.cities[c].city_color)) || (role() == "Medic")){
        board[c] = 0;
    }
    else{
        if(board[c] > 0){
            board[c]--;
        }
    }
    return *this;
}
pandemic::Player pandemic::Player::treat(pandemic::City c){
    // City ci = City::Algiers;
    // cout << role()<<endl;
    if(role() == "Virologist" && board.cities[c].isCardTaken) {
        // ci = c;
        remove_a_card(c);
    }
    else if(role() == "Virologist" && !board.cities[c].isCardTaken){
        throw std::invalid_argument("Virologist has no card!");
    }
    else if(role() == "FieldDoctor" && board.cities[city].nei_city.find(c) == board.cities[city].nei_city.end()){
        throw std::invalid_argument("FieldDoctor, wrong city to treat!");
        // ci = c;
    }
    else if(city != c){
        // cout<<"\t\t" <<city << " $$$ "<< c <<endl;
        throw std::invalid_argument("wrong city to treat!");
        // ci = board.cities[city].city_name;
    }
    return treat_helper(c);
}

pandemic::Player pandemic::Player::take_card(pandemic::City c){
    board.cities[c].isCardTaken = true;
    if(this->takenCards.find(c) != this->takenCards.end()){
        this->takenCards.insert({c, true});
        // this->curent_cards.insert({c, cities[c]});
    }
    return *this;
}

void pandemic::Player::remove_cards(){
    for(auto c : this->takenCards){
        board.cities.at(c.first).isCardTaken = false;
        // this->takenCards.erase(c.first);
        // this->curent_cards.clear();
        // c.second = false;
    }
    this->takenCards.clear();
}