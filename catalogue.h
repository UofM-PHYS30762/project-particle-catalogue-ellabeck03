#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include "particle.h" // Ensure this includes the base class Particle and any derived classes.

class ParticleCatalogue {
private:
    std::unordered_map<std::string, std::vector<std::shared_ptr<Particle>>> particle_catalogue;

public:
    void add_particle(const std::shared_ptr<Particle>& particle);
    size_t get_particle_number() const;
    std::unordered_map<std::string, size_t> get_particle_number_by_type() const;
    FourMomentum sum_momenta() const;
    std::vector<std::shared_ptr<Particle>> get_particles_of_type(const std::string& type) const;
    void print_particles() const;
};

#endif