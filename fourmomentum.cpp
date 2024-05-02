#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"

using std::string;

// Default constructor
FourMomentum::FourMomentum() : energy(0.0), momentum(3, 0.0) {}

// Parameterized constructor
FourMomentum::FourMomentum(double energy_in, const std::vector<double>& momentum_in)
{
    set_energy(energy_in);
    set_momentum(momentum_in);
}

// Setters
void FourMomentum::set_energy(double energy_in) 
{
    validate_energy(energy_in);
    energy = energy_in;
}

void FourMomentum::set_momentum(const std::vector<double>& momentum_in) 
{
    momentum = momentum_in;
}

// Assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& other) 
{
    if (this != &other) {
        std::cout << "Assignment operator called" << std::endl;
        energy = other.energy;
        momentum = other.momentum;
    }
    return *this;
}

// Move operator
FourMomentum& FourMomentum::operator=(FourMomentum&& other) 
{
    if (this != &other) {
        std::cout << "Move operator called" << std::endl;
        std::swap(energy, other.energy);
        std::swap(momentum, other.momentum);
    }
    return *this;
}

// Copy constructor
FourMomentum::FourMomentum(const FourMomentum& other) : energy(other.energy), momentum(other.momentum) 
{
    std::cout << "Copy constructor called" << std::endl;
}

// Move constructor
FourMomentum::FourMomentum(FourMomentum&& other) : energy(std::move(other.energy)), momentum(std::move(other.momentum)) 
{
    std::cout << "Move constructor called" << std::endl;
}

// Destructor
FourMomentum::~FourMomentum() 
{
    std::cout << "Destroying four momentum information" << std::endl;
}

// Getter functions
double FourMomentum::get_energy() const 
{
    return energy;
}

std::vector<double> FourMomentum::get_momentum() const 
{
    return momentum;
}

// Other member functions
void FourMomentum::validate_energy(double energy_in) 
{
    if (energy_in < 0) {
        throw std::invalid_argument("Energy cannot be negative. Please input a valid energy.");
    }
}
