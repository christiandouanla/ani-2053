# Exercice 6 — Les deux erreurs de dépendance

## 1. 

Pour faire le test, j'ai utilier mon projet `MonEssai` et le projet `NKMath`.

Dans `MonEssai.jenga`, j'ai ajouter les deux dépendances :

```
dependson([
    "NKMath",
])

links([
    "NKMath",
])
```

Dans `main.cpp`, j'utilise une fonction de NKMath :

```
#include "NKMath/NKMath.h"
#include <iostream>

using namespace nkentseu::math;

int main()
{
    float valeur = NkSqrt(16.0f);

    std::cout << valeur << std::endl;

    return 0;
}
```

J'ai aussi ajouté les chemins d'inclusion nécessaires pour que les fichiers de NKMath  retrouvent leurs dépendances.
``` includedirs([
    "../../Kernel/Foundation/NKMath/src",
    "../../Kernel/Foundation/NKCore/src",
    "../../Kernel/Foundation/NKPlatform/src",
    "../../Kernel/Foundation/NKMemory/src",
    "../../Kernel/Foundation/NKContainers/src",
])
 ```

Avec `dependson` et `links`, le build a donné. Jenga a construit les 6 projets dans l'ordre ci :

1. NKPlatform
2. NKCore
3. NKMemory
4. NKContainers
5. NKMath
6. MonEssai

Le résultat était :

```
BUILD COMPLETED
Projects Built:  6/6
Time:           9.50s
Status:         ✓ SUCCESS
```



# 2. Test avec `dependson` retiré

Pour le premier test, j'ai retiré seulement :

```
dependson([
    "NKMath",
])
```

J'ai laissé `links(["NKMath"])`.

J'ai ensuite lancé :

```
jenga build --project MonEssai
```

Jenga a affiché :

```
Build Order (1 projects):
  1. MonEssai [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:/msys64/ucrt64/bin/ld: cannot find -lNKMath: No such file or directory                     ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\MonEssai\MonEssai.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 4.38s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         1
Time:           4.38s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ MonEssai
  ```

### donc quand j'enlève `dependson`, Jenga ne sait plus qu'il doit construire `NKMath` avant `MonEssai`.

### Le changement est surtout visible dans le **Build Order** : on passe de 6 projets à seulement 1.


# 3. Test avec `dependson` présent mais `links` retiré

Pour le deuxième test, j'ai remis :

```
dependson([
    "NKMath",
])
```

et j'ai retiré seulement :

```
links([
    "NKMath",
])
```

J'ai ensuite relancé :

```
jenga build --project MonEssai
```

Cette fois, jenga a affiché :

```
Build Order (6 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) →
  6. MonEssai [CONSOLE_APP] (depends: NKMath)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.14s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.15s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.72s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.80s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MonEssai\MonEssai.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           8.50s
Status:         ✓ SUCCESS
```

### donc quand j'enlève `links` il y'a pas d'erreur.

### Donc je ne peux pas dire que `links` provoque forcément une erreur dans ce cas, puisque ce n'est pas ce qui est 

### Par contre, `dependson` a  eu un effet sur le Build Order.



# 4- ce que j'observe
### Cela montre que dependson intervient dans l'ordre de construction, tandis que links concerne le lien avec la bibliothèque. (dependson indique qu'un projet doit être construit avant l'autre, alors que links sert à ajouter une bibliothèque)