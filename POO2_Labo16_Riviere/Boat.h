/* 
 * POO2:   Labo16 Rivières
 * File:   Boat.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */

#ifndef BOAT_H
#define BOAT_H

#include "Container.h"
#include "Bank.h"
class Bank;

class Boat : public Container {
public:
    
    Boat(): CAPACITY(2){};
    Boat(const std::string& , const size_t capacity);
    
    /**
     * affiche le bateau
     */
    virtual void draw()const;
    
    /**
     * Getter de le poineur sur la berge
     * @return poineur sur berge du bateau
     */
    Bank* getBank() const;

    /**
     * Bouge le bateau sur la berge de destination si le bateau a un conducteur
     * @param b berge de destination
     * @return  true si le bateau à pu bouger, sinon false
     */
    bool move(Bank* b);
    
    /**
     * Set le poineur sur la berge
     * @return nouvelle berge
     */
    void setBank(Bank* bank);
    
    /**
     * Getter de la capacité max du bateau
     * @return capacité max du bateau
     */
    const size_t getCapacity();
    
private:
    Bank* _bank;                // reference sur la berge ou se trouve le bateau
    const size_t CAPACITY;      // capacité max du bateau
};

#endif /* BOAT_H */

