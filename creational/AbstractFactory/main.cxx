#include <iostream>

namespace Season
{
    enum class Type
    {
        Summer,
        Winter
    };

    class ISeason
    {
        public:
            virtual ~ISeason() {}
            virtual void info() const = 0;
    };

    class Summer : public ISeason
    {
        public:
            virtual ~Summer() {}
            void info() const
            {
                std::cout << "Summer Season" << std::endl;
            }
    };

    class Winter : public ISeason
    {
        public:
            virtual ~Winter() {}
            void info() const
            {
                std::cout << "Winter Season" << std::endl;
            }
    };

    namespace Provider
    {
        class IProvider
        {
            public:
                virtual ~IProvider() {}
                virtual ISeason* getSeason() const = 0;
        };

        class Summer : public IProvider
        {
            public:
                virtual ~Summer() {}
                virtual ISeason *getSeason() const final
                {
                    return new Season::Summer();
                }
        };

        class Winter: public IProvider
        {
            public:
                virtual ~Winter() {}
                virtual Season::ISeason* getSeason() const final
                {
                    return new Season::Winter();
                }
        };
    }
}

Season::Provider::IProvider* getSeasonProvider(Season::Type seasonType)
{
    switch (seasonType)
    {
        case Season::Type::Summer: return new Season::Provider::Summer();
        case Season::Type::Winter: return new Season::Provider::Winter();
    }
    return nullptr;
}

int main()
{
  const Season::Provider::IProvider *seasonProvider = getSeasonProvider(Season::Type::Summer);

  const Season::ISeason *season = seasonProvider->getSeason();

  season->info();

  return 0;
}
