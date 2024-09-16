#!/bin/sh
curl https://circleci.com/api/v1.1/project/github/Tesserium/clera/latest/artifacts \
  | grep -o -E 'https://([^"]*)' \
  | wget --verbose --input-file -
mv clera /usr/local/bin
ln /usr/local/bin/clera /usr/local/bin/claer
ln /usr/local/bin/clera /usr/local/bin/celar
ln /usr/local/bin/clera /usr/local/bin lcear
