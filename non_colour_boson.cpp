#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"
#include "non_colour_boson.h"
#include "lepton.h"
#include "tau.h"
#include "neutrino.h"
#include "quark.h"
#include "electron.h"
#include "muon.h"

using std::string;

//default constructor
NonColourBoson::NonColourBoson() : Particle(), flavour("W-") {}

//parameterised constructor
NonColourBoson::NonColourBoson(double mass_in, const FourMomentum& four_momentum_in, std::string flavour_in)
    : Particle(mass_in, four_momentum_in, 0, 1), flavour(flavour_in)
    {
        if(flavour_in == "W+")
        {
            charge = 1.0;
            flavour = flavour_in;
        }

        else if(flavour_in == "W-")
        {
            charge = -1.0;
            flavour = flavour_in;
        }

        else if((flavour_in == "Higgs") || (flavour_in == "Z") || (flavour_in == "photon"))
        {
            charge = 0.0;
            spin = 0.0;
            flavour = flavour_in;
        }
    }

//getters
std::string NonColourBoson::get_flavour() const {return flavour;}
std::vector<std::shared_ptr<Particle>> NonColourBoson::get_decay_particles() {return decay_particles;}
std::string NonColourBoson::get_type() const { return "boson"; }

//function to add a decay lepton
void NonColourBoson::add_decay_particle(std::shared_ptr<Particle> decay_particle_in) 
{
    decay_particles.push_back(decay_particle_in);
    if (decay_particles.size() == 2) {validate_decay();}
}

//other member functions
void NonColourBoson::antiparticle()
{
    Particle::antiparticle();
    
    if(flavour == "W-")
    {
        flavour= "W+";
    }

    else if(flavour == "W+")
    {
        flavour = "W-";
    }

    else if((flavour == "Higgs") || (flavour == "Z") || (flavour == "photon"))
    {
        throw std::invalid_argument("error: this particle has no antiparticle");
    }
}

void NonColourBoson::print_data()
{
    std::cout << "Particle type: " << flavour << " boson"<< std::endl;
    Particle::print_data(); // Call base class print method
    std::cout << "--------------" << std::endl;
}

void NonColourBoson::validate_decay() const
{
    double charge_sum = 0;
    std::vector<std::shared_ptr<Particle>> leptons, neutrinos, quarks, bosons;

    //checking no photons have decayed
    if (flavour == "photon") 
    {
        if (!(decay_particles.empty())) {throw std::runtime_error("Photons should not decay.");}
    }

    //checking charge consistency
    for (const auto& particle : decay_particles) 
    {
        charge_sum += particle->get_charge();
        std::string flavor = particle->get_type();

        if (dynamic_cast<Neutrino*>(particle.get())) {neutrinos.push_back(particle);} 
        else if (dynamic_cast<Lepton*>(particle.get())) {leptons.push_back(particle);}
        else if (dynamic_cast<Quark*>(particle.get())) {quarks.push_back(particle);} 
        else if (dynamic_cast<NonColourBoson*>(particle.get())) {bosons.push_back(particle);} 
        else {throw std::runtime_error("Invalid particle type in Tau decay");}
    }

    if (charge_sum != charge) {throw std::runtime_error("Charge inconsistency detected");}

    //checking valid W boson decays
    bool valid_w_decay1 = (leptons.size() == 1) && (neutrinos.size() == 1);
    bool valid_w_decay2 = (quarks.size() == 2);

    if (flavour == "W+" || flavour == "W-")
    {
        if(!valid_w_decay1 && !valid_w_decay2)
        {
            throw std::runtime_error("Invalid decay.");
        }

        if (valid_w_decay2) 
        {
            //checking the two quark flavours are different
            auto quark1 = std::dynamic_pointer_cast<Quark>(quarks[0]);
            auto quark2 = std::dynamic_pointer_cast<Quark>(quarks[1]);

            if (!quark1 || !quark2 || quark1->get_flavour() == quark2->get_flavour()) 
            {
                throw std::runtime_error("Invalid quark decay: quarks must have different flavours.");
            }
        
        } 
    }

    //checking valid Z boson decays
    bool valid_z_decay1 = (quarks.size() == 2);
    bool valid_z_decay2 = (leptons.size() == 2);

    if (flavour == "Z")
    {
        if(!valid_z_decay1 && !valid_z_decay2)
        {
            throw std::runtime_error("Invalid decay.");
        }
    }

    //checking valid Higgs boson decays
    bool valid_higgs_decay1 = (bosons.size() == 2);
    bool valid_higgs_decay2 = (quarks.size() == 2);

    if (flavour == "Higgs")
    {
        if(!valid_higgs_decay1 && !valid_higgs_decay2)
        {
            throw std::runtime_error("Invalid decay.");
        }

        std::shared_ptr<Particle> first = decay_particles[0];
        std::shared_ptr<Particle> second = decay_particles[1];

        if (valid_higgs_decay1)
        {
            auto boson1 = std::dynamic_pointer_cast<NonColourBoson>(bosons[0]);
            auto boson2 = std::dynamic_pointer_cast<Quark>(bosons[1]);

            if ((boson1->get_flavour() == boson2->get_flavour()) && (boson1->get_flavour() == "Higgs" || boson1->get_flavour() == "photon"))
            {
                std::cout<<"Decay validated"<<std::endl;
                return;
            }

            else if ((boson1->get_flavour() == "W+" && boson2->get_flavour() == "W-") || (boson1->get_flavour() == "W-" && boson2->get_flavour() == "W+"))
            {
              std::cout<<"Decay validated"<<std::endl;
              return;  
            }
            
            else {throw std::runtime_error("Invalid decay.");}
        }

        else if (valid_higgs_decay2)
        {
            auto quark1 = std::dynamic_pointer_cast<Quark>(quarks[0]);
            auto quark2 = std::dynamic_pointer_cast<Quark>(quarks[1]);

            if ((quark1->get_flavour() == "bottom" && quark2->get_flavour() == "antibottom") || (quark1->get_flavour() == "antibottom" && quark2->get_flavour() == "bottom"))
            {
              std::cout<<"Decay validated"<<std::endl;
              return;  
            }

            else {throw std::runtime_error("Invalid decay.");}
        }
    }

    std::cout<<"Decay validated"<<std::endl;

}
