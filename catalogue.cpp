#include "catalogue.h"
#include "particle.h" 
#include <iostream>

void ParticleCatalogue::add_particle(const std::shared_ptr<Particle>& particle) {
    particle_catalogue[particle->get_type()].push_back(particle);
}

size_t ParticleCatalogue::get_particle_number() const {
    size_t total = 0;
    for (const auto& pair : particle_catalogue) {
        total += pair.second.size();
    }
    return total;
}

std::unordered_map<std::string, size_t> ParticleCatalogue::get_particle_number_by_type() const {
    std::unordered_map<std::string, size_t> count;
    for (const auto& pair : particle_catalogue) {
        count[pair.first] = pair.second.size();
    }
    return count;
}

FourMomentum ParticleCatalogue::sum_momenta() const {
    FourMomentum total_momentum;
    for (const auto& pair : particle_catalogue) {
        for (const auto& particle : pair.second) {
            total_momentum = total_momentum + particle->get_four_momentum();
        }
    }
    return total_momentum;
}

std::vector<std::shared_ptr<Particle>> ParticleCatalogue::get_particles_of_type(const std::string& type) const {
    if (particle_catalogue.find(type) != particle_catalogue.end()) {
        return particle_catalogue.at(type);
    }
    return {}; // Return empty vector if no particles of that type are found.
}

void ParticleCatalogue::print_particles() const {
    for (const auto& pair : particle_catalogue) {
        for (const auto& particle : pair.second) {
            particle->print_data();
        }
    }
}