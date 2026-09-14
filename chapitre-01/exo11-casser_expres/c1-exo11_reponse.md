# Exercice 11 — Casser exprès

## Manipulation

J’ai introduit volontairement une faute de syntaxe dans le fichier `Kernel/Foundation/NKMath/src/NKMath/NkFunctions.cpp`.

J’ai supprimé le point-virgule à la fin de cette instruction :

```
return static_cast<float32>(floor(x))
```

J’ai ensuite lancé :

```
jenga rebuild --target NKMath --config Debug
```

## Résultat de la construction

Jenga a calculé l’ordre de construction suivant :

1. `NKPlatform`
2. `NKCore`
3. `NKMemory`
4. `NKContainers`
5. `NKMath`

Les quatre premiers projets ont été construits correctement :

- `NKPlatform` : succès — 2,46 s
- `NKCore` : succès — 1,76 s
- `NKMemory` : succès — 2,86 s
- `NKContainers` : succès — 4,11 s

La construction s’est ensuite arrêtée sur `NKMath`.

Jenga a indiqué l’erreur suivante dans `NkFunctions.cpp` :

```
error: expected ';' after return statement
```

L'erreur se trouvait à la ligne 62, à l'endroit où j'avais supprimé le `;`.

Le résultat final était :

```
Projects Built:  4/5
Failed:          1
Errors:          2
Time:            17.11s
Status:          FAILURE
```


Cette manipulation m’a permis de voir concrètement l’ordre de construction des dépendances. `NKPlatform` est construit avant `NKCore`, puis `NKMemory`, puis `NKContainers`, et enfin `NKMath`.

L'erreur dans `NKMath` n'a donc été rencontrée qu'après la construction des projets dont `NKMath` dépend. Cela correspond au principe du cours selon lequel l'ordre de construction est calculé à partir des dépendances. fileciteturn10file0L455-L461

Le message `expected ';' after return statement` permet également d'identifier directement la cause de l'échec : il manquait le point-virgule après l'instruction `return`.

## Remise en état

Après le test, j’ai remis le point-virgule dans `NkFunctions.cpp` :

```
return static_cast<float32>(floor(x));
```
