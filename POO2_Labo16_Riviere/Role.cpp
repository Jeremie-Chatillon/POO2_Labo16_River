/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Role.cpp
 * Author: Jeremie
 * 
 * Created on 27. avril 2018, 12:24
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
