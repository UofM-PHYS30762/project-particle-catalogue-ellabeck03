#include "electron.h"
#include <iostream>
#include <stdexcept>

// default constructor
Electron::Electron() : Lepton(), deposited_energies(4, 0.0) {}

// parameterized constructor
Electron::Electron(FourMomentum& four_momentum_in, const std::vector<double>& deposited_energies_in)
    : Lepton(0.511, four_momentum_in, -1, 1)
{
    set_deposited_energies(deposited_energies_in);
}

// getters
const std::vector<double>& Electron::get_deposited_energies() const {return deposited_energies;}
std::string Electron::get_type() const { return "electron"; }

// setters
void Electron::set_deposited_energies(const std::vector<double>& deposited_energies_in) 
{
    validate_deposited_energies(deposited_energies_in);
    deposited_energies = deposited_energies_in;
}

// other member functions
void Electron::validate_deposited_energies(const std::vector<double>& deposited_energies) 
{
    if (deposited_energies.size() != 4) {
        throw std::invalid_argument("Error: incorrect number of calorimeter layers.");
    }

    // check that the energy deposited is equal to the total energy
    double sum = 0.0;
    for (double energy : deposited_energies) {sum += energy;}

    if (std::abs(sum - get_four_momentum().get_energy()) > 1e-6) //allow small tolerance level
    {
        throw std::invalid_argument("Error: total energy deposited does not match electron's energy.");
    }
}

void Electron::print_data() 
{
    std::cout<<"Particle type: "<<(get_antiparticle_status() ? "Positron" : "Electron")<< std::endl;

    std::cout << "Deposited energies: (";
    for (double energy : deposited_energies) {
        std::cout<< " " <<energy<<",";
    }
    std::cout<<") MeV"<<std::endl;

    Lepton::print_data();
}