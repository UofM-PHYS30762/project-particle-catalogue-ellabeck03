// PHYS 30762 Programming in C++
// Project
// Particle Catalogue


#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "electron.h"

using std::string;

//non-member functions
std::vector<double> sum_four_vectors(const FourMomentum& momentum1, const FourMomentum& momentum2)
{
  std::vector<double> summed_momentum;

  double summed_energy = momentum1.get_energy() + momentum2.get_energy();
  summed_momentum.push_back(summed_energy);

  for(size_t i=0; i<momentum1.get_momentum().size(); ++i)
  {
    summed_momentum.push_back(momentum1.get_momentum()[i] + momentum2.get_momentum()[i]);
  }

  return summed_momentum;
}

double dot_product(const FourMomentum& momentum1, const FourMomentum& momentum2)
{
  double four_momentum_dot_product = momentum1.get_energy() * momentum2.get_energy();

  for(size_t i=0; i<momentum1.get_momentum().size(); ++i)
  {
    four_momentum_dot_product -= (momentum1.get_momentum()[i] * momentum2.get_momentum()[i]);
  }

  return four_momentum_dot_product;
}


int main()
{
  std::vector<Lepton*> lepton_pointers;

  FourMomentum electron1_momentum(20.0, {1.0, 2.0, 3.0});
  Electron electron1(0.511, electron1_momentum, {5, 5, 5, 5});
  electron1.print_data();

  return 0;
}