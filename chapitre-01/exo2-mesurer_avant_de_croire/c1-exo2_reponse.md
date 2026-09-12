## J'ai utilisé PowerShell pour compter les fichiers .cpp et .h ainsi que leurs lignes.

Commandes utilisées :

```
Get-ChildItem -Recurse -File -Filter *.cpp
Get-ChildItem -Recurse -File -Filter *.h
```

Pour les lignes, j'ai utilisé  ``` Get-Content ```  avec ``` Measure-Object -Line```.

Résultats :

* .cpp : **1609 fichiers**, **917647 lignes**
* .h : **2728 fichiers**, **988601 lignes**
* Total : **4337 fichiers**, **1906248 lignes**

Le chapitre indique **2641 fichiers** et **1193385 lignes**.

J'ai vérifié le dossier Build : il n'existe pas à la racine. Les dossiers de type Build, bin, obj, out ou Generated contiennent seulement **10 fichiers .cpp/.h**, soit **3255 lignes**.

J'ai aussi trouvé **164 fichiers .cpp/.h dans les dossiers de tests**.


Apres la remarque du professeur, j'ai aussi regardé la partie `External` avec `jenga info`.

Dans le dossier `Externals`, j'ai trouvé **1673 fichiers .cpp/.h**, avec **787518 lignes**.

En dehors de `Externals`, il reste **2662 fichiers**, avec **1117545 lignes**.

On voit donc que les fichiers externes représentent une grosse partie du dépôt. Et surtout, les **2662 fichiers hors `Externals`** sont assez proches des **2641 fichiers** annoncés dans le chapitre.

Donc, une partie de la différence vient sûrement des dépendances externes qui sont comptées dans mon dépôt actuel. Il reste aussi une différence sur le nombre de lignes, qui peut venir de la version actuelle du dépôt et de la façon dont le comptage a été fait.

