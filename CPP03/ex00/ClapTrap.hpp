#include <iostream>
#include <string>

class ClapTrap
{
    private:
        ClapTrap(void);
        
        std::string Name;
        unsigned int Hit_Points;
        unsigned int Energy_Points;
        unsigned int Attack_Damage;

    public:
        ClapTrap(const std::string& name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);

        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);

        void takeDamage(unsigned int amount);

        void beRepaired(unsigned int amount);

        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;
        const std::string& getName() const;
        void setAttackDamage(unsigned int amount);
};

