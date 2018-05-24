/* 
 * POO2:   Labo16 Rivières
 * File:   Role.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */
#include "Role.h"

const Role Role::POLICIER(true);
const Role Role::VOLEUR(false);
const Role Role::ADULTE(true);
const Role Role::ENFANT(false);

Role::Role() : _canDrive(false) {
}

Role::Role(bool _canDrive) : _canDrive(_canDrive) {
}


bool Role::canDrive() const {
    return _canDrive;
}

bool Role::operator==(const Role& r) const {
    return this == &r;
}

/*
Role::Role() {
}

Role::Role(const Role& orig) {
}

Role::~Role() {
}
*/
