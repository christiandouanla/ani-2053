# Exercice 10 — Le graphe d’un module

## 1. Dépendances directes de NKCanvas

J’ai ouvert le fichier `Kernel/Runtime/NKCanvas/NKCanvas.jenga`.

Dans ce fichier, les dépendances de `NKCanvas` sont déclarées avec `nkentseudependson` :

```
_canvasDeps = [
    "NKWindow",
    "NKFont",
    "NKImage",
    "NKStream",
    "NKTime",
    "NKGlad",
    "NKThreading"
]
```

Donc les dépendances directes de **NKCanvas** sont :

- NKWindow
- NKFont
- NKImage
- NKStream
- NKTime
- NKGlad
- NKThreading

Le fichier utilise ensuite `nkentseudependson` avec cette liste. fileciteturn22file0L39-L69

## 2. Dépendances des dépendances

J’ai ensuite lancé la construction de `NKCanvas` pour voir l’ordre de construction et les dépendances utilisées.

Le résultat donne :

- **NKWindow** dépend de NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading et NKTime.
- **NKFont** dépend de NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform et NKThreading.
- **NKImage** dépend de NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream et NKThreading.
- **NKStream** dépend de NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform et NKThreading.
- **NKTime** dépend de NKContainers, NKCore, NKLogger, NKMemory, NKPlatform et NKThreading.
- **NKGlad** n’a pas de dépendance affichée.
- **NKThreading** dépend de NKContainers, NKCore, NKMemory et NKPlatform.

Le cours explique que l’ordre de construction est calculé à partir des dépendances et permet donc de savoir quels projets doivent être construits avant un autre. 

## 3. Graphe sur deux niveaux

Le graphe obtenu peut être représenté ainsi :

```
                              NKCanvas
                                  |
       _______________________________________________________
        |           |      |      |      |         |      
    NKWindow      NKFont NKImage NKStream NKTime NKGlad NKThreading     |      |      |      |         |
        |           |      |      |      |         |
        |           |      |      |      |         |
        |__________ __________________________________________
                    |
       ______________________________________________________
       |            |            |            |
   NKContainers   NKCore    NKFileSystem   NKLogger
       |            |            |            |
       ___________________________________________________
                    |
                  NKMath
                    |
                NKMemory
                    |
                NKPlatform
```

Ce graphe est simplifié car plusieurs projets sont utilisés par plusieurs autres projets. Je ne les compte donc pas plusieurs fois.

## 4. Nombre de projets à construire avant NKCanvas

La construction de `NKCanvas` m’a donné :

```
Build Order (16 projects):

1. NKPlatform
2. NKGlad
3. NKCore
4. NKMemory
5. NKContainers
6. NKMath
7. NKThreading
8. NKLogger
9. NKFont
10. NKFileSystem
11. NKTime
12. NKStream
13. NKEvent
14. NKImage
15. NKWindow
16. NKCanvas
```

Il y a donc **16 projets au total** dans le Build Order.

Comme `NKCanvas` est le dernier, il faut construire :

**16 - 1 = 15 projets avant NKCanvas.**

### Conclusion

**Il faut donc construire 15 projets avant NKCanvas.**

Cette construction montre aussi que les dépendances ne forment pas seulement une simple liste : plusieurs projets ont des dépendances communes, ce qui forme un graphe de dépendances.