/* 
 * POO2:   Labo16 Rivières
 * File:   Bank.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */

#include "Controller.h"
#include "Bank.h"
#include "Boat.h"
#include "Person.h"
#include "Role.h"

Controller::Controller() {
    
    persons.push_back(new Person("policier", Role::POLICIER, Sex::HOMME));
    persons.push_back(new Person("voleur", Role::VOLEUR, Sex::HOMME));

    persons.push_back(new Person("paul", Role::ENFANT, Sex::HOMME));
    persons.push_back(new Person("pierre", Role::ENFANT, Sex::HOMME));
    persons.push_back(new Person("julie", Role::ENFANT, Sex::FEMME));
    persons.push_back(new Person("jeanne", Role::ENFANT, Sex::FEMME));
   
    persons.push_back(new Person("pere", Role::ADULTE, Sex::HOMME));
    persons.push_back(new Person("mere", Role::ADULTE, Sex::FEMME));
    
    boat = new Boat("Bateau", 2);
    
    banks[BANK_RIGHT] = new Bank("Droite");
    banks[BANK_LEFT] = new Bank("Gauche");
    
    init(banks[0]);
    
}

Controller::~Controller() {
    delete boat;
    for(int i = 0; i < COUNT_BANK; ++i){
        delete banks[i];
    }
    
    for(Person* p: persons)
        delete p;
}

void Controller::play() {
    drawMenu();
    drawRiver();

    do {
        handleCommand(askCommand());
    } while (_continue);
}

void Controller::drawMenu() {
    std::cout << COMMAND_AFFICHER << "      : afficher" << std::endl;
    std::cout << COMMAND_EMBARQUER << " <nom>: embarquer <nom>" << std::endl;
    std::cout << COMMAND_DEBARQUER << " <nom>: debarquer <nom>" << std::endl;
    std::cout << COMMAND_DEPLACER << "      : deplacer bateau" << std::endl;
    std::cout << COMMAND_REINITIALISER << "      : reinitialiser" << std::endl;
    std::cout << COMMAND_QUITTER << "      : quitter" << std::endl;
    std::cout << COMMAND_MENU << "      : menu" << std::endl;

}

void Controller::drawRiver(){
    drawLine(CHAR_BANK, SIZE_RIVER);
    banks[0]->drawALL();
    drawLine(CHAR_BANK, SIZE_RIVER);
    if(boat->getBank() == banks[BANK_RIGHT]){
        boat->drawALL();   
        drawLine(CHAR_RIVER, SIZE_RIVER);
    } else{
        drawLine(CHAR_RIVER, SIZE_RIVER);
        boat->drawALL(); 
    }



    drawLine(CHAR_BANK, SIZE_RIVER);
    banks[1]->drawALL();
    drawLine(CHAR_BANK, SIZE_RIVER);
}

void Controller::drawLine(char c, size_t nbChar) {
    char buf[nbChar + 1];
    buf[nbChar] = '\0';
    memset(buf, c, nbChar); // pour ne pas faire une while sur un cout

    std::cout << std::endl << buf << std::endl;
}

std::string Controller::askCommand() {
    std::string command = "";
    std::cout << std::endl << std::to_string(_turn) << "> ";
    std::getline(std::cin, command);

    return command;
}

void Controller::handleCommand(const std::string& s) {
    char c;
    try {
        c = s.at(0);
    } catch (const std::exception& e) {
        std::cout << "Erreur: Pas de commande" << std::endl;
        return;
    }

    if (c == COMMAND_DEBARQUER) {
        handleMovePerson(s, &Controller::commandDebark);
        return;

    } else if (c == COMMAND_EMBARQUER) {
        handleMovePerson(s, &Controller::commandEmbark);
        return;

    } else if (s.size() == 1) { // Toutes les commandes sauf Embarquer/Debarquer doivent avoir 1 seul caractère
        switch (c) {
            case COMMAND_AFFICHER:
                drawRiver();
                break;

            case COMMAND_DEPLACER:
                ++_turn;
                handleMoveBoat();
                break;

            case COMMAND_MENU:
                drawMenu();
                break;

            case COMMAND_QUITTER:
                _continue = false;
                break;

            case COMMAND_REINITIALISER:
                clearConterner();
                init(banks[BANK_RIGHT]);
                drawMenu();
                break;

            default:
                std::cout << "Erreur: Caractere invalide" << std::endl;
        }
    } else {
        std::cout << "Erreur: Commande invalide" << std::endl;
    }
}

void Controller::handleMovePerson(const std::string& s, void(Controller::*fptr)(Person*)) {

    if (s.length() <= 2) {
        std::cout << "Erreur: Entrez une personne: " << s << std::endl;
        return;
    } else {
        std::string tmpS = s.substr(2);
        Person* p = findPersonByName(tmpS);

        if (p == nullptr) {
            std::cout << "Erreur: Entrez un nom correcte" << std::endl;
            return;
        } else {
            ++_turn;
            (this->*fptr)(p);
        }
    }
}

