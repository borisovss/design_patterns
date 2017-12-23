#include <iostream>

namespace Interface {
  namespace Actor {
    class Season   /* интерфейс объекта */
    {
      public:
        Season() {}
        virtual ~Season() {}
        virtual void info() = 0;
    };
  }
  namespace Factory {
    class Season /* интерфейс фабрики объектов */
    {
      public:
        Season() {}
        virtual ~Season() {}
        virtual Interface::Actor::Season* obtaineSeason() = 0;
    };
  }
}

namespace Actor {
  namespace Season {
    class Summer : public Interface::Actor::Season /* реализация объекта типа "Season::Summer" */
    {
      public:
        Summer() {}
        virtual ~Summer() {}
        void info() { std::cout << "Summer Season" << std::endl; }
    };
    class Winter : public Interface::Actor::Season /* реализация объекта "Season::Winter" */
    {
      public:
        Winter() {}
        virtual ~Winter() {}
        void info() { std::cout << "Winter Season" << std::endl; }
    };
  }
}

namespace Factory {
  namespace Season {
    class Summer : public Interface::Factory::Season /* реализация фабрики объектов "Season" типа "Summer" */
    {
      public:
        Summer() {}
        virtual ~Summer() {}
        virtual Interface::Actor::Season *obtaineSeason() { return new Actor::Season::Summer(); }
    };
    class Winter: public Interface::Factory::Season /* реализация фабрики объектов "Season" типа "Winter" */
    {
      public:
        Winter() {}
        virtual ~Winter() {}
        virtual Interface::Actor::Season* obtaineSeason() { return new Actor::Season::Winter(); }
    };
  }
}

/* получить используемую фабрику */
Interface::Factory::Season* obtaineSeasonFactory()
{
    #define SUMMER 1

    #if    SUMMER
        return new Factory::Season::Summer();
    #elif  Winter
        return new Factory::Season::Winter();
    #else
        return NULL;
    #endif
}

/* используем только интерфейсы - ничего не знаем о конкретных реализациях */
int main()
{
  /* получаем указатель на интерфейс фабрики */
  Interface::Factory::Season *oSeasonFactory = obtaineSeasonFactory();

  /* получаем указатель на интерфейс объекта типа 'Season' посредством фабрики */
  Interface::Actor::Season *oSeason = oSeasonFactory->obtaineSeason();

  /* используем объект */
  oSeason->info();

  /* удаляем объекты */
  delete oSeasonFactory;
  delete oSeason;

  return 0;
}
