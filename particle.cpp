#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"

using std::string;

//default constructor
Particle::Particle() : charge(-1), mass(0.0) , antiparticle_status(false) {}

//parameterised constructor
Particle::Particle(double mass_in, const FourMomentum& four_momentum_in) : charge(-1), four_momentum(four_momentum_in), antiparticle_status(false)
{
    set_mass(mass_in);
}

//getters
int Particle::get_charge() const {return charge;}
double Particle::get_mass() {return mass;}
const FourMomentum& Particle::get_four_momentum() const {return four_momentum;}
bool Particle::get_antiparticle_status() const {return antiparticle_status;}

//setters
void Particle::set_mass(double mass_in) {mass = mass_in;}
void Particle::set_four_momentum(FourMomentum& four_momentum_in) {four_momentum = four_momentum_in;}

//other member functions
void Particle::antiparticle()
{
  charge = charge * -1;
  antiparticle_status = true;
}

void Particle::print_data()
{
  std::cout<<"Energy: "<<four_momentum.get_energy()<<" MeV"<<std::endl;
  std::cout<<"p_x: "<<four_momentum.get_momentum()[0]<<std::endl;
  std::cout<<"p_y: "<<four_momentum.get_momentum()[1]<<std::endl;
  std::cout<<"p_z: "<<four_momentum.get_momentum()[2]<<std::endl;
  std::cout<<"--------------"<<std::endl;
}