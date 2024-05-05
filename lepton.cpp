#include "lepton.h"
#include <iostream>

// Default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {spin = 1/2;} // Assuming default lepton number as +1

// Parameterized constructor
Lepton::Lepton(double mass_in, double rest_mass_in, FourMomentum& four_momentum_in, double charge_in, int lepton_number_in)
    : Particle(mass_in, rest_mass_in, four_momentum_in, charge_in, 0.5), lepton_number(lepton_number_in) {}

// Getter
int Lepton::get_lepton_number() const {return lepton_number;}
std::string Lepton::get_type() const {return "lepton";}

// Overriding the antiparticle method
void Lepton::antiparticle() 
{
    Particle::antiparticle(); // Call base class method to flip charge and set antiparticle status
    lepton_number = -1 * lepton_number; // Flip the lepton number
}

// Overriding the print_data method
void Lepton::print_data()
{
    std::cout << "Lepton Number: " << lepton_number << std::endl;
    Particle::print_data(); // Call base class print method
    std::cout << "--------------" << std::endl;
}