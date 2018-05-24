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
    Boat(){};
    Boat(const std::string& name);
    
    virtual void draw()const;
    
    Bank* getBank() const;

    bool move(Bank* b);
    
    void setBank(Bank* bank);
    
private:
    Bank* _bank;
};

#endif /* BOAT_H */

