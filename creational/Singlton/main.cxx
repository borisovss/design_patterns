#include <iostream>

class Singlton
{
    Singlton() {}
    Singlton(const Singlton &);
    Singlton& operator=(Singlton const&);
  public:
    static Singlton& instance()
    {
        static Singlton *singlton = nullptr;
        if (!singlton)
            singlton = new Singlton();
        return *singlton;
    }
    const char* name() const
    {
        return "Singlton";
    }
};

int main()
{
    Singlton &singlton = Singlton::instance();

    std::cout << singlton.name() << std::endl;

    return 0;
}
