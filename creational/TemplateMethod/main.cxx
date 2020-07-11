#include <iostream>

class Education
{
    protected:
        virtual const char* stepName() const  = 0;
        virtual const char* admission() const = 0;
        virtual const char* studying() const = 0;
        virtual const char* control() const = 0;
        virtual const char* awarding()  const = 0;
    public:
        virtual ~Education() {}
        void learn() const
        {
            std::cout <<         stepName()  << std::endl;
            std::cout << "  " << admission() << std::endl;
            std::cout << "  " << studying()  << std::endl;
            std::cout << "  " << control()   << std::endl;
            std::cout << "  " << awarding()  << std::endl;
        }
};

class School: public Education
{
    const char* stepName() const final { return "School"; }
    const char* admission() const final { return "Admission to school"; }
    const char* studying() const final { return "Attending lessons"; }
    const char* control() const final { return "Exams passage"; }
    const char* awarding() const final { return "Getting school certificate"; }
  public:
    virtual ~School() {}
};


class University: public Education
{
    const char* stepName() const final { return "University"; }
    const char* admission() const final { return "Going to university."; }
    const char* studying() const final { return "Attending lectures"; }
    const char* control() const final { return "State examination"; }
    const char* awarding() const final { return "Getting school diploma"; }
  public:
    virtual ~University() {}
};

int main()
{
  const School *school = new School();
  school->learn();

  const University *university = new University();
  university->learn();

  return 0;
}
