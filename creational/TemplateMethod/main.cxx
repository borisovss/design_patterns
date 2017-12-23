#include <iostream>

class Education {
  public:
    Education() {}
    virtual ~Education() {}
    virtual std::string stepName()  = 0;
    virtual std::string admission() = 0;
    virtual std::string studying()  = 0;
    virtual std::string control()   = 0;
    virtual std::string awarding()  = 0;
    void learn()
    {
      std::cout <<         stepName()  << std::endl;
      std::cout << "  " << admission() << std::endl;
      std::cout << "  " << studying()  << std::endl;
      std::cout << "  " << control()   << std::endl;
      std::cout << "  " << awarding()  << std::endl;
    }
};

class School: public Education {
  public:
    School() {}
    virtual ~School() {}
    std::string stepName()
    {
      return "School";
    }
    std::string admission()
    {
      return "Admission to school";
    }
    std::string studying()
    {
      return "Attending lessons";
    }
    std::string control()
    {
      return "Exams passage";
    }
    std::string awarding()
    {
      return "Getting school certificate";
    }
};


class University: public Education {
  public:
    University() {}
    virtual ~University() {}
    std::string stepName()
    {
      return "University";
    }
    std::string admission()
    {
      return "Going to university.";
    }
    std::string studying()
    {
      return "Attending lectures";
    }
    std::string control()
    {
      return "State examination";
    }
    std::string awarding()
    {
      return "Getting school diploma";
    }
};

int main()
{
  School     *oSchool     = new School();
  University *oUniversity = new University();

  oSchool->learn();
  oUniversity->learn();

  delete oSchool;
  delete oUniversity;

  return 0;
}
