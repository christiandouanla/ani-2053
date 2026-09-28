# exo 9 les quatres dialogue

dans cet exercice j'ai ajouté dans mon code 

​```
NkDialogResult res = NkDialogs::OpenFileDialog("*.*", "Ouvrir un fichier");
NkDialogResult res = NkDialogs::SaveFileDialog("txt", "Enregistrer sous");
NkDialogResult res = NkDialogs::OpenFolderDialog("Choisir un dossier");
NkDialogResult res = NkDialogs::ColorPicker(0xFFFFFFFF);
​```
pour declenché les quatre dialogue natifs un par touche (O, S, D, C) et Echap pour quitter.

et
​```
if (!res.confirmed) {
    logger.Info("[exo9] %s : annule par l'utilisateur", nomDialogue.CStr());
    return;
}
​```
pour verifier que l'utilisateur n'a pas annulé avant d'utiliser `res.path` ou `res.color`.

## test

j'ai compiler avec `jenga build` et exécuter avec `jenga run`.

​```
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
│  ✓ Build Successful                                                             Time: 7.72s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           7.72s
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

[2026-09-28 23:07:09.154] [INF] [default] [main.cpp:32 in nkmain] -> [exo9] O = ouvrir un fichier | S = enregistrer sous | D = choisir un dossier | C = choisir une couleur | Echap = quitter
[2026-09-28 23:07:16.983] [INF] [default] [main.cpp:13 in LogDialogResult] -> [exo9] OpenFileDialog : annule par l'utilisateur
[2026-09-28 23:07:22.572] [INF] [default] [main.cpp:13 in LogDialogResult] -> [exo9] SaveFileDialog : annule par l'utilisateur
[2026-09-28 23:07:34.760] [INF] [default] [main.cpp:13 in LogDialogResult] -> [exo9] OpenFolderDialog : annule par l'utilisateur
[2026-09-28 23:07:38.531] [INF] [default] [main.cpp:13 in LogDialogResult] -> [exo9] ColorPicker : annule par l'utilisateur

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (37.67s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
PS C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow> 
​```

donc le terminal confirme que le programme se lance bien, affiche le message d'instructions, et qu'en
appuyant sur une touche puis en annulant le dialogue, le programme continue normalement sans planter.