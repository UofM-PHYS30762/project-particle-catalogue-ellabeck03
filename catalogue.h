#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <unordered_map>
/*
using an unordered map as an STL container
stores data as pairs: (type, pointer)
allows for easy retrieval of particles by type
*/

#include <vector>
#include <memory>
#include <string>
#include "particle.h"

class ParticleCatalogue 
{
private:
    std::unordered_map<std::string, std::vector<std::shared_ptr<Particle>>> particle_catalogue;

public:

    //function to add a particle to the container
    void add_particle(const std::shared_ptr<Particle>& particle);

    //getters
    size_t get_particle_number() const;
    std::unordered_map<std::string, size_t> get_particle_number_by_type() const;
    std::vector<std::shared_ptr<Particle>> get_particles_of_type(const std::string& type) const;

    //other member functions
    FourMomentum sum_momenta() const;
    void print_particles() const;
};

#endif