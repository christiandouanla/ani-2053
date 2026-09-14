# Exercice 12 — Réveiller les tests

## 1. Ligne qui désactive la compilation des tests

Dans le fichier `Nkentseu.jenga`, j’ai trouvé :

```
dutc(enable=True)
```

Cette ligne désactive la compilation des tests dans le workspace. Le cours indique également que `dute(enable=True)` désactive leur exécution par défaut. 

Pour cet exercice, je n’ai pas supprimé ces lignes. J’ai utilisé l’option `--force` de la commande `jenga test` pour passer outre cette désactivation pour cette exécution.

## 2. Suite de tests lancée

J’ai lancé la suite de tests de NKMath avec :

```
jenga test --project NKMath_Tests --config Debug --force
```

Jenga a identifié la suite :

```
NKMath_Tests [TEST_SUITE]
```

La construction a eu besoin de 7 projets, dont `NKMath_Tests`. 

La suite `NKMath_Tests` a ensuite été exécutée avec **8 tests au total**. 

## 3. Résultats

D'après le résultat obtenu :

- **Suites de tests existantes : 60**
- **Suites exécutées : 1**
- **Suites passées : 1**
- **Tests dans la suite exécutée : 8**
- **Tests réussis : 8**
- **Assertions réussies : 499 / 499**
- **Taux de réussite : 100 %** 
## Conclusion

Le workspace désactive les tests par défaut avec `dutc(enable=True)` pour la compilation et `dute(enable=True)` pour l'exécution. Le cours précise qu'il existe 60 suites de tests. 

J’ai donc forcé l’exécution de la suite `NKMath_Tests`. Sur les 60 suites existantes, **1 seule a été exécutée et elle est passée avec 100 % de réussite**.