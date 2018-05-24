/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Container.cpp
 * Author: Jeremie
 * 
 * Created on 27. avril 2018, 08:10
 */

#include "Container.h"

Container::Container(const std::string& name) 
: name(name) 
{}



void Container::drawALL() const{
    std::cout << name << ": ";
    draw();
}

void Container::draw() const{
    for (auto it = persons.begin(); it != persons.end(); it++)
        std::cout << (*it)->getName() << " ";
}

void Container::add(Person* p){
    persons.push_back(p);
}

void Container::remove(Person* p){
    persons.remove(p);
}

bool Container::contains(Person* p) const{
    
    for(const Person* tmpP : persons)
        if(p == tmpP)
            return true;
    
    return false;
}

bool Container::containsRole(const Role& r) const{

    for (const Person* p : persons) {
        if (p->getRole() == r)
            return true;
    }

    return false;
}

bool Container::containsRoleSex(const Role& r, Sex s) const{
    for (const Person* p : persons)
        if (p->getRole() == r && p->getSex() == s)
            return true;

    return false;
}

void Container::clear(){
    persons.clear();
}

size_t Container::size() const {
    return persons.size();
}

/*
Container::Container() {
}

Container::Container(const Container& orig) {
    listPerson = orig.listPerson;
    //listPerson.splice(orig.listPerson.begin(), orig.listPerson.end());
}

Container::~Container() {
    
    // Supprimer les personnes dans la liste
}

*/