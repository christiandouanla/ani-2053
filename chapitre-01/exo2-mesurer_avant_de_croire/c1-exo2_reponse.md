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

La différence vient donc probablement du fait que la version actuelle du dépôt contient plus de fichiers et de code que la version utilisée pour les chiffres du chapitre.
