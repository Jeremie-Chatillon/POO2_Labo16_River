/* 
 * POO2:   Labo16 Rivières
 * File:   Controlleur.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
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
     * @param p     Presonne à déplacer
     * @param from  Contener d'origine
     * @param to    Conterner de destination
     */
    void commandMoveContainer(Person* p, Container* from, Container* to);
    
   /**
    * Change la référence de rive du bateau si il passe les conditions
    */
    void handleMoveBoat();
    
    /**
     * Contrôle qu'il y ait un conducteur sur le bateau et le déplace sur la berge
     * @param b Berge de destination du bateau
     */
    void checkAndMove(Bank* b);
    
    /**
     * Trouve une personne en fonction de leur nom
     * @param s nom de la personne
     * @return la personne
     */
    Person* findPersonByName(const std::string& s) const;
    
    /**
     * Vide les container bèreges et bateau
     */
    void clearConterner();
    
    /**
     * Place toutes les persone sur la berge
     * @param b berge des naufragés
     */
    void init(Bank* b);
    
protected:
    /**
     * Contrôles les règles si le voleur peut se déplacer
     * @param from  Contener d'origine
     * @param to    Conterner de destination
     * @return      true si il peut se dépéacer, sinon false
     */
    bool checkVoleurRule(Container* from, Container* to);
    
    bool checkPolicerRule(Container* from);


    /**
     * Check les règles pour les enfants. Comme il y a les filles et les garçon,
     *  il y a une méthode qui gère les deux, c'est pourquoi on doit psaser un 
     *  sex avec lequelle ils ne peuvent pas être et lequelle ils peuvent être
     * @param to    container de destination
     * @param sOk   Sex avec lequelle il peut être
     * @param sKo   Sex avec lequelle il ne peut pas être
     * @return      true si il peut se dépéacer, sinon false
     */
    bool checkChildRule(Container* to, const Sex& sOk, const Sex& sKo);
    
    /**
     * Contrôles les règles si le père peut se déplacer
     * @param from  Contener d'origine
     * @param to    Conterner de destination
     * @return      true si il peut se dépéacer, sinon false
     */
    bool checkFaterRule(Container* from, Container* to);
    
    /**
     * Contrôles les règles si la mère peut se déplacer
     * @param from  Contener d'origine
     * @param to    Conterner de destination
     * @return      true si elle peut se dépéacer, sinon false
     */
    bool checkMotherRule(Container* from, Container* to);
    
    /**
     * Regle global pour la famille. Elle ne peut pas se déplacer si le voleur est seul
     * @param to container de destination
     * @return      true si elle peut se dépéacer, sinon false
     */
    bool checkFamilyRules(Container* to);
    
private:
    // AFFICHAGE //
    static const size_t SIZE_RIVER = 60;
    static const char CHAR_RIVER = '=';
    static const char CHAR_BANK = '-';
    
    // Liste de toutes les personnes dans le jeux
    std::list<Person*> persons;
    
    // Containers
    Boat* boat;
    Bank* banks[COUNT_BANK];
    
    // Nombre de tours
    size_t _turn;
    
    bool _continue;     // Continuer à jouer  
};

#endif /* CONTROLLER_H */

