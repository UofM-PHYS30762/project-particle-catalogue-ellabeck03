#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "lepton.h"
#include "particle.h"
#include "muon.h"

using std::string;

// default constructor
Muon::Muon() : Lepton(), is_isolated(false) {}

// parameterised constructor
Muon::Muon(FourMomentum& four_momentum_in, bool isolated_in) : Lepton(105.7, four_momentum_in, -1, 1), is_isolated(isolated_in) {}

// getters
bool Muon::get_isolation_status() const {return is_isolated;}
std::string Muon::get_type() const { return "muon"; }

// setters
void Muon::set_isolation_status(bool is_isolated_in) {is_isolated = is_isolated_in;}

// other member functions
void Muon::print_data()
{
    if (antiparticle_status == true)
    {
        std::cout<<"Particle type: Antimuon"<<std::endl;
    }

    else if (antiparticle_status == false)
    {
        std::cout<<"Particle type: Muon"<<std::endl;
    }
    
    Lepton::print_data();
}