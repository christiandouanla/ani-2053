# Exercice 8 — Debug vs Release

## 1. Construction en Debug

Avant les mesures, j'ai nettoyé les fichiers générés avec :

```
jenga clean
```

J'ai ensuite construit `MonEssai` en configuration Debug :

```
jenga build --project MonEssai --config Debug
```

Les 6 projets ont été réellement construits :
````
| Projet | Temps |
|        |          |
| NKPlatform | 4,33 s |
| NKCore | 3,26 s |
| NKMemory | 5,02 s |
| NKContainers | 8,06 s |
| NKMath | 8,95 s |
| MonEssai | 4,08 s |
| **Total** | **33,71 s** |
````
Résultat :

```
Projects Built:  6/6
Time:           33.71s
Status:         ✓ SUCCESS
```

J'ai ensuite mesuré la taille de l'exécutable avec :

```
(Get-Item ".\Build\Bin\Debug-Windows\MonEssai\MonEssai.exe").Length
```

Résultat :

```
148788
```

La taille du fichier Debug est donc de **148 788 octets**.



## 2. Construction en Release

J'ai ensuite construit le même projet en configuration Release :

```
jenga build --project MonEssai --config Release
```

Les 6 projets ont également été réellement construits :
````
| Projet | Temps |
|        |       |
| NKPlatform | 4,57 s |
| NKCore | 3,37 s |
| NKMemory | 6,49 s |
| NKContainers | 9,95 s |
| NKMath | 9,60 s |
| MonEssai | 4,25 s |
| **Total** | **38,23 s** |
````
Résultat :

```
Projects Built:  6/6
Time:           38.23s
Status:         ✓ SUCCESS
```

J'ai ensuite mesuré la taille de l'exécutable avec :

```
(Get-Item ".\Build\Bin\Release-Windows\MonEssai\MonEssai.exe").Length
```

Résultat :

```
117679
```

La taille du fichier Release est donc de **117 679 octets**.

---

## 3. Comparaison

| Configuration | Temps de construction | Taille de l'exécutable |
|---|---:|---:|
| Debug | **33,71 s** | **148 788 octets** |
| Release | **38,23 s** | **117 679 octets** |

### Différence de temps

```
38,23 − 33,71 = 4,52 s
```

La construction Release a donc pris **4,52 s de plus** que la construction Debug.

### Différence de taille

```
148 788 − 117 679 = 31 109 octets
```

L'exécutable Release est donc **31 109 octets plus petit** que l'exécutable Debug.

---

## 4. Les lignes du `.jenga` qui expliquent les différences

Dans les fichiers `.jenga` des projets construits, on trouve notamment :

### Configuration Debug

```
with filter("config:Debug"):
    defines([...])
    optimize("Off")
    symbols(True)
```

La ligne :

```
optimize("Off")
```

indique que les optimisations sont désactivées en Debug. Le compilateur a donc moins de travail d'optimisation à effectuer.

La ligne :

```
symbols(True)
```

indique que les symboles sont conservés pour la configuration Debug. Cela contribue à avoir un exécutable plus volumineux.

### Configuration Release

```
with filter("config:Release"):
    defines([...])
    optimize("Speed")
    symbols(False)
```


## 5. Configuration du workspace

Dans `Nkentseu.jenga`, les deux configurations sont déclarées avec :

```
configurations(["Debug", "Release"])
```

Cette ligne explique que le workspace dispose des configurations Debug et Release.



## Conclusion

chez moi, la configuration Debug a été construite en **33,71 s** et produit un exécutable de **148 788 octets**.

La configuration Release a été construite en **38,23 s** et produit un exécutable de **117 679 octets**.

Release prend donc **4,52 s de plus**, mais son exécutable est **31 109 octets plus petit**.

Pour le temps de construction, le mode Debug n’utilise pas d’optimisation, contrairement au mode Release. C’est pourquoi Release peut prendre un peu plus de temps à construire.

Pour la taille du fichier, les symboles de débogage sont activés en Debug mais pas en Release. C’est pourquoi le fichier Debug est plus gros.
