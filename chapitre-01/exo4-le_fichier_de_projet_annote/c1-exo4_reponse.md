# Exercice 4
Fichier choisi : ``Kernel\AI\NKSpeech\NKSpeech.jenga``
#!/usr/bin/env python3
## Indique que le fichier peut être exécuté directement avec Python 3.

# -*- coding: utf-8 -*-
## Définit l'encodage du fichier en UTF-8.

"""
NKSpeech — parole from-scratch (ASR + TTS) pour NKAI, C++17.
Brique 1 livree : NkAudioFeatures (MFCC / log-Mel). ASR/TTS = scaffold (spec).
Namespace : nkentseu::ai. Deps Foundation seulement (+ NKLogger).
"""
## Description du projet.

from Jenga import *
## Importe les éléments de Jenga utilisés dans le fichier.

from jengaconfig import *
## Importe les éléments de configuration utilisés dans le fichier.

with project("NKSpeech"):
## Déclare le projet NKSpeech. Le type du projet est STATIC_LIB, ce qui est confirmé par la sortie de jenga build.

    language("C++")
## Indique que les fichiers du projet doivent être traités comme du C++.

    cppdialect("C++17")
## Indique que la compilation utilise le standard C++17.

    location(".")
## Indique que le dossier du projet est le dossier courant du fichier .jenga. Les chemins relatifs du projet sont donc calculés à partir de ce dossier.

    nkentseudependson(
## Utilise la fonction propre à Nkentseu qui permet de gérer les dépendances du projet.

        ["NKCore", "NKPlatform", "NKMemory", "NKContainers", "NKMath", "NKLogger"],
## Indique les dépendances directes de NKSpeech.

        selfexport="NKSpeech",
## ?

        extra_includes=["src"],
## Ajoute le dossier src aux chemins d'inclusion supplémentaires.

    )
## Fin de la déclaration des dépendances.

    files([
## Déclare les fichiers qui appartiennent au projet.

        "src/NKSpeech/**.cpp",
## Inclut les fichiers sources .cpp présents dans src/NKSpeech et ses sous-dossiers grâce à **.

        "src/NKSpeech/**.h",
## Inclut les fichiers d'en-tête .h présents dans src/NKSpeech et ses sous-dossiers.

    ])
## Fin de la liste des fichiers.

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
## Définit le dossier dans lequel les fichiers objets sont placés. Ici, pour cette construction, le chemin correspond à Build/Obj/Debug-Windows/NKSpeech.

    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
## Définit le dossier où la bibliothèque construite est placée. La sortie du build confirme ici Build/Lib/Debug-Windows/NKSpeech.lib.

    with filter("system:Windows && options:windows-runtime=uwp"):
## Applique les lignes suivantes lorsque le système est Windows avec l'option UWP.

        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
## Pour cette configuration, les fichiers objets sont placés dans un dossier spécifique à UWP.

        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")
## Pour cette configuration, la bibliothèque est placée dans un dossier de sortie spécifique à UWP.

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
## Applique les lignes suivantes à Windows lorsque UWP n'est pas utilisé et que la plateforme n'est ni Xbox Series ni Xbox One.

        usetoolchain(TC_WINDOWS)
## Indique d'utiliser la toolchain Windows pour cette configuration.

    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
## Applique la configuration lorsque le système est UWP, ou lorsque Windows utilise l'option UWP.

        usetoolchain("xbox-clang")
## Indique d'utiliser la toolchain appelée xbox-clang pour cette configuration.

## Tests : aucun bloc test() ou testfiles() n'apparaît dans ce fichier.
