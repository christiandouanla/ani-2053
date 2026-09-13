
# Exercice 4

**Fichier choisi :** `Kernel\AI\NKSpeech\NKSpeech.jenga`

#!/usr/bin/env python3
## ?

# -*- coding: utf-8 -*-
## Définit l'encodage du fichier en UTF-8.

"""
NKSpeech — parole from-scratch (ASR + TTS) pour NKAI, C++17.
Brique 1 livree : NkAudioFeatures (MFCC / log-Mel). ASR/TTS = scaffold (spec).
Namespace : nkentseu::ai. Deps Foundation seulement (+ NKLogger).
"""
## Description du projet.

from Jenga import *
## Importe Jenga.

from jengaconfig import *
## Importe la configuration.

with project("NKSpeech"):
## Nom du projet. Type : ?

    language("C++")
## Le langage utilisé est C++.

    cppdialect("C++17")
## Le standard utilisé est C++17.

    location(".")
## Emplacement du projet.

    nkentseudependson(
## Dépendances du projet.

        ["NKCore", "NKPlatform", "NKMemory", "NKContainers", "NKMath", "NKLogger"],
## Les dépendances sont NKCore, NKPlatform, NKMemory, NKContainers, NKMath et NKLogger.

        selfexport="NKSpeech",
## ?

        extra_includes=["src"],
## ?

    )
## Fin de la déclaration des dépendances.

    files([
## Fichiers du projet.

        "src/NKSpeech/**.cpp",
## Fichiers sources .cpp.

        "src/NKSpeech/**.h",
## Fichiers sources .h.

    ])
## Fin de la liste des fichiers.

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
## ?

    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
## ?

    with filter("system:Windows && options:windows-runtime=uwp"):
## Filtre pour Windows.

        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
## ?

        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")
## ?

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
## Filtre pour Windows.

        usetoolchain(TC_WINDOWS)
## ?

    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
## Filtre pour UWP ou Windows.

        usetoolchain("xbox-clang")
## ?

## Tests : ?