# Exercice 8 — Debug contre Release

## 1. Mesures

J'ai construit le même projet `MonEssai` avec les deux configurations Debug et Release.

### Debug

Commande utilisée :

```
jenga build --project MonEssai --config Debug
```

Résultat :

- Temps de construction : **5,50 s**
- Taille du binaire : **148 788 octets**
- Fichier obtenu : `Build\Bin\Debug-Windows\MonEssai\MonEssai.exe`

### Release

Commande utilisée :

```
jenga build --project MonEssai --config Release
```

Résultat :

- Temps de construction : **55,24 s**
- Taille du binaire : **117 679 octets**
- Fichier obtenu : `Build\Bin\Release-Windows\MonEssai\MonEssai.exe`

## 2. Comparaison
````
| Configuration | Temps | Taille         |
| Debug         | 5,50 s| 148 788 octets |
| Release       | 55,24s| 117 679 octets |
````

La différence de temps est de **49,74 secondes**. Donc dans mon test Release a pris beaucoup plus de temps.

Pour la taille, le fichier Release est plus petit de **31 109 octets**.

## 3. Les lignes dans les fichiers `.jenga`

Dans les fichiers des dépendances j'ai trouvé les configurations suivantes.

Pour Debug :

```
with filter("config:Debug"):
    defines(["_DEBUG", "DEBUG", ...])
    optimize("Off")
    symbols(True)
```

Pour Release :

```
with filter("config:Release"):
    defines(["NDEBUG", ...])
    optimize("Speed")
    symbols(False)
```

Dans `Nkentseu.jenga`, on trouve aussi :

```
configurations(["Debug", "Release"])
```

Cette ligne permet d'avoir les deux configurations.

## 4.

On peut voir que les paramètres ne sont pas les mêmes entre Debug et Release.

En Debug, l'optimisation est sur `Off` et les symboles sont activés avec `symbols(True)`.

En Release, l'optimisation est sur `Speed` et les symboles sont désactivés avec `symbols(False)`.

Dans mon cas, le binaire Release est plus petit mais sa construction a pris beaucoup plus de temps. Je pense que cela vient des paramètres de compilation différents entre les deux configurations.
