# exercice 6 — le conflit provoqué

j’ai utilisé deux clones du même dépôt. j’ai modifié la même ligne du fichier `fichier.txt` dans les deux clones.

## 1. premier clone : modification et push

le premier clone a été modifié puis poussé sur le dépôt 

```
[master 1a0e828] modifie la ligne des deux
1 file changed, 0 insertions(+), 0 deletions(-)
```

le push a réussi :

```
To https://github.com/christiandouanla/git-exo6.git
11ae793..1a0e828  master -> master
```

## 2. deuxième clone : modification et refus du push

dans le deuxième clone, j’ai aussi modifié la même ligne puis créé un commit.

```
[master ee20a80] modifie la ligne des deux
1 file changed, 0 insertions(+), 0 deletions(-)
```

le push a ensuite été refusé car le dépôt contenait déjà le commit du premier clone.

```
To https://github.com/christiandouanla/git-exo6.git
! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'https://github.com/christiandouanla/git-exo6.git'
hint: Updates were rejected because the remote contains work that you do not
have locally. This is usually caused by another repository pushing to
the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

## 3. pull et conflit

j’ai fait un `git pull` pour récupérer la modification du premier clone.

```
From https://github.com/christiandouanla/git-exo6
11ae793..1a0e828  master     -> origin/master
warning: Cannot merge binary files: fichier.txt (HEAD vs. 1a0e8284f225bb9eb76155ddda1f5534736a7acc)
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
Automatic merge failed; fix conflicts and then commit the result.
```

le conflit concernait donc le `fichier.txt`.

## 4. vérification du conflit

```
On branch master
Your branch and 'origin/master' have diverged,
and have 1 and 1 different commits each, respectively.

You have unmerged paths.

Unmerged paths:
  both modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
```

## 5. résolution du conflit

j’ai marqué le fichier comme s'il etait bon avec `git add fichier.txt`.

le statut a ensuite indiqué :

```
All conflicts fixed but you are still merging.
(use "git commit" to conclude merge)
```

j’ai terminé la résolution avec un commit :

```
[master 48d2550] resout le conflit
```

## 6. push final

le dernier push a réussi :

```t
To https://github.com/christiandouanla/git-exo6.git
1a0e828..48d2550  master -> master
```

## conclusion

le conflit a bien été provoqué entre les deux clones. le deuxième push a d’abord été refusé, puis le `git pull` a provoqué le conflit. j’ai ensuite résolu le conflit, fait le commit de résolution et poussé le résultat sur le dépôt distant.