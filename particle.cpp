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

    // Deep copy of the four-momentum vector
    delete four_momentum;
    four_momentum = new std::vector<double>(*copy.four_momentum);
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

    delete four_momentum;
    four_momentum = move.four_momentum;
    move.four_momentum = nullptr;
  }
  return *this;
}

// Sum operator
particle particle::operator+(const particle &other) const
{
  particle sum("", -1, false, (*four_momentum)[0] + other.four_momentum->at(0), (*four_momentum)[1] + other.four_momentum->at(1), (*four_momentum)[2] + other.four_momentum->at(2), (*four_momentum)[3] + other.four_momentum->at(3));
  // sum.set_energy(((*four_momentum)[0] + other.four_momentum->at(0))*speed_of_light);
  // sum.set_momentum_x((*four_momentum)[1] + other.four_momentum->at(1));
  // sum.set_momentum_y((*four_momentum)[2] + other.four_momentum->at(2));
  // sum.set_momentum_z((*four_momentum)[3] + other.four_momentum->at(3));
  return sum;
}

// Dot product operator
double particle::dot_product(const particle& other) const
{
  // Perform element-wise multiplication and subtraction according to the formula
  double dot_product_result{dot_product_result += (*four_momentum)[0] * other.four_momentum->at(0)};
  for(size_t i = 1; i < 4; ++i)
  {
    dot_product_result -= (*four_momentum)[i] * other.four_momentum->at(i);
  }
  return dot_product_result;
  // return (get_energy() * other.get_energy() - get_momentum_x() * other.get_momentum_x() - get_momentum_y() * other.get_momentum_y() - get_momentum_z() * other.get_momentum_z());
}

// Function to print info about a particle
void particle::print_data() const
{
  std::cout<<"particle type: "<<get_name()<<std::endl;
  std::cout<<"charge: "<<get_charge()<<std::endl;
  std::cout<<"energy: "<<get_energy()<<" MeV/c"<<std::endl;
  std::cout<<"momentum x-component: "<<get_momentum_x()<<" MeV"<<std::endl;
  std::cout<<"momentum y-component: "<<get_momentum_y()<<" MeV"<<std::endl;
  std::cout<<"momentum z-component: "<<get_momentum_z()<<" MeV"<<std::endl;
  std::cout<<"---------------------------------"<<std::endl;
}

void particle::print_vector() const
{
  std::cout<<"("<<get_energy()<<","<<get_momentum_x()<<","<<get_momentum_y()<<","<<get_momentum_z()<<")"<<std::endl;
}