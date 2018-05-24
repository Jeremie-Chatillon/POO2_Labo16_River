/* 
 * POO2:   Labo16 Rivières
 * File:   Container.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
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

