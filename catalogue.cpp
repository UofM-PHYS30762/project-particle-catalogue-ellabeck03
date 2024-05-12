#include "catalogue.h"
#include "particle.h" 
#include <iostream>

void ParticleCatalogue::add_particle(const std::shared_ptr<Particle>& particle) 
{
    //add particle to the map, sorted by type
    particle_catalogue[particle->get_type()].push_back(particle);
}

size_t ParticleCatalogue::get_particle_number() const 
{
    //function to get the total number of particles
    size_t total = 0;
    for (const auto& pair : particle_catalogue) 
    {
        total += pair.second.size();// pair.second refers to a vector of particle pointers for a specific particle type (e.g. electron, gluon)
    }
    return total;
}

std::unordered_map<std::string, size_t> ParticleCatalogue::get_particle_number_by_type() const 
{
    std::unordered_map<std::string, size_t> count;//creates a map which stores each type of particle present

    for (const auto& pair : particle_catalogue)
    {
        count[pair.first] = pair.second.size();//accesses vector of pointers to the particles of a specific type, and finds the size of the vector
    }

    return count;
}

FourMomentum ParticleCatalogue::sum_momenta() const 
{
    //find the total four-momentum of all particles in the map
    FourMomentum total_momentum;

    for (const auto& pair : particle_catalogue) 
    {
        for (const auto& particle : pair.second) 
        {
            //add momentum of each particle pointer
            total_momentum = total_momentum + particle->get_four_momentum();
        }
    }

    return total_momentum;
}

std::vector<std::shared_ptr<Particle>> ParticleCatalogue::get_particles_of_type(const std::string& type) const 
{
    //returns sub-catalogue of particles of a specific type
    if (particle_catalogue.find(type) != particle_catalogue.end()) 
    {
        return particle_catalogue.at(type);
    }
    return {}; // returns empty vector if no particles of that type are found.
}

void ParticleCatalogue::print_particles() const 
{
    //prints all data in the catalogue
    for (const auto& pair : particle_catalogue) 
    {
        for (const auto& particle : pair.second) 
        {
            particle->print_data();
        }
    }
}