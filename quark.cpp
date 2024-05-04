#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "quark.h"

using std::string;

//default constructor
Quark::Quark() : Particle(), flavour("up"), colour("red") {}

//parameterised constructor
Quark::Quark(double mass_in, const FourMomentum& four_momentum_in, std::string flavour_in, std::string colour_in)
    : Particle(mass_in, four_momentum_in, 0, 0.5), flavour(flavour_in), colour(colour_in)
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
        }

        else if((flavour_in == "antidown") || (flavour_in == "antistrange") || (flavour_in == "antibottom"))
        {
            charge = 1.0 / 3.0;
        }
    }

//getters
double Quark::get_baryon_number() const {return baryon_number;}
std::string Quark::get_flavour() const {return flavour;}
std::string Quark::get_colour() const {return colour;}
std::string Quark::get_flavor() const { return "quark"; }

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