/* 
 * POO2:   Labo16 Rivières
 * File:   Boat.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */
#include "Boat.h"

Boat::Boat(const std::string& name) : Container(name), _bank(nullptr) {
}

void Boat::draw() const{
    std::cout << "< ";
    Container::draw();
    std::cout << ">";
}


Bank* Boat::getBank() const {
    return _bank;
}


bool Boat::move(Bank* b) {
    for (const Person* p : persons)
        if (p->canDrive()) {
            _bank = b;
            return true;
        }
    return false;
}

void Boat::setBank(Bank* bank) {
    _bank = bank;
}

