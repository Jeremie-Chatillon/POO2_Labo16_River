/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Role.h
 * Author: Jeremie
 *
 * Created on 27. avril 2018, 12:24
 */

#ifndef ROLE_H
#define ROLE_H

/**
 * Classe Role fonctionnant comme un enum
 */
class Role{
public:    
    bool canDrive() const;
    
    
    static const Role POLICIER;
    static const Role VOLEUR;
    static const Role ADULTE;
    static const Role ENFANT;
    
    /*On ne veut pas pouvoire copoer un role*/
    Role(const Role&) = delete;
    Role &operator=(const Role& r) = delete;
    
    
    bool operator ==(const Role& r) const;
    
private:
    Role();
    Role(bool _canDrive);   
    bool _canDrive;
};
#endif /* ROLE_H */

