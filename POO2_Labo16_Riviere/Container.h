/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Container.h
 * Author: Jeremie
 *
 * Created on 27. avril 2018, 08:10
 */

#ifndef CONTAINER_H
#define CONTAINER_H



#include <iostream>
#include <cstring>
#include <list>


#include "Person.h"


class Container {
protected:
    std::string name;
    std::list<Person*> persons;
public:

    Container(){};

    Container(const std::string& name);
    

    virtual void drawALL() const;

    virtual void draw() const;

    virtual void add(Person* p);

    virtual void remove(Person* p);

    bool contains(Person* p) const;
    
    bool containsRole(const Role& r) const;

    bool containsRoleSex(const Role& r, Sex s) const;

    void clear();

    size_t size() const;
};

#endif /* CONTAINER_H */

