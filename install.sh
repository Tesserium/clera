#!/bin/sh
rm -rf clera
curl https://circleci.com/api/v1.1/project/github/Tesserium/clera/latest/artifacts \
  | grep -o -E 'https://([^"]*)' \
  | wget --verbose --input-file -
mv clera /usr/local/bin/clera
ln /usr/local/bin/clera /usr/local/bin/claer
ln /usr/local/bin/clera /usr/local/bin/celar
ln /usr/local/bin/clera /usr/local/bin/lcear
chmod +x /usr/local/bin/clera
chmod +x /usr/local/bin/claer
chmod +x /usr/local/bin/celar
chmod +x /usr/local/bin/lcear
