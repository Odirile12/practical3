#include <iostream>
#include "user.h"
using namespace std;
#include "ctrlCat.h"
#include "dogorithm.h"
#include "AdminUser.h"
#include "RegularUser.h"



int main() {

    // Create chat rooms
    CtrlCat ctrlCatRoom;
    Dogorithm dogorithmRoom;

    // Create users
    AdminUser admin("NANA");
    RegularUser user1("CICI");
    RegularUser user2("TITI");

    ctrlCatRoom.registerUser(&admin);
    ctrlCatRoom.registerUser(&user1);

    dogorithmRoom.registerUser(&user2);
    dogorithmRoom.registerUser(&admin);

    admin.send("Hello, this is NANA!", &ctrlCatRoom);
    user1.send("Hi NANA, this is CICI!", &ctrlCatRoom);

    user2.send("Hello from TITI in Dogorithm!", &dogorithmRoom);
    admin.send("NANA here again in Dogorithm!", &dogorithmRoom);

    admin.receive("This is a direct message to NANA.", &user1, &ctrlCatRoom);
    user1.receive("This is a direct message to CICI.", &admin, &ctrlCatRoom);
    user2.receive("This is a direct message to TITI.", &admin, &dogorithmRoom);

    dogorithmRoom.removeUser(&user2);
    



    return 0;
}