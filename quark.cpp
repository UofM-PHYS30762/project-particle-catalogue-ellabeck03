#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "quark.h"

using std::string;

//default constructor
Quark::Quark() : Particle(), flavour("up"), colour("red") {}

//parameterised constructor
Quark::Quark(double mass_in, FourMomentum& four_momentum_in, std::string flavour_in, std::string colour_in)
    : Particle(mass_in, determineRestMass(flavour_in), four_momentum_in, 0, 0.5), flavour(flavour_in)
    {
        if((flavour_in == "up") || (flavour_in == "charm") || (flavour_in == "top"))
        {
            charge = 2.0 / 3.0;
        }

        else if((flavour_in == "down") || (flavour_in == "strange") || (flavour_in == "bottom"))
        {
            charge = -1.0 / 3.0;
        }

        else if((flavour_in == "antiup") || (flavour_in == "anticharm") || (flavour_in == "antitop"))
        {
            charge = -2.0 / 3.0;
            antiparticle_status = true;
        }

        else if((flavour_in == "antidown") || (flavour_in == "antistrange") || (flavour_in == "antibottom"))
        {
            charge = 1.0 / 3.0;
            antiparticle_status = true;
        }

        if((flavour_in == "up") || (flavour_in == "antiup")) {rest_mass = 2.2;}
        if((flavour_in == "down") || (flavour_in == "antidown")) {rest_mass = 4.8;}
        if((flavour_in == "charm") || (flavour_in == "anticharm")) {rest_mass = 1275;}
        if((flavour_in == "strange") || (flavour_in == "antistrange")) {rest_mass = 95;}
        if((flavour_in == "top") || (flavour_in == "antitop")) {rest_mass = 173070;}
        if((flavour_in == "bottom") || (flavour_in == "antibottom")) {rest_mass = 4180;}

        set_colour(colour_in);
    }


double Quark::determineRestMass(const std::string& flavour_in) {
    if((flavour_in == "up") || (flavour_in == "antiup")) {return 2.2;}
    if((flavour_in == "down") || (flavour_in == "antidown")) {return 4.8;}
    if((flavour_in == "charm") || (flavour_in == "anticharm")) {return 1275;}
    if((flavour_in == "strange") || (flavour_in == "antistrange")) {return 95;}
    if((flavour_in == "top") || (flavour_in == "antitop")) {return 173070;}
    if((flavour_in == "bottom") || (flavour_in == "antibottom")) {return 4180;}
    return 0; // default case
}

//getters
double Quark::get_baryon_number() const {return baryon_number;}
std::string Quark::get_flavour() const {return flavour;}
std::string Quark::get_colour() const {return colour;}
std::string Quark::get_type() const { return "quark"; }

//setters
void Quark::set_colour(std::string colour_in)
{
    validate_colour(colour_in);
    colour = colour_in;
}

//other member functions

void Quark::antiparticle() 
{
    Particle::antiparticle(); 
    baryon_number = -1 * baryon_number; // Flip the lepton number

    flavour = "anti" + flavour;
    colour = "anti" + colour;
}

void Quark::print_data()
{
    std::cout<<"Particle Type: "<<flavour<<" quark"<<std::endl;
    std::cout<<"Colour: "<<colour<<std::endl;
    std::cout << "Baryon Number: " << baryon_number << std::endl;
    Particle::print_data(); // Call base class print method
    std::cout << "--------------" << std::endl;
}

void Quark::validate_colour(std::string colour_in)
{
    if((antiparticle_status == false) && (colour_in.length() >= 4) && (colour_in.substr(0, 4) == "anti"))
    {
        throw std::invalid_argument("Error: wrong colour set");
    }

    if((antiparticle_status == true)  && !(colour_in.substr(0, 4) == "anti"))
    {
        throw std::invalid_argument("Error: wrong colour set");
    }
}