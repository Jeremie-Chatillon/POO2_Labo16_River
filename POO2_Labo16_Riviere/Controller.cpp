/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: Jeremie
 * 
 * Created on 27. avril 2018, 08:00
 */

#include "Controller.h"
#include "Bank.h"
#include "Boat.h"
#include "Person.h"
#include "Role.h"

Controller::Controller() {

    commands = {COMMAND_AFFICHER, COMMAND_DEBARQUER, COMMAND_DEPLACER, COMMAND_EMBARQUER, COMMAND_MENU, COMMAND_QUITTER, COMMAND_REINITIALISER};
    persons.push_back(new Person("policier", Role::POLICIER, Sex::HOMME));
    

    persons.push_back(new Person("paul", Role::ENFANT, Sex::HOMME));
    persons.push_back(new Person("pierre", Role::ENFANT, Sex::HOMME));
    persons.push_back(new Person("julie", Role::ENFANT, Sex::FEMME));
    persons.push_back(new Person("jeanne", Role::ENFANT, Sex::FEMME));
   
    persons.push_back(new Person("voleur", Role::VOLEUR, Sex::HOMME));
   
    persons.push_back(new Person("pere", Role::ADULTE, Sex::HOMME));
    persons.push_back(new Person("mere", Role::ADULTE, Sex::FEMME));
    
    boat = new Boat("Bateau", 2);
    
    banks[BANK_RIGHT] = new Bank("Droite");
    banks[BANK_LEFT] = new Bank("Gauche");
    
    init(banks[0]);
    
}
/*
Controller::Controller(const Controller& orig) {
    
}
*/
Controller::~Controller() {
    delete boat;
    for(int i = 0; i < COUNT_BANK; ++i){
        delete banks[i];
    }
}

