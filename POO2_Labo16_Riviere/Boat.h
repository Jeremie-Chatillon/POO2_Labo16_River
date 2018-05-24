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
    
    virtual void draw()const;
    
    Bank* getBank() const;

    bool move(Bank* b);
    
    void setBank(Bank* bank);
    
    const size_t getCapacity();
    
private:
    Bank* _bank;
    const size_t CAPACITY;
};

#endif /* BOAT_H */

