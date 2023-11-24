# 😸 S1 | Prog: Workshop 
### _Eléa Crunchant & Nolan Bourrel_

> Pour ce projet, nous avons décidé de réaliser les exercices dans l'ordre de la consigne afin de parcourir les difficultés dans l'ordre croissant. Nous avons pu ainsi obtenir des bases solides pour avancer dans les exercices les plus complexes.

---

## Ne garder que le vert (⭐️)
![](./output/green.png)

Pour ce filtre, nous n'avons pas rencontré de difficulté particulière. Nous avons utilisé une petite boucle for() pour ne garder que le vert sur chacun des pixels et réduire les autres à 0.f (noir).

---

## Échanger les canaux (⭐️)
![](./output/swap.png)


Idem que pour le filtre précédent, mais nous avons pu utiliser la fonction swap pour ce filtre.

---

## Noir & Blanc (⭐️)
![](./output/bw.png)

Pour ce filtre, nous avons manipulé des moyennes. Nous avons fait la moyenne des intensités des couleurs RGB pour chaque pixel et lui avons appliqué cette moyenne comme nouvelle valeur. 
> si chacun des canaux possède la même valeur, alors la couleur sera forcément une nuance de gris.

---

## Négatif (⭐️)
![](./output/negatif.png)

Nous avons utilisé le même procédé que pour les filtres précédents mais nous avons inversé la couleur. 
> L'inversion de la couleur consiste à la remplacer par sa couleur opposée obtenue par le calcul : (1 - elle-même)

---

## Dégradé (⭐️)
![](./output/gradient.png)

Nous avons rencontré un peu plus de difficultés en réalisant ce dégradé. En effet, nous savions que la couleur de chaque pixel dépendait de sa position x. 

Cependant, nous obtenions un grand rectangle noir et nous ne comprenions pas pourquoi le dégradé ne s'affichait pas correctement. 

Finalement, nous nous sommes rendus compte que nous avions mal implémenté notre boucle for(). Nous avions initialisé x et y comme des int et non des float. 

``` C++
for (int x{0}; x < image.width(); x++)
```
``` C++
for (float x{0.f}; x < image.width(); x++)
```

La division par des int nous donnant toujours des valeurs proches de 0 qui se convertissaient donc automatiquement en 0 ne nous donnaient que des pixels noirs et une ligne blanche.

---

