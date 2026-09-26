dans cette exercice j'ai ajouter dans mon code 
```
cfg.minWidth = (300);      
cfg.minHeight = (250);
```
pour choisir les tailles minimales de ma fenetre 

et
```
auto size = window.GetSize();
logger.Info("X = {}", size.x);
logger.Info("Y = {}", size.y);
```
pour que la taille de la fenetre a sa fermeture s'affiche dans le terminal

## 1-fixer une taille minimale
j'ai choisis comme tailles minimales ``300`` et ``250``
j'ai compilé avec ``jenga build`` et j'ai executer avec ``jenga run`` 
 
 j'ai reduis la largeur et la hauteur le plus que possible et le terminal affcihe 
 ```
  ▶  EXECUTION  —  Window.exe
     C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-26 20:37:02.578] [INF] [default] [main.cpp:21 in nkmain] -> X = 278
[2026-09-26 20:37:02.579] [INF] [default] [main.cpp:22 in nkmain] -> Y = 194
```
donc le terminal nous dit que la largeur est de ``278`` et la hauteur ``194`` pourtant d'apres les donnée que j'ai inserer ca devait etre ``300`` et ``250``

## 2-la plus petite taille que le systeme accepte
ici  j'ai retirer les tailles minimales et j'ai compilé et executer,

j'ai ensuite reduis la fenetre jusqu'a ce que ce ne soit plus possible et le resultat obtenu dans le terminal est:
```
▶  EXECUTION  —  Window.exe
     C:\Users\BEST-COMPUTER\Desktop\dd\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-26 20:46:36.182] [INF] [default] [main.cpp:20 in nkmain] -> X = 176
[2026-09-26 20:46:36.183] [INF] [default] [main.cpp:21 in nkmain] -> Y = 34
```
donc la taille minimale que le systeme accepte est ``largeur=176`` et ``hauteur=34``