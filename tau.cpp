#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "lepton.h"
#include "particle.h"
#include "tau.h"

using std::string;

//default constructor
Tau::Tau() : Lepton(), is_leptonic_decay(false) {}

//parameterised constructor
Tau::Tau(double mass_in, const FourMomentum& four_momentum_in, bool is_leptonic_in) : Lepton(mass_in, four_momentum_in, 1), is_leptonic_decay(is_leptonic_in) {}

//getters
bool Tau::get_decay_status() const {return is_leptonic_decay;}
std::vector<std::shared_ptr<Lepton>> Tau::get_decay_leptons() {return decay_leptons;}

//setters
void Tau::set_decay_status(bool is_leptonic_in) {is_leptonic_decay = is_leptonic_in;}

//function to add a decay lepton
void Tau::add_decay_lepton(std::shared_ptr<Lepton> lepton_in)
{
    if(is_leptonic_decay == false)
    {
        throw std::invalid_argument("Error: can't add leptons to a hadronic decay!");
    }
    else
    {
        decay_leptons.push_back(lepton_in);
    }
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

    std::cout<<"Charge: "<<charge<<"e"<<std::endl;
    Lepton::print_data();
}