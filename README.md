# 😸 S1 | Prog: Workshop 
### _Eléa Crunchant & Nolan Bourrel_

> Pour ce projet, nous avons décidé de réaliser les exercices dans l'ordre de la consigne afin de parcourir les difficultés dans l'ordre croissant. Nous avons pu ainsi obtenir des bases solides pour avancer dans les exercices les plus complexes.

---

## Ne garder que le vert (⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨             |
| ---------------------- | ----------------------- |
| ![](./images/logo.png) | ![](./output/green.png) |

Pour ce filtre, nous n'avons pas rencontré de difficulté particulière. Nous avons utilisé une petite boucle for() pour ne garder que le vert sur chacun des pixels et réduire les autres à 0.f (noir).

---

## Échanger les canaux (⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨            |
| ---------------------- | ---------------------- |
| ![](./images/logo.png) | ![](./output/swap.png) |

Idem que pour le filtre précédent, mais nous avons pu utiliser la fonction swap pour ce filtre.

---

## Noir & Blanc (⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨          |
| ---------------------- | -------------------- |
| ![](./images/logo.png) | ![](./output/bw.png) |

Pour ce filtre, nous avons manipulé des moyennes. Nous avons fait la moyenne des intensités des couleurs RGB pour chaque pixel et lui avons appliqué cette moyenne comme nouvelle valeur. 
> si chacun des canaux possède la même valeur, alors la couleur sera forcément une nuance de gris.

---

## Négatif (⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨               |
| ---------------------- | ------------------------- |
| ![](./images/logo.png) | ![](./output/negatif.png) |

Nous avons utilisé le même procédé que pour les filtres précédents mais nous avons inversé la couleur. 
> L'inversion de la couleur consiste à la remplacer par sa couleur opposée obtenue par le calcul : (1 - elle-même)

---

## Dégradé (⭐️)
| _AVANT_                           | ✨ _APRÈS_ ✨                |
| --------------------------------- | -------------------------- |
| ![](./output/black_rectangle.png) | ![](./output/gradient.png) |


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

## Miroir (⭐️⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨              |
| ---------------------- | ------------------------ |
| ![](./images/logo.png) | ![](./output/mirror.png) |


Pour ce filtre, nous avons simplement créé une inversion entre la première moitié des pixels et la dernière moitié. 

Nous avons pris le premier pixel (x, y), que nous avons stocké dans une variable. Nous avons ensuite appliqué la couleur du dernier pixel (image.width(), image.height()) à notre premier pixel. Pour finir, nous avons associé la couleur du premier pixel stocké dans la variable, au dernier pixel. 

Nous avons répété ensuite cette opération sur les pixels suivants, le pixel(x+1, y+1) et le pixel (image.width()-1, image.height()-1)

> il faut bien faire attention à ne faire ces opérations sur la moitié de l'image pour éviter de se retrouver avec une demi-inversion.

---

## Image bruitée (⭐️⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨             |
| ---------------------- | ----------------------- |
| ![](./images/logo.png) | ![](./output/bruit.png) |


Pour créer cette image bruitée, nous avons sélectectionné des pixels au hasard sur l'image et nous lui avons associé une nouvelle couleur aléatoire.

Pour ce faire, nous avons utilisé la fonction random_int et random_float :
```c++
image.pixel(random_int(0, image.width()), random_int(0, image.height())) = random_float(0, 1)
```

---

## Rotation à 90° (⭐️⭐️)
| _AVANT_                | ✨ _APRÈS_ ✨             |
| ---------------------- | ----------------------- |
| ![](./images/logo.png) | ![](./output/rotate.png) |

Lors de la création de la rotation, nous avions compris qu'il fallait déplacer les pixels. Cependant, nous n'avions pas pensé à créer une nouvelle image. Les pixels ne pouvant pas se placer dans "rien", nous avons eu une erreur que nous avons mis du temps à comprendre. 

Une fois que nous avions compris qu'il fallait créer une nouvelle image qui possède la même largeur que la hauteur de l'image originelle et la même hauteur que la largeur de l'image d'origine et associer les pixels de la nouvelle image à l'image originelle, nous avons réussi à créer notre rotation.

``` c++
sil::Image image2{image.height() /*width*/, image.width() /*height*/};
```

---

