## nombre de lignes
j'ai ecris le plus petit programme qui ouvre une fenetre , la garde ouverte, et se termine proprement.
il fait 24 lignes avec 3 lignes vides  donc on a 21 lignes de code exactement au total
## retrouver chacune dans le chapitre

``#include "NKWindow/NKMain.h"`` : elle fournit le point d'entrée natif de chaque plateforme   ``dans la partie Vous n'écrivez pas de main.``

``#include "NKWindow/NKWindow.h"`` : elle donne acces a NKWindow/NKConfig ``presente dans le plus petit programme ``

 ``int nkmain(const nkentseu::NkEntryState& state) {``   : point d'entré qu'on ecrit ``dans la partie vous n'ecrivez pas de main .vous ecrivez nkmain``

 ``nkentseu::NkWindowConfig cfg;`` : declare la configuration de la fenetre ``dans la partie configurer et piloter la fenêtre``

``cfg.title = "MonTitre, etape 02";`` : elle sert a donner un nom a la fenetre ``dans la partie configurer et piloter la fenêtre``

``cfg.width = 720;`` : elle sert a donner la largeur de la fenetre ``dans la partie configurer et piloter la fenêtre``

``cfg.height = 550;`` : elle sert a donner la hauteur de la fenetre ``dans la partie configurer et piloter la fenêtre``

``nkentseu::NkWindow window;`` : declare l'objet la fenetre ``---``

`` if (!window.Create(cfg)) {`` : verifie que la creation a reussi ``dans la partie On vérifie IsOpen``

``logger.Error("Failed to create window");`` : cherche d'ou vient l'echec ``present dans le plus petit programme``

``return -1;`` sort proprement en cas d'echec ``present dans le plus petit programme``

``while (window.IsOpen()) {``  : boucle tant que la fenetre est ouverte  ``present dans le plus petit programme``

``while (nkentseu::NkEvent* event = nkentseu::NkEvents().PollEvent()) {`` : vide les differents elements a chaque tour  ``---``

``if (event->Is<nkentseu::NkWindowCloseEvent>()) {`` : detecte l'evenement de la fermeture ``present dans les douzes familles ``

``window.Close();`` declenche la fermeture de la fenetre ``---``

``return 0;`` sortie propre 


### j'ai testé sans l'venement de fermeture de la fentre: la fenetre est rester ouverte  sans possibilité de la fermé  . donc cette ligne etait necessaire, contrairement a runningv qui ne l'etait pas 


## compilation et execution du programme :
j'ai compilé avec ``jenga build`` la sortie obtrenue etait :
```
PS C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow> jenga build

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. Window [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Window                                                          Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Window\Window.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.57s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.57s
Status:         ✓ SUCCESS
═════════════════════════════════════════════════════════════
```

j'ai executé avec ``jenga run``  la sortie obtenue etait :
```
PS C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow> jenga run  

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window.exe
     C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.20s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```



