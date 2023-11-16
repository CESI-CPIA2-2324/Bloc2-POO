from pyzbar.pyzbar import decode # pip install pyzbar
from PIL import Image # pip install pillow

# Ouvrir l'image du QR code
img = Image.open('qrcode.png')

# Décoder le QR code
decoded_objects = decode(img)

# Afficher les données décodées
for obj in decoded_objects:
    print('Type : ', obj.type)
    print('Data : ', obj.data.decode('utf-8'))