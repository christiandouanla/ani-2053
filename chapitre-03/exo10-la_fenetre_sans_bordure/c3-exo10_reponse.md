# exo 10 la fenetre sans bordure
dans cet exercice j'ai ajouté dans mon code 

```
cfg.frame = false;
```
pour retirer la bordure systeme de la fenêtre.

et une fonction `ZoneAt` qui détermine dans quelle zone de ma barre de titre se trouve un clic (les
3 boutons à droite, ou le reste qui sert à déplacer la fenêtre) :
```
if (x >= closeLeft) return TitleBarZone::Close;
if (x >= maximizeLeft) return TitleBarZone::MaximizeRestore;
if (x >= minimizeLeft) return TitleBarZone::Minimize;
```

et la logique de déplacement au clic maintenu :
```
dragging = true;
dragWindowStart = window.GetPosition();
...
window.SetPosition(dragWindowStart.x + deltaX, dragWindowStart.y + deltaY);
```

## test

j'ai compiler avec `jenga build` et executer avec `jenga run`.

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
════════════════════════════════════════════════════════════════════════════════

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

[2026-09-28 23:21:11.816] [INF] [default] [main.cpp:52 in nkmain] -> [exo10] barre de titre custom active : glissez pour deplacer, double-cliquez pour agrandir/restaurer
[2026-09-28 23:21:22.286] [INF] [default] [main.cpp:89 in nkmain] -> [exo10] debut du glisser a x=499 y=499
[2026-09-28 23:21:23.523] [INF] [default] [main.cpp:104 in nkmain] -> [exo10] fin du glisser, nouvelle position x=643 y=643
[2026-09-28 23:21:25.415] [INF] [default] [main.cpp:89 in nkmain] -> [exo10] debut du glisser a x=488 y=488
[2026-09-28 23:21:28.027] [INF] [default] [main.cpp:89 in nkmain] -> [exo10] debut du glisser a x=488 y=488
[2026-09-28 23:21:28.782] [INF] [default] [main.cpp:104 in nkmain] -> [exo10] fin du glisser, nouvelle position x=611 y=611
[2026-09-28 23:21:31.852] [INF] [default] [main.cpp:89 in nkmain] -> [exo10] debut du glisser a x=488 y=488
[2026-09-28 23:21:32.033] [INF] [default] [main.cpp:104 in nkmain] -> [exo10] fin du glisser, nouvelle position x=611 y=611

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (72.13s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

donc le terminal confirme que la fenêtre s'est ouverte sans bordure système, avec le message d'instructions
affiché, et que le programme s'est terminé normalement 