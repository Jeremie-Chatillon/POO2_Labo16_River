/* 
 * POO2:   Labo16 Rivières
 * File:   Conatiner.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */

#ifndef CONTAINER_H
#define CONTAINER_H



#include <iostream>
#include <cstring>
#include <list>


#include "Person.h"

/**
 * Classe perettant de stocker des personnes
 */
class Container {
protected:
    std::string name;           
    std::list<Person*> persons;
public:

    Container(){};
    Container(const std::string& name);
    
    /**
     * Affiche le nom du container et la liste de personne
     */
    virtual void drawALL() const;

    /**
     * Afficher la liste des personnes
     */
    virtual void draw() const;

    /**
     * Ajout une personne a la fin du container
     * @param p Personne à ajouters
     */
    virtual void add(Person* p);

    /**
     * enlève une personne du container si elle y est
     * @param p Personne à enlever
     */
    virtual void remove(Person* p);

    /**
     * Rechercher une personne dans le container
     * @param p personne à rechercher
     * @return  true si la personne y est, sinon false
     */
    bool contains(Person* p) const;
    
    /**
     * Rechercher un role dans le container (toutes personnes ont un rôle
     * @param p personne à rechercher
     * @return  true si la personne y est, sinon false
     */
    bool containsRole(const Role& r) const;

    /**
     * Recher si il y a une personne avec role && un sex
     * @param r personne à rechercher
     * @param s Sex à rechecher
     * @return true si la personne && le sex y est, sinon false
     */
    bool containsRoleSex(const Role& r, Sex s) const;

    /**
     * Vide le container
     */
    void clear();

    /**
     * Taille du container
     * @return la taille du container
     */
    size_t size() const;
};

#endif /* CONTAINER_H */

