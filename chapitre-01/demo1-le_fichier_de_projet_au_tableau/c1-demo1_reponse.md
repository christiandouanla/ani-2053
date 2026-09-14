# Démo 1 — Le fichier de projet au tableau

**Fichier présenté :** `Kernel/AI/NKSpeech/NKSpeech.jenga`

## 1. Ce que déclare le fichier

Le fichier commence par les imports :

```
from Jenga import *
from jengaconfig import *
```

Ensuite, le projet est déclaré avec :

```
with project("NKSpeech"):
```

Cela indique que le fichier décrit le projet nommé `NKSpeech`.

Le langage utilisé est C++ et le dialecte demandé est C++17 :

```
language("C++")
cppdialect("C++17")
```

Le projet indique également :

```
location(".")
```

Le `.` indique que la localisation utilisée est relative au dossier du fichier `.jenga`. Les chemins relatifs du projet sont donc calculés à partir de cet emplacement.

## 2. Les dépendances

La partie principale des dépendances est :

```
nkentseudependson(
    ["NKCore", "NKPlatform", "NKMemory", "NKContainers", "NKMath", "NKLogger"],
    selfexport="NKSpeech",
    extra_includes=["src"],
)
```

`nkentseudependson` est une fonction spécifique à Nkentseu. Le cours explique qu'elle permet de gérer les dépendances du projet et de produire notamment les chemins d'inclusion, les liens et les dépendances de construction.

Ici, NKSpeech dépend donc de :

- NKCore
- NKPlatform
- NKMemory
- NKContainers
- NKMath
- NKLogger

Le paramètre `extra_includes=["src"]` ajoute également `src` aux chemins d'inclusion.

Le paramètre `selfexport="NKSpeech"` est une partie que je n'avais pas encore complètement comprise lors de l'exercice 4.

## 3. Les fichiers sources

Les fichiers sources sont déclarés avec :

```
files([
    "src/NKSpeech/**.cpp",
    "src/NKSpeech/**.h",
])
```

Cela indique à Jenga de prendre les fichiers `.cpp` et `.h` présents dans `src/NKSpeech` et ses sous-dossiers.

Le `**` permet donc de descendre récursivement dans les dossiers.

## 4. Où sont placés les fichiers construits ?

Le fichier définit ensuite :

```
objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
```

`objdir` indique où placer les fichiers objets intermédiaires.

`targetdir` indique où placer le résultat final de la construction.

Dans le cas de NKSpeech, la sortie est donc placée dans un répertoire `Build/Lib`.

## 5. Les filtres

Le fichier contient plusieurs filtres.

Par exemple :

```
with filter("system:Windows && options:windows-runtime=uwp"):
```

Ce bloc s'applique lorsque le système est Windows et que l'option Windows Runtime est UWP.

Il modifie alors les répertoires de sortie pour utiliser une version `-uwp`.

Un autre filtre est :

```
with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
    usetoolchain(TC_WINDOWS)
```

Ici, le choix du toolchain dépend des conditions indiquées dans le filtre.

Enfin :

```
with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
    usetoolchain("xbox-clang")
```

Ce bloc choisit un autre toolchain lorsque les conditions correspondantes sont remplies.

Les filtres permettent donc au même fichier `.jenga` de modifier certains paramètres selon la plateforme ou les options utilisées.

## 6. Où est décidé que NKSpeech est une bibliothèque statique ?



Dans `NKSpeech.jenga`, il n'y a pas de ligne explicite :

```
staticlib()
```

Pourtant, lorsque j'ai construit le projet avec Jenga, le résultat indiquait :

```
NKSpeech [STATIC_LIB]
```

Le fichier produit était également placé dans :

```
Build\Lib\...
```

La décision de considérer NKSpeech comme une bibliothèque statique ne se trouve donc **pas sous la forme d'un `staticlib()` écrit directement dans ce fichier**.

Dans ce projet, le type est déterminé par la configuration utilisée par Nkentseu/Jenga, notamment à travers les mécanismes utilisés par `nkentseudependson`.

C'est une différence importante avec un projet où le type serait déclaré directement avec `staticlib()`.

Le cours précise justement que, dans l'exemple de `NKMath`, le fichier `.jenga` ne contient pas explicitement `staticlib()` : le type vient du mécanisme partagé utilisé par le projet. Le type peut ensuite être vérifié avec `jenga info` ou lors de la construction. 

Pour NKSpeech, ma vérification avec Jenga a donné :

```
NKSpeech [STATIC_LIB]
```

Donc je ne dirais pas que la ligne `nkentseudependson` signifie simplement « créer une bibliothèque statique ». Je dirais plutôt que **le type final du projet est déterminé par la configuration Nkentseu/Jenga et vérifié par la sortie de Jenga**.

## 7. Résumé  au tableau

Le fichier `NKSpeech.jenga` déclare donc principalement :

- le projet `NKSpeech` ;
- le langage C++17 ;
- sa localisation ;
- ses dépendances ;
- ses fichiers `.cpp` et `.h` ;
- ses répertoires de fichiers objets et de sortie ;
- des règles différentes selon la plateforme ;
- les toolchains utilisés selon les conditions.

Le point que je retiens surtout est qu'un `.jenga` ne contient pas forcément toutes les informations sous une forme directe. Certaines informations sont déléguées à des fonctions ou à la configuration du workspace.

