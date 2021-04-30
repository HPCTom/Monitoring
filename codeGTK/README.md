Notre projet est l'implémentation d'un outil
de monitoring.

Notre programme se divise en deux parties, d'un côté les capteurs (sensors2.c), de l'autre l'interface(testGTK3.c et readproc.c).
Un makefile est fourni. 
Pour accéder à notre programme il faut saisir "./testGTK3" dans le bash après avoir exécuté 
la commande "make".

Installer GTK: sudo apt-install libgtk-3-dev

Installer libproc: sudo apt install libprocps-dev

Pour compilier le programme: gcc -o testGTK3 testGTK3.c -lprocps `pkg-config --cflags --libs gtk+-3.0`

Pour executer le programme: ./testGTK3

Bonne utilisation !
