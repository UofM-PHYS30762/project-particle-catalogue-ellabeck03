#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"

using std::string;

// default constructor
FourMomentum::FourMomentum() : energy(0.0), momentum(3, 0.0) {}

// parameterized constructor
FourMomentum::FourMomentum(double energy_in, const std::vector<double>& momentum_in)
{
    set_energy(energy_in);
    set_momentum(momentum_in);
}

// setters
void FourMomentum::set_energy(double energy_in) 
{
    validate_energy(energy_in);
    energy = energy_in;
}

void FourMomentum::set_momentum(const std::vector<double>& momentum_in) 
{momentum = momentum_in;}

// assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& other) 
{
    if (this != &other) {
        energy = other.energy;
        momentum = other.momentum;
    }
    return *this;
}

// move operator
FourMomentum& FourMomentum::operator=(FourMomentum&& other) 
{
    if (this != &other) {
        std::swap(energy, other.energy);
        std::swap(momentum, other.momentum);
    }
    return *this;
}

// copy constructor
FourMomentum::FourMomentum(const FourMomentum& other) : energy(other.energy), momentum(other.momentum) 
{}

// move constructor
FourMomentum::FourMomentum(FourMomentum&& other) : energy(std::move(other.energy)), momentum(std::move(other.momentum)) 
{}

// getter functions
double FourMomentum::get_energy() const {return energy;}

std::vector<double> FourMomentum::get_momentum() const {return momentum;}

// Other member functions
void FourMomentum::validate_energy(double energy_in) 
{
    if (energy_in < 0) {
        throw std::invalid_argument("Energy cannot be negative. Please input a valid energy.");
    }
}


//operator overloads
FourMomentum FourMomentum::operator-(const FourMomentum& other) const 
{
    double result_energy = this->energy - other.energy;
    std::vector<double> result_momentum;

    if (this->momentum.size() != other.momentum.size()) {
        throw std::length_error("Momentum vectors must have the same length.");
    }

    for (size_t i = 0; i < this->momentum.size(); ++i) {
        result_momentum.push_back(this->momentum[i] - other.momentum[i]);
    }

    return FourMomentum(result_energy, result_momentum);
}

FourMomentum FourMomentum::operator+(const FourMomentum& other) const 
{
    double result_energy = this->energy + other.energy;
    std::vector<double> result_momentum;

    if (this->momentum.size() != other.momentum.size()) {
        throw std::length_error("Momentum vectors must have the same length.");
    }

    for (size_t i = 0; i < this->momentum.size(); ++i) {
        result_momentum.push_back(this->momentum[i] + other.momentum[i]);
    }
    
    return FourMomentum(result_energy, result_momentum);
}

double FourMomentum::invariant_mass() const {
    double sum_p_squared = 0.0;
    for (auto& component : this->momentum) {sum_p_squared += std::pow(component, 2);}

    double mass_squared = std::pow(this->energy, 2) - sum_p_squared;

    // check for physical validity
    if (mass_squared < -0.001) {
        throw std::runtime_error("Invariant mass cannot be negative");
    }

    if (mass_squared < 0 && mass_squared > -0.001) {mass_squared = 0;}//allowing for small tolerance due to number storage if the true invariant mass is zero

    return std::sqrt(mass_squared);
}
