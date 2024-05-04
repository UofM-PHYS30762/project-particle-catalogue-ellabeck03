#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "gluon.h"

using std::string;

//default constructor
Gluon::Gluon() : Particle(), colours({"red", "antired"}) {}

//parameterised constructor
Gluon::Gluon(double mass_in, const FourMomentum& four_momentum_in, std::vector<std::string> colours_in)
    : Particle(mass_in, four_momentum_in, 0, 1)
    {
        set_colours(colours_in);
    }

//getters
std::vector<std::string> Gluon::get_colours() const {return colours;}
std::string Gluon::get_type() const { return "gluon"; }

//setters
void Gluon::set_colours(std::vector<std::string> colours_in)
{
    validate_colours(colours_in);
    colours = colours_in;
}

//other member functions
void Gluon::antiparticle() 
{
    Particle::antiparticle();
    charge = 0;

    for(int i = 0; i < 2; ++i)
    {
        if (colours[i].length() >= 4 && colours[i].substr(0, 4) == "anti") {colours[i].erase(0, 4);}

        else {colours[i] = "anti" + colours[i];}
    }
}

void Gluon::print_data()
{
    std::cout<<"Particle Type: Gluon"<<std::endl;
    std::cout<<"Colours: ";
    for(int i = 0; i < 2; ++i)
    {
        std::cout<<colours[i]<<" ";
    }
    std::cout<<std::endl;
    Particle::print_data(); // Call base class print method
    std::cout << "--------------" << std::endl;
}

void Gluon::validate_colours(std::vector<std::string> colours_in)
{
    int colour_counter{0};
    int anticolour_counter{0};

    if(!(colours_in.size() == 2))
    {
        throw std::invalid_argument("Error: incorrect quantity of colours set");
    }

    for (const auto& colour : colours_in)
    {
        if(colour.substr(0, 4) == "anti")
        {
            anticolour_counter += 1;
        }

        else
        {
            colour_counter += 1;
        }
    }

    if(!(colour_counter == 1) || !(anticolour_counter == 1))
    {
        throw std::invalid_argument("Error: wrong colours set");
    }
}