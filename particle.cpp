#include<iostream>
#include "particle.h"

// Assignment operator
particle& particle::operator=(const particle& copy)
{
  std::cout<<"calling copy operator\n";
  // The assignment operator needs to avoid self-assignment using the *this pointer
  if(this != &copy)
  {
    // Copy data from other particle
    name = copy.name;
    charge = copy.charge;
    antiparticle = copy.antiparticle;
    energy = copy.energy;
    momentum_x = copy.momentum_x;
    momentum_y = copy.momentum_y;
    momentum_z = copy.momentum_z;

    // Deep copy of the four-momentum vector
    delete four_momentum_copy;
    four_momentum_copy = new std::vector<double>(*copy.four_momentum_copy);
  }
  return *this;
}

// Move assignment operator
// The move assignment operator needs to correctly reassign the memory from the original object
particle& particle::operator=(particle&& move) noexcept
{
  std::cout<<"calling move operator\n";
  if(this != &move)
  {
    name = move.name;
    charge = move.charge;
    antiparticle = move.antiparticle;
    energy = move.energy;
    momentum_x = move.momentum_x;
    momentum_y = move.momentum_y;
    momentum_z = move.momentum_z;

    delete four_momentum_move;
    four_momentum_move = move.four_momentum_move;
    move.four_momentum_move = nullptr;
  }
  return *this;
}

// Sum operator
particle particle::operator+(const particle &other) const
{
  // particle sum // initialise
  // {
  //   "", 0, false, get_energy() + other.get_energy(), get_momentum_x() + other.get_momentum_x(), get_momentum_y() + other.get_momentum_y(), get_momentum_z() + other.get_momentum_z()
  // };
  particle sum;
  sum.set_energy(get_energy() + other.get_energy());
  sum.set_momentum_x(get_momentum_x() + other.get_momentum_x());
  sum.set_momentum_y(get_momentum_y() + other.get_momentum_y());
  sum.set_momentum_z(get_momentum_z() + other.get_momentum_z());
  return sum;
}

// Dot product operator
double particle::dot_product(const particle& other) const
{
  return (get_energy() * other.get_energy(), get_momentum_x() * other.get_momentum_x(), get_momentum_y() * other.get_momentum_y(), get_momentum_z() * other.get_momentum_z());
}

// Function to print info about a particle
void particle::print_data() const
{
  std::cout<<"particle type: "<<get_name()<<std::endl;
  std::cout<<"charge: "<<get_charge()<<std::endl;
  std::cout<<"energy: "<<get_energy()<<std::endl;
  std::cout<<"momentum x-component: "<<get_momentum_x()<<std::endl;
  std::cout<<"momentum y-component: "<<get_momentum_y()<<std::endl;
  std::cout<<"momentum z-component: "<<get_momentum_z()<<std::endl;
  std::cout<<"---------------------------------"<<std::endl;
}