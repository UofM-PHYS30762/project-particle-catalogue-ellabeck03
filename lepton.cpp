#include "lepton.h"
#include <iostream>

// default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {spin = 1/2;}

// parameterized constructor
Lepton::Lepton(double rest_mass_in, FourMomentum& four_momentum_in, double charge_in, int lepton_number_in)
    : Particle(rest_mass_in, four_momentum_in, charge_in, 0.5), lepton_number(lepton_number_in) {}

// getters
int Lepton::get_lepton_number() const {return lepton_number;}
std::string Lepton::get_type() const {return "lepton";}

// other member functions
void Lepton::antiparticle() 
{
    Particle::antiparticle();
    lepton_number = -1 * lepton_number;
}

void Lepton::print_data()
{
    std::cout << "Lepton Number: " << lepton_number << std::endl;
    Particle::print_data();
    std::cout << "--------------" << std::endl;
}