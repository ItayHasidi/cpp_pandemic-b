#include "City.hpp"
#include "City_Class.hpp"
#include "Color.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

map<pandemic::City, City_Class> cities;

City_Class::City_Class(const City_Class& c){
    this->city_color = c.city_color;
    this->city_name = c.city_name;
    this->isCardTaken = c.isCardTaken;
    this->isStation = c.isStation;
    this->nei_city = c.nei_city;
    this->sickness = c.sickness;
}


std::vector<std::string> City_Class::splitWords(const std::string& str){
    std::string word;
    std::vector<std::string> result;
    for (const char& x : str) 
    {
        if (x == ' ')
        {
            if(!word.empty()){
                result.push_back(word);
                word = "";
            }
        }
        else {
            word += x;
        }
    }
    if(!word.empty()){
        result.push_back(word);
    }
    return result;
}


pandemic::City City_Class::string_to_city(const string& type) {
    pandemic::City c = pandemic::City::Algiers;
    if(type == "Algiers") {c = pandemic::City::Algiers;}
    else if(type == "Atlanta") {c = pandemic::City::Atlanta;}
    else if(type == "Baghdad") {c = pandemic::City::Baghdad;}
    else if(type == "Bangkok") {c = pandemic::City::Bangkok;}
    else if(type == "Beijing") {c = pandemic::City::Beijing;}
    else if(type == "Bogota") {c = pandemic::City::Bogota;}
    else if(type == "BuenosAires") {c = pandemic::City::BuenosAires;}
    else if(type == "Cairo") {c = pandemic::City::Cairo;}
    else if(type == "Chennai") {c = pandemic::City::Chennai;}
    else if(type == "Chicago") {c = pandemic::City::Chicago;}
    else if(type == "Delhi") {c = pandemic::City::Delhi;}
    else if(type == "Essen") {c = pandemic::City::Essen;}
    else if(type == "HoChiMinhCity") {c = pandemic::City::HoChiMinhCity;}
    else if(type == "HongKong") {c = pandemic::City::HongKong;}
    else if(type == "Istanbul") {c = pandemic::City::Istanbul;}
    else if(type == "Jakarta") {c = pandemic::City::Jakarta;}
    else if(type == "Johannesburg") {c = pandemic::City::Johannesburg;}
    else if(type == "Karachi") {c = pandemic::City::Karachi;}
    else if(type == "Khartoum") {c = pandemic::City::Khartoum;}
    else if(type == "Kinshasa") {c = pandemic::City::Kinshasa;}
    else if(type == "Kolkata") {c = pandemic::City::Kolkata;}
    else if(type == "Lagos") {c = pandemic::City::Lagos;}
    else if(type == "Lima") {c = pandemic::City::Lima;}
    else if(type == "London") {c = pandemic::City::London;}
    else if(type == "LosAngeles") {c = pandemic::City::LosAngeles;}
    else if(type == "Madrid") {c = pandemic::City::Madrid;}
    else if(type == "Manila") {c = pandemic::City::Manila;}
    else if(type == "MexicoCity") {c = pandemic::City::MexicoCity;}
    else if(type == "Miami") {c = pandemic::City::Miami;}
    else if(type == "Milan") {c = pandemic::City::Milan;}
    else if(type == "Montreal") {c = pandemic::City::Montreal;}
    else if(type == "Moscow") {c = pandemic::City::Moscow;}
    else if(type == "Mumbai") {c = pandemic::City::Mumbai;}
    else if(type == "NewYork") {c = pandemic::City::NewYork;}
    else if(type == "Osaka") {c = pandemic::City::Osaka;}
    else if(type == "Paris") {c = pandemic::City::Paris;}
    else if(type == "Riyadh") {c = pandemic::City::Riyadh;}
    else if(type == "SanFrancisco") {c = pandemic::City::SanFrancisco;}
    else if(type == "Santiago") {c = pandemic::City::Santiago;}
    else if(type == "SaoPaulo") {c = pandemic::City::SaoPaulo;}
    else if(type == "Seoul") {c = pandemic::City::Seoul;}
    else if(type == "Shanghai") {c = pandemic::City::Shanghai;}
    else if(type == "StPetersburg") {c = pandemic::City::StPetersburg;}
    else if(type == "Sydney") {c = pandemic::City::Sydney;}
    else if(type == "Taipei") {c = pandemic::City::Taipei;}
    else if(type == "Tehran") {c = pandemic::City::Tehran;}
    else if(type == "Tokyo") {c = pandemic::City::Tokyo;}
    else if(type == "Washington") {c = pandemic::City::Washington;}

    else{
        throw std::invalid_argument("Invalid pandemic::City name");
    }

    return c;
}

pandemic::Color City_Class::string_to_color(const string& type) {
    pandemic::Color c = pandemic::Color::Black;
    if(type == "Yellow") {c =  pandemic::Color::Yellow;}
    else if(type == "Black") {c =  pandemic::Color::Black;}
    else if(type == "Blue") {c =  pandemic::Color::Blue;}
    else if(type == "Red") {c =  pandemic::Color::Red;}

    else{
        throw std::invalid_argument("Invalid Color name");
    }

    return c;
}

// map<pandemic::City, City_Class> City_Class::init(){
//     string line;
//     vector<string> words;
//     ifstream file("cities_map.txt");

//     while (getline (file, line)) {
//         words = City_Class::splitWords(line);
//         City_Class temp_city;
//         temp_city.city_name = City_Class::string_to_city(words[0]);
//         temp_city.city_color = City_Class::string_to_color(words[1]);
//         for(unsigned int i = 2; i < words.size(); i++){
//             temp_city.nei_city.insert({City_Class::string_to_city(words[i]), City_Class::string_to_city(words[i])});
//         }
//     }

//     file.close();
//     return cities;
// }

void set(City_Class c1, const City_Class& c2){
    c1.city_name = c2.city_name;
    c1.city_color = c2.city_color;
    c1.isCardTaken = c2.isCardTaken;
    c1.isStation = c2.isStation;
    c1.sickness = c2.sickness;
    c1.nei_city = c2.nei_city;
}


City_Class& City_Class::operator=(const City_Class& c){
    this->city_name = c.city_name;
    this->city_color = c.city_color;
    this->isCardTaken = c.isCardTaken;
    this->isStation = c.isStation;
    this->sickness = c.sickness;
    this->nei_city = c.nei_city;
    return *this;
}


City_Class::City_Class(){
//     // cities = init();
//     // string line;
//     // vector<string> words;
//     // ifstream file("cities_map.txt");

//     // while (getline (file, line)) {
//     //     words = splitWords(line);
//     //     // City_Class temp_city;
//     //     /*temp_city.*/this->city_name = string_to_city(words[0]);
//     //     /*temp_city.*/this->city_color = string_to_color(words[1]);
//     //     for(unsigned int i = 2; i < words.size(); i++){
//     //         /*temp_city.*/this->nei_city.insert({string_to_city(words[i]), string_to_city(words[i])});
//     //     }
//     // }
    this->sickness = -1;
    this->city_color = pandemic::Color::Black;
    this->city_name = pandemic::City::Algiers;
    this->isCardTaken = false;
    this->isStation = false;

//     // file.close();
}