#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "lepton.h"
#include "particle.h"
#include "neutrino.h"

using std::string;

//default constructor
Neutrino::Neutrino() : Lepton(), has_interacted(false), flavour("electron") {}

//parameterised constructor
Neutrino::Neutrino(double mass_in, const FourMomentum& four_momentum_in, bool has_interacted_in, std::string flavour_in) : Lepton(mass_in, four_momentum_in, 1), has_interacted(has_interacted_in)
{
    set_flavour(flavour_in);
    charge = 0;
}

//getters
bool Neutrino::get_interaction_status() const {return has_interacted;}
std::string Neutrino::get_flavour() const {return flavour;}
int Neutrino::get_charge() const {return 0;}

//setters
void Neutrino::set_interaction_status(bool has_interacted_in) {has_interacted = has_interacted_in;}
void Neutrino::set_flavour(std::string flavour_in)
{
    validate_flavour(flavour_in);
    flavour = flavour_in;
}

//validation
void Neutrino::validate_flavour(std::string flavour_in)
{
    if (!(flavour_in == "electron" || flavour_in == "muon" || flavour_in =="tau"))
    {
        throw std::invalid_argument("Error: unphysical neutrino flavour");
    }
}

//other member functions
void Neutrino::print_data()
{
    if (antiparticle_status == true)
    {
        std::cout<<"Particle type: Antineutrino"<<std::endl;
    }

    else if (antiparticle_status == false)
    {
        std::cout<<"Particle type: Neutrino"<<std::endl;
    }

    std::cout<<"Flavour: "<<flavour<<std::endl;
    std::cout << "Charge: " << charge << "e" << std::endl;
    Lepton::print_data();
}