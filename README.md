# Juan Lozano Calderón · Fuerza Alienígena

Página personal interactiva con ambientación de **Ben 10: Fuerza Alienígena**.
Taller 3: Creación de servidor web Apache en EC2 AWS · Universidad Católica de Colombia · Ing. Andrés Torres · 2026-3

- **Grupo:** Juan Lozano Calderón (trabajo individual)
- **Fecha:** 10 de octubre de 2026

## Estructura

```
sitio-juan-lozano/
├── index.html        ← la página (abre este archivo)
├── README.md
├── .nojekyll         ← para que GitHub Pages sirva todo tal cual
├── parte1/           ← fotos y música
│   ├── img/familia · img/yo · img/estudios · img/universidad
│   └── audio/        ← aquí va el MP3 del tema (ver abajo)
├── parte2/video/     ← familia e inspiración (Chicky, Bukowski, Mr. Robot, Spider-Man, Ben 10, Max Steel, Geometry Dash)
└── parte3/video/     ← series de la infancia (Ben 10 Fuerza Alienígena, Un Show Más, Hora de Aventura, Generator Rex)
```

`index.html` usa rutas relativas (`parte1/img/...`, `parte2/video/...`). Por eso **no muevas `index.html` fuera de esta carpeta** ni cambies los nombres de las carpetas: las fotos solo aparecen si `index.html` está al lado de `parte1`, `parte2` y `parte3`.

## Verla en tu PC

Descomprime el zip y abre `index.html` con doble clic. Todo funciona sin servidor.

## Subirla a GitHub (GitHub Pages)

1. En tu repositorio: **Add file → Upload files** y arrastra **el contenido** de `sitio-juan-lozano/` (index.html, README.md, .nojekyll y las carpetas parte1, parte2, parte3). `index.html` debe quedar en la raíz del repositorio.
2. **Settings → Pages → Build and deployment → Deploy from a branch → `main` / `(root)` → Save.**
3. En 1–2 minutos queda en `https://TU_USUARIO.github.io/NOMBRE_DEL_REPO/`.

Desde Git Bash también sirve:
```bash
cd sitio-juan-lozano
git init && git add . && git commit -m "Página personal Fuerza Alienígena"
git branch -M main
git remote add origin https://github.com/TU_USUARIO/NOMBRE_DEL_REPO.git
git push -u origin main
```

> GitHub distingue mayúsculas y minúsculas: `ME_BEN_10_REX_.mp4` no es lo mismo que `me_ben_10_rex_.mp4`.

## Subirla al servidor Apache de EC2 (Amazon Linux)

```bash
# Desde Git Bash en tu PC
scp -i "llave_quese_le_haya_puesto.pem" sitio-juan-lozano.zip ec2-user@IP_PUBLICA:~
ssh -i "llave_quese_le_haya_puesto.pem" ec2-user@IP_PUBLICA

# Dentro de la instancia
sudo dnf install -y httpd unzip
sudo systemctl enable --now httpd
unzip -o sitio-juan-lozano.zip
sudo cp -r sitio-juan-lozano/. /var/www/html/
sudo chown -R apache:apache /var/www/html
sudo find /var/www/html -type d -exec chmod 755 {} \;
sudo find /var/www/html -type f -exec chmod 644 {} \;
curl -I http://localhost      # HTTP/1.1 200 OK
```
Luego abre `http://IP_PUBLICA` (http, no https).

## Videos

Los videos están comprimidos (480 px) para que todo quepa en un zip de menos de 30 MB y por debajo del límite de 25 MB por archivo de la subida web de GitHub. Si quieres más calidad, **reemplaza cualquier video por tu original con exactamente el mismo nombre** en la misma carpeta (parte2/video o parte3/video). No hay que tocar `index.html`.

## Música

El tema de *Ben 10: Fuerza Alienígena* (Andy Sturmer, Cartoon Network) **no viene incluido** porque tiene derechos de autor. Si tienes el MP3, guárdalo como:

```
parte1/audio/ben10-fuerza-alienigena.mp3
```

Mientras no esté, el reproductor genera un synth "alienígena" original en el navegador. Citar la fuente no equivale a tener licencia: en un repositorio público, ese MP3 queda descargable para cualquiera.

## Por revisar

- Fotos de los colegios: si quedaron cruzadas, intercambia los nombres de `parte1/img/estudios/colegio-san-juan-de-dios.jpg` y `colegio-aldemar-rojas-plazas.jpg`.
- Asignación de fotos por hermano (pestañas Jenny, Carolina, Jorge y Fabián).
- Un repositorio público en GitHub deja las fotos familiares (incluidas las de tus sobrinos) visibles para cualquiera, de forma permanente.

## Créditos

Fotos familiares propias. Series, juegos, música, poema, logos y fotos institucionales: de sus titulares (detalle en la sección **Créditos** de la página). La ambientación es un homenaje original: no usa el logo del Omnitrix ni personajes de la serie. Mejora de imagen: Real-ESRGAN (BSD-3-Clause). Tipografías: Google Fonts (SIL OFL).
# juan-sebastian-lozano-calderon
# my_website_juan_sebastian_lozano_calderon
