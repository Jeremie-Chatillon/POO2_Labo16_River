/* 
 * POO2:   Labo16 Rivières
 * File:   Role.cpp
 * Author: Jeremie & James
 * 
 * Created on 27. avril 2018, 12:52
 */

#ifndef ROLE_H
#define ROLE_H

/**
 * Classe Role fonctionnant comme un enum
 */
class Role{
public:    
    /**
     * si le rôle peut conduire
     * @return ture si ou,false sinon
     */
    bool canDrive() const;
    
    
    static const Role POLICIER;
    static const Role VOLEUR;
    static const Role ADULTE;
    static const Role ENFANT;
    
    /*On ne veut pas pouvoire copoer un role*/
    Role(const Role&) = delete;
    Role &operator=(const Role& r) = delete;
    
    /**
     * COmpare 2 rôles pour savoir si c'est les même
     * @param r role à comparer
     * @return true = même rôle, sinon false
     */
    bool operator ==(const Role& r) const;
    
protected:
    /**
     * Constructeurs en protected pour pas que l'utilisateur puisse créer des nouveaux rôles mais qu'on puisse les surcharger
     */
    Role();
    Role(bool _canDrive);   

private:
    bool _canDrive;
};
#endif /* ROLE_H */

