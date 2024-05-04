#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "menu_class.h"

//funkcja main - miejsce rozpoczecia programu
int main()
{
    menu klasa;
    srand(time(NULL));
    klasa.init_programme();
    system("PAUSE");
    return 0;
}
