#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "lepton.h"
#include "particle.h"
#include "tau.h"
#include "neutrino.h"
#include "quark.h"

using std::string;

//default constructor
Tau::Tau() : Lepton() {}

//parameterised constructor
Tau::Tau(double mass_in, const FourMomentum& four_momentum_in) : Lepton(mass_in, four_momentum_in, -1, 1) {}

//getters
std::vector<std::shared_ptr<Particle>> Tau::get_decay_particles() {return decay_particles;}


//function to add a decay lepton
void Tau::add_decay_particle(std::shared_ptr<Particle> particle_in)
{
     decay_particles.push_back(particle_in);
     if (decay_particles.size() == 3) {
            validate_decay();
        }
}

void Tau::validate_decay()
{
    double charge_sum = 0;
    std::vector<std::shared_ptr<Particle>> leptons, neutrinos, quarks;
    
    for (const auto& particle : decay_particles) {
        charge_sum += particle->get_charge();
        std::string flavor = particle->get_flavor();

        if (dynamic_cast<Neutrino*>(particle.get())) {
            neutrinos.push_back(particle);
        } else if (dynamic_cast<Lepton*>(particle.get()) && flavor != "tau") {
            leptons.push_back(particle);
        } else if (dynamic_cast<Quark*>(particle.get())) {
            quarks.push_back(particle);
        } else {
            throw std::runtime_error("Invalid particle type in Tau decay");
        }
    }

    // Charge consistency check
    if (charge_sum != charge) {
        throw std::runtime_error("Charge inconsistency detected in Tau decay");
    }

    // Check for valid decay patterns
    if (!(leptons.size() == 1 && neutrinos.size() == 2 && quarks.empty()) &&  // Leptonic decay
        !(leptons.empty() && neutrinos.size() == 1 && quarks.size() == 2)) {  // Hadronic decay
        throw std::runtime_error("Invalid decay combination for Tau");
    }

    // // Further detailed checks can be added here, such as flavor matching for leptonic decays
    // if (!leptons.empty() && !neutrinos.empty()) {
    //     // Ensure that the lepton and antineutrino flavors match in leptonic decay
    //     if (leptons[0]->get_flavor() != neutrinos[0]->get_flavor()) {
    //         throw std::runtime_error("Flavor mismatch in leptonic decay products");
    //     }
    // }
    
    std::cout << "Decay check completed successfully.\n";
}

//other member functions
void Tau::print_data()
{
    if (antiparticle_status == true)
    {
        std::cout<<"Particle type: Antitau"<<std::endl;
    }

    else if (antiparticle_status == false)
    {
        std::cout<<"Particle type: Tau"<<std::endl;
    }

    Lepton::print_data();
}