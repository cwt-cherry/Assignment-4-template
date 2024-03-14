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
  std::vector<double>* four_momentum_move;
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

  // Destructor
  ~particle()
  {
    std::cout<<"Destroying "<<name<<std::endl;
    // The destructor needs to free the memory allocated by the constructor
    delete four_momentum_copy;
  }

  // Copy constructor
  particle(const particle& copy):
    name{copy.name}, charge{copy.charge}, antiparticle{copy.antiparticle}, energy{copy.energy}, momentum_x{copy.momentum_x}, momentum_y{copy.momentum_y}, momentum_z{copy.momentum_z}
  {
    std::cout<<"calling copy constructor\n";
    // The copy constructor needs to make a deep copy of the std::vector holding the 4-momentum
    // Copy constructor with dynamic allocation
    four_momentum_copy = new std::vector<double>(copy.four_momentum);
  }

  // Copy (assignment) operator
  particle& operator=(const particle& copy);

  // Move constructor
  particle(particle&& move) noexcept:
    name{move.name}, charge{move.charge}, antiparticle{move.antiparticle}, energy{move.energy}, momentum_x{move.momentum_x}, momentum_y{move.momentum_y}, momentum_z{move.momentum_z}
  {
    std::cout<<"calling move constructor\n";
    // The move constructor needs to correctly steal the memory from the object you're calling it on
    four_momentum_move = nullptr;
  }
  
  // Move assignment operator
  particle& operator=(particle&& move) noexcept;
  
  // Getter functions (accessors) to individual elements of 4-momentum
  string get_name() const {return name;}
  int get_charge() const {return charge;}
  bool get_antiparticle() const {return antiparticle;}
  double get_energy() const {return energy;}
  double get_momentum_x() const {return momentum_x;}
  double get_momentum_y() const {return momentum_y;}
  double get_momentum_z() const {return momentum_z;}

  // Setter functions, to change values of 4-momentum 
  void set_name(string particle_name)
  {
    if(particle_name == "electron" || particle_name == "positron" || particle_name == "muon" || particle_name == "antimuon")
    {
      name = particle_name;
    }
    else
    {
      std::cerr << "Invalid particle name." << std::endl;
      exit(0);
    }
  }

  void set_charge(int particle_charge)
  {
    if(particle_charge == 1 || particle_charge == -1)
    {
      charge = particle_charge;
    }
    else
    {
      std::cerr << "Invalid particle charge. Value should be either +1 or -1" << std::endl;
      exit(0);
    }
  }

  void set_antiparticle(bool particle_antiparticle) {antiparticle = particle_antiparticle;}

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

  void set_momentum_x(double particle_energy)
  {
    if(particle_energy >= 0) // not limiting energy to the speed of light due to change in slides
    {
      momentum_x = particle_energy / speed_of_light;
    }
    else
    {
      std::cerr<<"Invalid energy. Energy should be between 0 and the speed of light."<<std::endl;
      exit(0);
    }
  }

  void set_momentum_y(double particle_energy)
  {
    if(particle_energy >= 0) // not limiting energy to the speed of light due to change in slides
    {
      momentum_y = particle_energy / speed_of_light;
    }
    else
    {
      std::cerr<<"Invalid energy. Energy should be between 0 and the speed of light."<<std::endl;
      exit(0);
    }
  }

  void set_momentum_z(double particle_energy)
  {
    if(particle_energy >= 0) // not limiting energy to the speed of light due to change in slides
    {
      momentum_z = particle_energy / speed_of_light;
    }
    else
    {
      std::cerr<<"Invalid energy. Energy should be between 0 and the speed of light."<<std::endl;
      exit(0);
    }
  }

  // Sum operator
  particle operator+(const particle &other) const;

  // Dot product operator
  double dot_product(const particle& other) const;

  // Function to print info about a particle 
  void print_data() const;

// End of particle class
};