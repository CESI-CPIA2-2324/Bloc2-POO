# Introduction aux QR Codes

## Qu'est-ce qu'un QR Code ?

Un QR Code (Quick Response Code) est un type de code-barres en deux dimensions constitué de carrés noirs disposés sur une grille carrée blanche. Il a été créé par l'entreprise japonaise Denso-Wave en 1994. Les QR Codes peuvent stocker des informations sous forme numérique ou alphanumérique. Ils sont souvent utilisés pour stocker des URL, des informations de contact, des calendriers, des emails, des localisations et bien plus encore. Les QR Codes peuvent être lus par un lecteur de QR Code, un smartphone ou une webcam. Ils sont devenus très populaires au Japon et sont maintenant utilisés dans le monde entier.

La version la plus récente des QR Codes est la version 40, qui peut stocker jusqu'à 4 296 caractères alphanumériques. Les QR Codes peuvent également être créés avec des niveaux de correction d'erreur différents. Il existe quatre niveaux de correction d'erreur : L (7%), M (15%), Q (25%) et H (30%). Plus le niveau de correction d'erreur est élevé, plus le QR Code peut être endommagé tout en restant lisible. Par exemple, un QR Code avec un niveau de correction d'erreur H peut être endommagé jusqu'à 30% et rester lisible.

La technologie des QR Codes est tombée dans le domaine public, ce qui signifie que n'importe qui peut créer et utiliser des QR Codes sans avoir besoin d'une licence.

## Comment fonctionnent les QR Codes ?

Les QR Codes peuvent stocker des informations sous forme numérique ou alphanumérique. Ils sont souvent utilisés pour stocker des URL, des informations de contact, des calendriers, des emails, des localisations et bien plus encore. 

### Structure d'un QR Code

Voici les principaux éléments qui composent la structure d'un QR code :

1. Motifs de positionnement: Trois carrés situés dans les coins supérieur gauche, supérieur droit et inférieur gauche permettent au lecteur de détecter la présence et l'orientation du QR code.
2. Motifs de séparation: Des marges blanches entourent les motifs de positionnement pour les séparer du reste du QR code et faciliter leur détection.
3. Motifs d'alignement: Ces motifs plus petits que les motifs de positionnement apparaissent dans les QR codes de plus grande taille pour aider à la correction des erreurs dues à la déformation.
4. Motifs de synchronisation: Une ligne alternant des pixels noirs et blancs qui traverse le QR code verticalement et horizontalement pour permettre au lecteur de déterminer la taille des pixels.
5. Zone de données: C’est ici que sont codées les informations. Le QR code utilise une grille où chaque cellule peut être noire ou blanche et représente un bit d'information.
6. Codes de correction d'erreur: Ils permettent de restaurer les données si le code est sale ou endommagé. Plus le niveau de correction d'erreur est élevé, plus la quantité d'espace utilisée pour les codes de correction d'erreur est grande.
7. Version: La version du QR code détermine la taille de la matrice de données, allant de la version 1 (21x21 pixels) à la version 40 (177x177 pixels).

8. Format d'informations: Inclut des détails sur le niveau de correction d'erreur utilisé et le masque de motif appliqué au QR code.
9. Zone calme: Il s'agit d'une marge autour du QR code qui ne contient aucun élément de design et est utilisée pour aider les lecteurs à distinguer le QR code du reste de l'environnement.
10. Modules: Chaque petit carré dans le QR code est appelé un module. Chaque module représente un bit de données.

Voici un schéma qui illustre la structure d'un QR code :


Les données sont codées dans un format spécifique qui peut inclure des informations numériques, alphanumériques, des octets/binaires ou même des caractères Kanji. Lorsqu’un QR code est scanné, le lecteur interprète cette grille modulaire en fonction des motifs standard pour décoder l'information qu'elle contient, avec l'aide des codes de correction d'erreur pour s'assurer que les données sont interprétées correctement même si une partie du QR code est endommagée ou obstruée.

## Comment générer un QR Code en Python ?

Pour générer un QR Code en Python, vous pouvez utiliser la bibliothèque `qrcode`. Voici un exemple de code qui génère un QR Code :

```python
import qrcode

qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_H,
    box_size=10,
    border=4,
)

qr.add_data('https://www.example.com')
qr.make(fit=True)

img = qr.make_image(fill='black', back_color='white')
img.save('qrcode.png')
```

Ce code génère un QR Code qui contient l'URL `https://www.example.com` et l'enregistre dans un fichier PNG appelé `qrcode.png`.

## Comment lire un QR Code en Python ?

Pour lire un QR Code en Python, vous pouvez utiliser la bibliothèque `pyzbar`. Voici un exemple de code qui lit un QR Code :

```python
from pyzbar.pyzbar import decode
from PIL import Image

img = Image.open('qrcode.png')
result = decode(img)
print(result[0].data.decode('utf-8'))
```

Ce code lit le QR Code dans le fichier PNG `qrcode.png` et affiche le résultat.

### Interpréter le résultat

Le résultat est une liste de dictionnaires. Chaque dictionnaire contient les données décodées, le type de code-barres et la position du code-barres dans l'image. Voici un exemple de résultat :

```python
[Decoded(data=b'https://www.example.com', type='QRCODE', rect=Rect(left=40, top=40, width=240, height=240), polygon=[Point(x=40, y=40), Point(x=40, y=280), Point(x=280, y=280), Point(x=280, y=40)])]
```

### Retrouver des informations spécifiques

Pour retrouver des informations spécifiques, vous pouvez utiliser les clés du dictionnaire. Voici un exemple de code qui affiche les données décodées :

```python
print(result[0].data.decode('utf-8'))
```

Ce code affiche les données décodées du premier élément de la liste.

## Conclusion

Dans ce tutoriel, vous avez appris ce qu'est un QR Code, comment générer un QR Code en Python et comment lire un QR Code en Python. Vous pouvez maintenant utiliser ces connaissances pour créer vos propres applications qui génèrent et lisent des QR Codes (en restant dans la légalité, bien sûr).