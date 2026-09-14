# Exercice 7 — Le temps que ça prend

## 1. Mesure de la construction à froid

Avant la première mesure, j’ai nettoyé les fichiers générés avec :

```
jenga clean
```

Ensuite, j’ai lancé la construction du projet `MonEssai` :

```
jenga build --project MonEssai
```

Cette première construction était une construction complète à froid. Les 6 projets nécessaires ont été construits :
````

| Projet      | Temps |
|             |       |
| NKPlatform  | 8,54 s|
| NKCore      | 3,27 s|
| NKMemory    | 4,91 s|
| NKContainers| 7,77 s|
| NKMath      | 9,36 s|
| MonEssai    | 5,13 s|
| Total       |38,99 s|
````

La construction s’est terminée avec le statut `SUCCESS`.

## 2. Deuxième construction sans modification

Juste après, sans modifier aucun fichier, j’ai relancé exactement la même commande :

```
jenga build --project MonEssai
```

Cette fois, les 6 projets ont affiché :

```
All files up to date
```

Les temps affichés étaient :

- NKPlatform : 0,10 s
- NKCore : 0,11 s
- NKMemory : 0,33 s
- NKContainers : 1,44 s
- NKMath : 0,60 s
- MonEssai : 0,07 s

**Temps total : 2,66 s**

La construction s’est également terminée avec le statut `SUCCESS`.

## 3. Écart entre les deux constructions

La première construction a pris **38,99 s**, tandis que la deuxième a pris **2,66 s**.

L’écart est donc :

**38,99 − 2,66 = 36,33 s**

La deuxième construction est donc beaucoup plus rapide parce qu'aucun fichier n'avait été modifié entre les deux lancements. Jenga a indiqué que les fichiers étaient déjà à jour et n'a donc pas eu besoin de refaire la compilation.

## 4. Comment Jenga sait qu'il n'a pas besoin de recompiler ?

En regardant les fichiers générés dans `Build`, à côté des fichiers objets, j’ai trouvé notamment :

```
Build\Obj\Debug-Windows\MonEssai\main.obj
Build\Obj\Debug-Windows\MonEssai\main.obj.d
Build\Obj\Debug-Windows\MonEssai\main.obj.jenga_sig
```

Le fichier `main.obj.jenga_sig` contient une signature :

```

ef5d3bf7a098b14d7b7fae328de846031edbb057aac230961157420131b66aea
```

On voit donc que Jenga conserve une signature associée au fichier objet généré. Lors d’une nouvelle construction, il peut comparer l’état actuel avec les informations conservées et déterminer si le fichier doit être recompilé.

Dans notre deuxième construction, cette vérification a conduit Jenga à afficher `All files up to date` pour les 6 projets.

## Conclusion

La différence entre les deux temps vient donc principalement du fait que la première construction devait réellement construire les 6 projets après le nettoyage, alors que la deuxième pouvait réutiliser les résultats déjà présents.

**Construction à froid : 38,99 s**  
**Construction à chaud : 2,66 s**  
**Écart : 36,33 s**

