#include "lepton.h"
#include <iostream>

// Default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {} // Assuming default lepton number as +1

// Parameterized constructor
Lepton::Lepton(double mass_in, const FourMomentum& four_momentum_in, int lepton_number_in)
    : Particle(mass_in, four_momentum_in), lepton_number(lepton_number_in) {}

// Getter
int Lepton::get_lepton_number() const {return lepton_number;}

// Overriding the antiparticle method
void Lepton::antiparticle() 
{
    Particle::antiparticle(); // Call base class method to flip charge and set antiparticle status
    lepton_number = -1 * lepton_number; // Flip the lepton number
}

// Overriding the print_data method
void Lepton::print_data()
{
    Particle::print_data(); // Call base class print method
    std::cout << "Lepton Number: " << lepton_number << std::endl;
    std::cout << "--------------" << std::endl;
}