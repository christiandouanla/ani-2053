# demo 1 — le graphe au tableau

## dépôt utilisé

j’ai utilisé le dépôt réel **Nkentseu**.


## les branches

j’ai utilisé la commande :

```
git branch -a
```

elle a montré notamment :

```
main
sorcier
remotes/origin/HEAD -> origin/main
remotes/origin/docs/roadmaps
remotes/origin/feat/gemcrush
remotes/origin/feat/ilyana-pdf
remotes/origin/feat/nkcode-ai-codeblocks
remotes/origin/feat/nkcode-panneaux
remotes/origin/feat/nkcode-pdf-portage-linux
remotes/origin/feat/nkcode-usage-fixes
remotes/origin/feat/nkref
remotes/origin/feat/noge-inventaire
remotes/origin/fix/nktraits-portable
remotes/origin/main
```

## trouver une fusion

j’ai utilisé :

```
git log --oneline --merges --all
```

une des fusions trouvées est :

```
7c3e84a0 Merge remote-tracking branch 'origin/main'
```

pour vérifier cette fusion :

```
git show --no-patch --format=fuller 7c3e84a
```

résultat :

```
commit 7c3e84a0b67e857070caeedcf096e42edfea1355
Merge: 4c7d66b5 cc41ca45
Author:     LeTeguis teuguiasederis@gmail.com
AuthorDate: Fri Aug 28 22:15:51 2026 +0100
Commit:     LeTeguis teuguiasederis@gmail.com
CommitDate: Fri Aug 28 22:15:51 2026 +0100

Merge remote-tracking branch 'origin/main'
```

le commit de fusion a donc deux parents :

```
4c7d66b5
cc41ca45
```

cela a aussi été vérifié avec :

```
git rev-list --parents -n 1 7c3e84a
```

résultat :

```
7c3e84a0b67e857070caeedcf096e42edfea1355 4c7d66b529ac87182652e957d085f4ced722c79c cc41ca45163ebb8718ede5e385ec876054dd1a6b
```

## les deux côtés de la divergence

le premier parent était :

```
git show --no-patch --oneline 4c7d66b5
```

```
4c7d66b5 Distribution : refuser de livrer un exe dont une DLL importee manque
```

le deuxième parent était :

```
git show --no-patch --oneline cc41ca45
```

```
cc41ca45 GemCrush : le jeu complet -- menu, aventure 30 niveaux, 3 modes, audio synthetise (#84)
```

le graphe montre donc que les deux historiques se rejoignent au commit `7c3e84a0`.

## le graphe avec git

j’ai utilisé :

```
git log --oneline --graph --decorate --all -15
```

le résultat est :

```
* 6fb634fc (HEAD -> sorcier, origin/main, origin/HEAD, main) NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
* 860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
* c1c815ff CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)
* addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
* 43285010 (origin/fix/nktraits-portable) NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
* 0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication
*   7c3e84a0 Merge remote-tracking branch 'origin/main'
|\
| * cc41ca45 GemCrush : le jeu complet -- menu, aventure 30 niveaux, 3 modes, audio synthetise (#84)
* | 4c7d66b5 Distribution : refuser de livrer un exe dont une DLL importee manque
* | ad0779cb NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur
* | 5fc605de Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux
* | 56b0ed67 wiki : les mesures Vulkan sont CONFIRMEES par contre-verification -- et un 5e piege, celui qui a permis le desaccord
* | ecfb57cb wiki maintenabilite : quelle garde rougirait AUJOURD HUI -- reponse mesuree, et c est << aucune ici >>
* | b4cdf3cc wiki pieges : l avertissement sur CreateWithFallback est MAINTENU -- mesure a l appui -- et gagne le corollaire sur les bancs
* | 92cf625a wiki : je retire << 18 shaders casses >> -- c etait mon cache, pas le depot ; + les 4 pieges d instrument et la validation de G1
```

on voit bien le point de divergence avec les deux lignes `| *` et `* |`, puis leur réunion au niveau de `7c3e84a0`.

## graphe à reproduire au tableau



```
          cc41ca45
             |
             |
             +------\
                    |
                    v
                 7c3e84a0
                    ^
                    |
             +------/
             |
          4c7d66b5
             |
             |
          ad0779cb
```

le commit `7c3e84a0` correspond à la fusion visible dans le terminal.

## vérification de la fusion

j’ai aussi vérifié les fichiers apportés par cette fusion avec :

``
git diff-tree --cc --stat 7c3e84a
```

le résultat indique :

```
21 files changed, 7397 insertions(+)
```

la fusion a notamment apporté les fichiers du projet GemCrush et une modification de `Nkentseu.jenga`.

## conclusion

le graphe montre deux historiques qui ont divergé à partir de `4c7d66b5` et `cc41ca45`.

ils sont ensuite réunis par le commit de fusion `7c3e84a0`.

le graphe obtenu avec `git log --graph` correspond donc au graphe que j’ai représenté au tableau.