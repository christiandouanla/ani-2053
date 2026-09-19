# c2-exo7 — le conflit qui n’en est pas un

## modifications

deux personnes travaillent sur le même fichier `fichier.txt`, mais ont modifier deux endroits différents

la première personne modifie la première partie du fichier

le commit etait :

```
[master 1fdd0dd] modifie la premiere partie
1 file changed, 1 insertion(+), 1 deletion(-)
```

puis elle pousse son commit :

```
To https://github.com/christiandouanla/git-exo7.git
602183a..1fdd0dd  master -> master
```

la deuxième personne modifie une autre partie du même fichier.

le commit etait :

```
[master 2548dcb] modifie la deuxieme partie
1 file changed, 1 insertion(+), 1 deletion(-)
```

ensuite elle fait un `git pull`.

git assemble automatiquement les deux modifications

git demande seulement de terminer l'opération :

```
All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
       modified:   fichier.txt
```

on termine alors avec le commit :

```
[master 57b63fe] assemble les deux modifications
```

après ca :

```
On branch master
Your branch is ahead of 'origin/master' by 2 commits.

nothing to commit, working tree clean
```

enfin, les modifications sont envoyées sur github :

```
To https://github.com/christiandouanla/git-exo7.git
1fdd0dd..57b63fe  master -> master
```

## conclusion

ici, les deux personnes ont modifié le même fichier mais à deux endroits différents. git a donc pu assembler les deux modifications automatiquement, sans demander de résoudre un conflit