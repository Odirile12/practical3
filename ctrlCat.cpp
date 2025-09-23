#include "ctrlCat.h"

void CtrlCat::rgisterUser(User* u){
    addUser(u);
}
void CtrlCat::removeUser(User* u){
    deleteUser(u);
}

// this wuold be chatRoom cat*=new ctrlCat();