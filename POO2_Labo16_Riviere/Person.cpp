/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.cpp
 * Author: Jeremie
 * 
 * Created on 27. avril 2018, 07:44
 */

#include "Person.h"

Person::Person(const std::string& name, const Role& role, const Sex sex): name(name), role(role), sex(sex) {
}

bool Person::canDrive() const {
    return role.canDrive();
}

const std::string& Person::getName() const {
    return name;
}

const Role& Person::getRole() const {
    return role;
}

const Sex Person::getSex() const {
    return sex;
}



/*
Person::Person(const Person& orig) {
}
* */

