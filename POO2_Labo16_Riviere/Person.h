/* 
 * POO2:   Labo16 Rivières
 * File:   Person.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
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
    
    /**
     * Indique si elle peut conduire
     * @return true si oui, sinon false
     */
    bool canDrive() const;
    
    
    /**
     * Getter du nom
     * @return le nom
     */
    const std::string& getName() const;
    
    /**
     * Getter du role
     * @return le role
     */
    const Role& getRole() const;
    
    /**
     * getter du sex
     * @return le sex (par copue car c'est un enum
     */
    const Sex getSex() const; 
    
    /**
     * Surcharge de l'opérateur de flux <<
     */
    friend std::ostream& operator << (std::ostream& lhs, const Person& rhs){
            lhs << rhs.name;
        return lhs;
    }
    
};



#endif /* PERSON_H */

