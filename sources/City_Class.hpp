
using namespace std;

#ifndef CITY_CLASS_H
#define CITY_CLASS_H

#include "City.hpp"
#include "Color.hpp"

class City_Class{
        public:
                pandemic::City city_name;
                pandemic::Color city_color;
                int sickness = 0;
                bool isCardTaken = false;
                bool isStation = false;
                std::map<pandemic::City, pandemic::City> nei_city;
                
                static std::vector<std::string> splitWords(const std::string& str);
                static pandemic::City string_to_city(const string& type);
                static pandemic::Color string_to_color(const string& type);

                City_Class();
                City_Class(const City_Class& c);
                static map<pandemic::City, City_Class> init();
                void set(City_Class c1, const City_Class& c2);
                City_Class& operator=(const City_Class& c);
};

#endif