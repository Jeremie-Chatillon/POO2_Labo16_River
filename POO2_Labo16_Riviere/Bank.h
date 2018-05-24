/* 
 * POO2:   Labo16 Rivières
 * File:   Bank.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */

#ifndef BANK_H
#define BANK_H

#include "Container.h"

/**
 * Contener représentant une berge
 */
class Bank : public Container{
public:
    /**
     * Constructeur
     * @param name nom de la berge
     */
    Bank(const std::string& name);
};

#endif /* BANK_H */

