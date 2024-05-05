#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"

using std::string;

//default constructor
Particle::Particle() : charge(-1), mass(0.0), spin(0.0), antiparticle_status(false) {}

//parameterised constructor
Particle::Particle(double mass_in, double rest_mass_in, FourMomentum& four_momentum_in, double charge_in, double spin_in)
    : rest_mass(rest_mass_in), charge(charge_in), spin(spin_in) {
    set_mass(mass_in);
    set_four_momentum(four_momentum_in);
}

//getters
double Particle::get_charge() const {return charge;}
double Particle::get_spin() const {return spin;}
double Particle::get_mass() {return mass;}
const FourMomentum& Particle::get_four_momentum() const {return four_momentum;}
bool Particle::get_antiparticle_status() const {return antiparticle_status;}
std::string Particle::get_type() const { return "none"; }

//setters
void Particle::set_mass(double mass_in) {mass = mass_in;}
void Particle::set_four_momentum(FourMomentum& four_momentum_in) 
{
    if (!check_mass_consistency(four_momentum_in)) {adjust_four_momentum(four_momentum_in);}
    else {four_momentum = four_momentum_in;}
}

//other member functions
void Particle::antiparticle()
{
  charge = charge * -1;
  antiparticle_status = true;
}

bool Particle::check_mass_consistency(FourMomentum& four_momentum_in) const {
    double calculated_mass = four_momentum_in.invariant_mass();
    if (std::abs(calculated_mass - rest_mass) > 1e-1) {  // assuming some tolerance
        std::cerr << "Warning: The invariant mass of the four-vector (" << calculated_mass
                  << ") does not match the rest mass of the particle (" << rest_mass << ")." << std::endl;
        return false;
    }
    return true;
}

void Particle::adjust_four_momentum(FourMomentum& four_momentum_in)
{
    std::cout<<rest_mass<<std::endl;
    if (four_momentum_in.get_energy() < rest_mass) {four_momentum_in.set_energy(rest_mass); std::cout<<"Energy set to "<<four_momentum_in.get_energy()<<std::endl;}

    double p_magnitude = sqrt(fabs(std::pow(four_momentum_in.get_energy(), 2) - std::pow(rest_mass, 2)));
    
    double equal_component = p_magnitude / sqrt(3.0);

    std::vector<double> p_direction = {equal_component, equal_component, equal_component};
    
    double new_energy = sqrt(std::pow(rest_mass, 2) + std::pow(p_magnitude, 2));

    // Update the four_momentum object
    four_momentum_in = FourMomentum(new_energy, p_direction);
    set_four_momentum(four_momentum_in);

    // Output the adjusted four-momentum
    std::cout << "Adjusted Four-Momentum: E = " << new_energy << ", p = (";
    for (size_t i = 0; i < p_direction.size(); ++i) {
        std::cout << p_direction[i];
        if (i != p_direction.size() - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}

void Particle::print_data()
{
  std::cout<<"Invariant mass: "<<four_momentum.invariant_mass()<<std::endl;
  std::cout<<"Charge: "<<charge<<"e"<<std::endl;
  std::cout<<"Spin: "<<spin<<std::endl;
  std::cout<<"Energy: "<<four_momentum.get_energy()<<" MeV"<<std::endl;
  std::cout<<"p_x: "<<four_momentum.get_momentum()[0]<<std::endl;
  std::cout<<"p_y: "<<four_momentum.get_momentum()[1]<<std::endl;
  std::cout<<"p_z: "<<four_momentum.get_momentum()[2]<<std::endl;
}