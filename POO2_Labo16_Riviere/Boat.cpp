/* 
 * POO2:   Labo16 Rivières
 * File:   Boat.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */
#include "Boat.h"

Boat::Boat(const std::string& name, const size_t capacity) : Container(name), _bank(nullptr), CAPACITY(capacity) {
}

void Boat::draw() const{
    std::cout << "< ";
    Container::draw();
    std::cout << ">";
}


Bank* Boat::getBank() const {
    return _bank;
}

const size_t Boat::getCapacity() {
    return CAPACITY;
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

