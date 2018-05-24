/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.h
 * Author: Jeremie
 *
 * Created on 27. avril 2018, 07:44
 */

#ifndef PERSON_H
#define PERSON_H

#include <cstdlib>
#include <iostream>
#include <list>

#include "Role.h"

enum Sex{HOMME, FEMME};


class Person {
private:    
    const std::string name;
    const Role& role;
    const Sex sex;
    
public:
    Person(const std::string& s, const Role& role, const Sex sex);
    
    
    bool canDrive() const;
    
    friend std::ostream& operator << (std::ostream& lhs, const Person& rhs){
            lhs << rhs.name;
        return lhs;
    }
    
    const std::string& getName() const;
    
    const Role& getRole() const;
    
    const Sex getSex() const;    
};



#endif /* PERSON_H */