void Controller::handleMoveBoat() {
    if (boat->getBank() == banks[BANK_LEFT]) {
        checkAndMove(banks[BANK_RIGHT]);
    } else {
        checkAndMove(banks[BANK_LEFT]);
    }
    drawRiver();
}

void Controller::commandEmbark(Person* p) {
    if (boat->size() >= boat->getCapacity()) {
        std::cout << "Erreur: Bateau plein" << std::endl;
        return;
    } else if (!boat->getBank()->contains(p)) {
        std::cout << "Erreur: personne pas sur la rive" << std::endl;
        return;
    } else {
        commandMoveContainer(p, boat->getBank(), boat);
    }
}

void Controller::commandDebark(Person* p) {
    if (!boat->contains(p)) {
        std::cout << "Erreur: personne pas dans le bateau" << std::endl;
        return;
    } else {
        commandMoveContainer(p, boat, boat->getBank());
    }
}

void Controller::commandMoveContainer(Person* p, Container* from, Container* to) {
    const Role& r = p->getRole();
    bool canMove = true;

    if (r == Role::VOLEUR) {
        canMove = checkVoleurRule(from, to);

    } else if (r == Role::POLICIER) {
        canMove = checkPolicerRule(from);

    } else if (r == Role::ADULTE) {
        if (p->getSex() == Sex::HOMME) {
            canMove = checkFaterRule(from, to);
        } else {
            canMove = checkMotherRule(from, to);
        }

    } else if (r == Role::ENFANT) {
        Sex sOk = p->getSex();

        canMove = checkChildRule(from, sOk, sOk == Sex::HOMME ? Sex::FEMME : Sex::HOMME);
    };

    if (canMove) {
        to->add(p);
        from->remove(p);
        drawRiver();
    }
}

bool Controller::checkVoleurRule(Container* from, Container* to) {
    if (to->size() == 0 || to->containsRole(Role::POLICIER))
        return true;
    else {
        std::cout << "### Le voleur ne peut rester avec des autres personnes sans le policier" << std::endl;
        return false;
    }
}

bool Controller::checkPolicerRule(Container* from) {
    // from->size() <= 2  ==> c'est qu'il est seul avec le voleur
    if (!from->containsRole(Role::VOLEUR) || from->size() <= 2)
        return true;
    else {
        std::cout << "### Le policier ne peut laisser le voleur avec des autres personnes" << std::endl;
        return false;
    }
}

bool Controller::checkChildRule(Container* to, const Sex& sOk, const Sex& sKo) {
    if (!checkFamilyRules(to)) {
        return false;
    }

    if (!to->containsRoleSex(Role::ADULTE, sOk) && to->containsRoleSex(Role::ADULTE, sKo)) {
        std::cout << "### Un enfant ne doit pas rester seul avec son parent de sex oppose" << std::endl;
        return false;
    }
    else
        return true;
}

bool Controller::checkMotherRule(Container* from, Container* to) {
    if (!checkFamilyRules(to)) {
        return false;
    }


    if ((to->containsRoleSex(Role::ENFANT, Sex::HOMME) && !to->containsRoleSex(Role::ADULTE, Sex::HOMME))
            || (from->containsRoleSex(Role::ENFANT, Sex::FEMME) && from->containsRoleSex(Role::ADULTE, Sex::HOMME))) {
        std::cout << "### Le pere ne peut pas laisser ses fils seuls avec la mere" << std::endl;
        return false;
    } else {
        return true;
    }
}

bool Controller::checkFaterRule(Container* from, Container* to) {
    if (!checkFamilyRules(to)) {
        return false;
    }

    if ((to->containsRoleSex(Role::ENFANT, Sex::FEMME) && !to->containsRoleSex(Role::ADULTE, Sex::FEMME))
            || (from->containsRoleSex(Role::ENFANT, Sex::HOMME) && from->containsRoleSex(Role::ADULTE, Sex::FEMME))) {
        std::cout << "### Le pere ne peut pas laisser ses fils seuls avec la mere" << std::endl;
        return false;
    } else {
        return true;
    }
}

bool Controller::checkFamilyRules(Container* to) {
    if (!to->containsRole(Role::VOLEUR) || to->containsRole(Role::POLICIER))
        return true;
    else {
        std::cout << "### Il faut le policier pour être avec le voleur" << std::endl;
        return false;
    }
}

void Controller::checkAndMove(Bank* b) {
    if (!boat->move(b)) {
        std::cout << "Erreur: Il n'y a pas de conducteur" << std::endl;
    }
}

Person* Controller::findPersonByName(const std::string& s) const {
    for (Person* p : persons) {
        if (s == p->getName())
            return p;
    }

    return nullptr;
}

void Controller::clearConterner() {
    if (!boat->size())
        boat->clear();

    for (size_t i = 0; i < COUNT_BANK; ++i)
        if (!banks[i]->size())
            banks[i]->clear();
}

void Controller::init(Bank* b) {
    for (auto it = persons.begin(); it != persons.end(); it++)
        b->add(*it);

    boat->setBank(b);

    _turn = 0;
    _continue = true;
}


