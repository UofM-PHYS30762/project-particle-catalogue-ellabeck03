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
    : Particle(mass_in, four_momentum_in), flavour(flavour_in), colour(colour_in) {}

//getters
double Quark::get_baryon_number() const {return baryon_number;}
std::string Quark::get_flavour() const {return flavour;}
std::string Quark::get_colour() const {return colour;}

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