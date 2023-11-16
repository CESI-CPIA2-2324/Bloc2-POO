import qrcode # installer d'abord le module qrcode

# Créer une instance de QRCode
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_H,
    box_size=10,
    border=4,
)

# Ajouter des données
qr.add_data('https://www.example.com')
qr.make(fit=True)

# Créer une image et la sauvegarder
img = qr.make_image(fill='black', back_color='white')
img.save('qrcode.png')