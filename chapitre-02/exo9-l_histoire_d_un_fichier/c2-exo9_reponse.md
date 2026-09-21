# c2-exo9 — l’histoire d’un fichier

## fichier choisi

j’ai choisi le fichier :

`Engine/Noge/src/Noge/Core/NkApplication.cpp`


### 1. histoire complète du fichier

commande utilisée :

```
git log --follow --oneline -- Engine/Noge/src/Noge/Core/NkApplication.cpp
```

sortie :

```
3b79729b NKRenderer : Present() avant EndFrame() sur les 3 sites inverses, et le commentaire qui enseignait l inverse
7bb1f37f fix(nogee): crash demarrage — ODR layout DEVMODE/UNICODE (NkWin32Window), double OnAttach, garde mUIReady + thumbnails paresseux AssetBrowser (boot 4,2s -> 0,41s)
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
d4fce7ee feat(render): grille infinie reutilisable + fix ombres GL (glClipControl/clipZ01) + fix freeze DX11 (ResizeBuffers/command list) + NkInput cross-platform + cap FPS/vsync + pool object-UBO dynamique + ombres instanciees ; consolidation WIP multi-modules (NKCode, Noge, ...) (#19)
d557314e update
f1e536a5 refactor 001
8737e282 Begin clearing and restructured file
```

cela montre les différents commits qui ont participé à l’histoire du fichier. 

### 2. création du fichier

pour vérifier la création du fichier, j’ai utilisé :

```
git show d557314e -- Engine/Noge/src/Noge/Core/NkApplication.cpp
```

sortie importante :

```
commit d557314e707baf17e53029b9d9cae2c5164dd417

Author: LeTeguis
Date:   Tue May 5 20:04:22 2026 +0100

    update

new file mode 100644
...
@@ -0,0 +1,335 @@
```

le fichier a donc été créé dans ce commit avec 335 lignes. fileciteturn0file0L30-L58

### 3. premier gros changement

j’ai vérifié le commit :

```
git show --stat bdda350a -- Engine/Noge/src/Noge/Core/NkApplication.cpp
```

sortie :

```
Engine/Noge/src/Noge/Core/NkApplication.cpp | 632 ++++++++++++++--------------
1 file changed, 323 insertions(+), 309 deletions(-)
```

ce commit correspond à un reformatage avec clang-format.

pour voir son message complet :

```
git show --no-patch --format=fuller bdda350a
```

sortie :

```
commit bdda350a054705f217f0daf5a54ab02bcb9c56ef
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Jul 9 16:53:52 2026 +0100

    style: reformatage clang-format repo-wide (Kernel/Engine/Applications)

    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    1748 fichiers (.h/.cpp/.inl/.mm).
```

le fichier a donc beaucoup changé pendant ce reformatage : 323 lignes ajoutées et 309 supprimées. 

### 4. autre changement important

commande :

```
git show --stat d4fce7ee -- Engine/Noge/src/Noge/Core/NkApplication.cpp
```

sortie :

```
Engine/Noge/src/Noge/Core/NkApplication.cpp | 120 ++++++++++++----------------
1 file changed, 51 insertions(+), 69 deletions(-)
```

message du commit :

```
feat(render): grille infinie reutilisable + fix ombres GL (glClipControl/clipZ01) + fix freeze DX11 (ResizeBuffers/command list) + NkInput cross-platform + cap FPS/vsync + pool object-UBO dynamique + ombres instanciees ; consolidation WIP multi-modules (NKCode, Noge, ...) (#19)
```

### 5. vérification des changements

pour vérifier les modifications et les messages, j’ai aussi utilisé :

```
git show --stat d557314e -- Engine/Noge/src/Noge/Core/NkApplication.cpp
git show --stat bdda350a -- Engine/Noge/src/Noge/Core/NkApplication.cpp
git show --stat d4fce7ee -- Engine/Noge/src/Noge/Core/NkApplication.cpp
```

les résultats principaux sont :

```
d557314e
1 file changed, 335 insertions(+)

bdda350a
1 file changed, 323 insertions(+), 309 deletions(-)

d4fce7ee
1 file changed, 51 insertions(+), 69 deletions(-)
```

## conclusion

l’histoire du fichier commence avec sa création dans le commit `d557314e` avec 335 lignes.

ensuite, il a notamment été fortement modifié par le reformatage clang-format du commit `bdda350a`, puis par les changements liés au rendu et aux différents modules dans `d4fce7ee`.

les messages des commits donnent les raisons des changements : reformatage du code, corrections de problèmes au démarrage, changements liés au rendu, aux ombres, à DX11, à l’input et aux performances.

le fichier a donc beaucoup évolué depuis sa création et son histoire montre plusieurs types de changements : création, reformatage et modifications fonctionnelles.