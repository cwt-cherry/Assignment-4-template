// PHYS 30762 Programming in C++
// Assignment 4
// Practice special functions and operators in C++ classes

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using std::string;

// Beginning of particle class
class particle
{
private:
  string name;
  int charge{1}; // -1 or +1
  const double speed_of_light = 2.9979245e8; // Unit of m/s
  bool antiparticle;
  double energy{0}; // Between 0 and c
  double momentum_x{0};
  double momentum_y{0};
  double momentum_z{0};
  std::vector<double> four_momentum;
  std::vector<double>* four_momentum_copy;
  // We need the four-vector, you can leave the particle mass (or remove it, we don't mark it)


public:
  // Default Constructor
  particle(): name{}, charge{}, antiparticle{}, energy{}, momentum_x{}, momentum_y{}, momentum_z{}
  {
  }

  // Parameterised Constructor
  // The parameterised constructor needs to dynamically allocate the std::vector containing the four-vector elements
  // The parameterised constructor also needs to check the validity of the energy component
  particle(string particle_name, int particle_charge, bool particle_antiparticle, double particle_energy, double particle_momentum_x, double particle_momentum_y, double particle_momentum_z):
    name{particle_name}, charge{particle_charge}, antiparticle(particle_antiparticle), energy{particle_energy}, momentum_x{particle_momentum_x}, momentum_y{particle_momentum_y}, momentum_z{particle_momentum_z}
  {
    four_momentum.push_back(energy);
    four_momentum.push_back(momentum_x);
    four_momentum.push_back(momentum_y);
    four_momentum.push_back(momentum_z);
  }

  // Copy constructor
  particle(const particle& copy):
    name{copy.name}, charge{copy.charge}, antiparticle{copy.antiparticle}, energy{copy.energy}, momentum_x{copy.momentum_x}, momentum_y{copy.momentum_y}, momentum_z{copy.momentum_z}
  {
    // The copy constructor needs to make a deep copy of the std::vector holding the 4-momentum
    // Copy constructor with dynamic allocation
    four_momentum_copy = new std::vector<double>(copy.four_momentum);
  }

  // Destructor
  ~particle()
  {
    std::cout<<"Destroying "<<name<<std::endl;
    // The destructor needs to free the memory allocated by the constructor
    delete four_momentum_copy;
  }

  // Assignment operator
  // The assignment operator needs to avoid self-assignment using the *this pointer

  // Move constructor
  // The move constructor needs to correctly steal the memory from the object you're calling it on
  
  // Move assignment operator
  // The move assignment operator needs to correctly reassign the memory from the original object
  
  // Getter functions (accessors) to individual elements of 4-momentum
  double get_energy() const
  {
    return energy;
  }

  double get_momentum_x() const
  {
    return momentum_x;
  }

  double get_momentum_y() const
  {
    return momentum_y;
  }

  double get_momentum_z() const
  {
    return momentum_z;
  }

  // Setter functions, to change values of 4-momentum 
  void set_momentum_x(double particle_energy)
  {
    momentum_x = particle_energy / speed_of_light;
  }
  void set_momentum_y(double particle_energy)
  {
    momentum_y = particle_energy / speed_of_light;
  }
  void set_momentum_z(double particle_energy)
  {
    momentum_z = particle_energy / speed_of_light;
  }
  // Make sure you check input validity for the energy in the 4-momentum 
  void set_energy(double particle_energy)
  {
    if(particle_energy >= 0) // not limiting energy to the speed of light due to change in slides
    {
      energy = particle_energy;
    }
    else
    {
      std::cerr<<"Invalid energy. Energy should be between 0 and the speed of light."<<std::endl;
      exit(0);
    }
  }

  // Sum operator
  particle operator+(const particle &other) const
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
  double dot_product(const particle& other) const
  {
    return (get_energy() * other.get_energy(), get_momentum_x() * other.get_momentum_x(), get_momentum_y() * other.get_momentum_y(), get_momentum_z() * other.get_momentum_z());
  }

  // Function to print info about a particle 
  // (not necessary or marked, but nice as you can extend the one you already have from Assignment 3)
  void print_data();

};

// Implementation of functions goes here

// End of particle class and associated member functions

// Define variable
const double speed_of_light = 2.9979245e8; // Unit of m/s

// Random velocity generating function
double random_energy() 
{
  return static_cast<double>(std::rand()) / RAND_MAX * speed_of_light;
}

// Main program
int main()
{
  particle p;

  // Create the following particles: 
  // two electrons, four muons, one antielectron, one antimuon 
  // Use the parameterised constructor to do these
  particle electron1("electron", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle electron2("electron", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle electron3("positron", 1, true, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon1("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon2("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon3("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon4("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon5("antimuon", 1, true, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());

  std::vector<particle> particles;

  particles.push_back(electron1);
  particles.push_back(electron2);
  particles.push_back(electron3);
  particles.push_back(muon1);
  particles.push_back(muon2);
  particles.push_back(muon3);
  particles.push_back(muon4);
  particles.push_back(muon5);

  // (optional but nice) Print out the data from all the particles (put them in a vector)

  // Sum the four-momenta of the two electrons 
  // Do the dot product of the first two four-muons

  // Assignment operator of an electron to a new electron
  // Copy constructor of the first muon to a new muon
  // Move the antielectron into another antielectron using the move constructor 
  // Assign the antimuon to another antimuon using the move assignment

  // (optional but nice) Here or at the end of each step, print the new particle info
  // to convince yourself that you have used all special functions and operations correctly

  return 0;
}