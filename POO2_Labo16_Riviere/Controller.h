/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: Jeremie
 *
 * Created on 27. avril 2018, 07:53
 */

#define R_POLICIER  0;
#define R_VOLEUR    1;
#define R_ADULTE    2;
#define R_ENFANT    3; 


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cstring>
#include <list>

#include "Container.h"
#include "Bank.h"
#include "Boat.h"

// COMMAND LIST //
#define COMMAND_AFFICHER        'p'
#define COMMAND_EMBARQUER       'e'
#define COMMAND_DEBARQUER       'd'
#define COMMAND_DEPLACER        'm'
#define COMMAND_REINITIALISER   'r'
#define COMMAND_QUITTER         'q'
#define COMMAND_MENU            'h'

// BANK LIST //
#define BANK_RIGHT              0
#define BANK_LEFT               1
#define COUNT_BANK              2

class Controller {
public:
    Controller();
    virtual ~Controller();
    
    /**
     * Permet de jouer au jeux
     */
    void play();
private:
    /**
     * Dessine le menu
     */
    void drawMenu();
    /**
     * Dessine la rivière
     */
    void drawRiver();
    /**
     * Desinne une ligne
     * @param c         Caractère de la ligne
     * @param nbChar    Nombre de caractères
     */
    void drawLine(char c, size_t nbChar);
    
    /**
     * Demande une entrée untilisateur. Lit 1 seule ligne à la fois
     * @return ligne entrée par l'utilisateur lue
     */
    std::string askCommand();
    
    /**
     * Taite la commande
     * @param s
     */
    void handleCommand(const std::string& s);
   
    /**
     * Permet de bouger une persone sur un bateau ou une berge (fptr)
     * @param s    commande (contien le nom de la personne
     * @param fptr permet d'appliquer une fonction sur le type demovenment
     */
    void handleMovePerson(const std::string& s, void (Controller::*fptr)(Person* p));
    
    /**
     * Ebarque une perssonne sur un la barque si elle le peut
     * @param p Personne à déplacer
     */
    void commandEmbark(Person * p);
    
    /**
     * Déplace la personne du bateau sur la berge si elle le peut
     * @param p Personne à déplacer
     */
    void commandDebark(Person * p);
    
    /**
     * Permet de déplcaer une personne d'un container à un autre en checkant les règles
     * @param p 
     * @param from
     * @param to
     */
    void commandMoveContainer(Person* p, Container* from, Container* to);
    
    

    void handleMoveBoat();
    
    void checkAndMove(Bank* b);
    
    Person* findPersonByName(const std::string& s) const;
    

    void clearConterner();
    void init(Bank* b);
    
protected:
    bool checkVoleurRule(Container* from, Container* to);
    
    bool checkPolicerRule(Container* from);

    /**
     * Règle s'appliquant aux fils
     * @param to
     * @param s         sex avec lequelle il ne doit pas être
     * @return 
     */
    bool checkChildRule(Container* to, const Sex& sOk, const Sex& sKo);
    
    bool checkFaterRule(Container* from, Container* to);
    
    bool checkMotherRule(Container* from, Container* to);
    
    bool checkFamilyRules(Container* to);
    
private:
    static const size_t SIZE_RIVER = 60;
    static const char CHAR_RIVER = '=';
    static const char CHAR_BANK = '-';
    

    std::list<Person*> persons;
    
    // Containers
    Boat* boat;
    Bank* banks[COUNT_BANK];
    
    size_t _turn;
    
    bool _continue;     // Continuer à jouer  
};

#endif /* CONTROLLER_H */

