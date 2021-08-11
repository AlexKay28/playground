#include <iostream>
#include <vector>
#include <string>

class Gun {
public:
    virtual void Shoot() {
        std::cout << "BANG!" << std::endl;
    }
};

class MachineGun : public Gun {
public:
    void Shoot() override {
        std::cout << "BANG BANG BANG" << std::endl;
    }
};

class Player {
public:

    Player (std::string name): player_name_(name) {}

    void UseGun(Gun *gun) {
        std::cout << "My name: " << this->player_name_ << std::endl;
        gun->Shoot();
    }
private:
    std::string player_name_;
};

int main() {
    std::string choosed_gun;

    std::cout << "Create player and give him the gun" << std::endl;
    Player player1("Player1");

    std::cout << "Choose the gun [Pistol/MachineGun]" << std::endl;
    std::cin >> choosed_gun;
    if (choosed_gun == "Pistol") {
        Gun gun;
        player1.UseGun(&gun);
    } else if (choosed_gun == "MachineGun") {
        MachineGun mgun;
        player1.UseGun(&mgun);
    } else {
        throw std::invalid_argument("Bad gun name");
    }
}
