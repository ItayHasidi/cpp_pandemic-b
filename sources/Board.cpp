#include "Board.hpp"
#include "City.hpp"
#include "City_Class.hpp"
#include "Color.hpp"
#include <map>
#include <vector>
#include <ostream>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;
using namespace pandemic;

Board::Board(){
    string line;
    ifstream file("cities_map.txt");
    while (getline (file, line)) {
        vector<string> words = City_Class::splitWords(line);
        int len = words.size();
        City_Class temp_city;
        temp_city.city_name = City_Class::string_to_city(words[0]);
        temp_city.city_color = City_Class::string_to_color(words[1]);
        this->cities.insert({City_Class::string_to_city(words[0]), temp_city});
        for(unsigned int i = 2; i < len; i++){
            this->cities[temp_city.city_name].nei_city.insert({City_Class::string_to_city(words[i]), City_Class::string_to_city(words[i])});
        }
    }
    file.close();

    // for(auto itr : cities){
    //     cout << itr.second.city_name << "\t";
    //     for(auto itr2 : itr.second.nei_city){
    //         cout << itr2.second << " , ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // this->cure_level.insert({pandemic::Color::Black , false});
    // this->cure_level.insert({pandemic::Color::Blue , false});
    // this->cure_level.insert({pandemic::Color::Red , false});
    // this->cure_level.insert({pandemic::Color::Yellow , false});

    // for(const auto& itr : pandemic::Color.){
    //     cout << "hi"<<endl;
    //     this->cure_level[itr.first] = false;
    // }
}

int& pandemic::Board::operator[](pandemic::City c){
    return this->cities[c].sickness;
}

ostream& /*pandemic::*/pandemic::operator<<(ostream& out, const Board& b){
    // out << b.cur_city.sickness;
    out << "• Sickness in each city:" << endl;
    for (auto it = b.cities.begin();it != b.cities.end(); ++it){
        out << "\t" << it->second.city_name << " =\t" << it->second.sickness << endl;
    }

    out << "• Cures discoverd for each sickness:" << endl;
    for (const auto* it = b.cure_level.begin();it != b.cure_level.end(); ++it){
        out << "\t" << it << " =\t"/* << it->second*/ << endl;
    }

    out << "• Research stations:" << endl;
    // for (auto it = sick_city.begin();it != sick_city.end(); ++it){
    //     out << "/t" << it->first << " =\t" << it->second << endl;
    // }
    
    return out;
}

bool pandemic::Board::is_clean(){
    for (auto it = this->cities.begin();it != this->cities.end(); ++it){
        if(it->second.sickness != 0 && it->second.sickness != -1){
            return false;
        }
    }
    return true;;
}

void pandemic::Board::remove_cures(){
    // for (auto it = this->cure_level.begin();it != this->cure_level.end(); ++it){
    for(unsigned int i = 0; i < ColorNum; i++){
        cure_level.at(i) = false;
    }
}

void pandemic::Board::remove_stations(){
    for (auto it = this->cities.begin();it != this->cities.end(); ++it){
        it->second.isStation = false;
    }
}
