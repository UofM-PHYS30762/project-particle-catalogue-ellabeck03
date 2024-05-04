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
    : Particle(mass_in, four_momentum_in, 0, 1), colours(colours_in) {}

//getters
std::vector<std::string> Gluon::get_colours() const {return colours;}

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