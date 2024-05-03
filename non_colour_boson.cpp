#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"
#include "non_colour_boson.h"

using std::string;

//default constructor
NonColourBoson::NonColourBoson() : Particle(), type("Z") {}

//parameterised constructor
NonColourBoson::NonColourBoson(double mass_in, const FourMomentum& four_momentum_in, std::string type_in)
    : Particle(mass_in, four_momentum_in), type(type_in) {}

//getters
std::string NonColourBoson::get_type() const {return type;}
std::vector<std::shared_ptr<Particle>> NonColourBoson::get_decay_particles() {return decay_particles;}

//function to add a decay lepton
void NonColourBoson::add_decay_particle(std::shared_ptr<Particle> decay_particle_in) {decay_particles.push_back(decay_particle_in);}

void NonColourBoson::antiparticle()
{
    Particle::antiparticle();
}

void NonColourBoson::print_data()
{
    std::cout << "Particle type: " << type << std::endl;
    Particle::print_data(); // Call base class print method
    std::cout << "--------------" << std::endl;
}


