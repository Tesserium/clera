#!/bin/sh
rm -rf clera
curl https://circleci.com/api/v1.1/project/github/Tesserium/clera/latest/artifacts \
  | grep -o -E 'https://([^"]*)' \
  | wget --verbose --input-file -
sudo mv clera /usr/local/bin/clera
sudo ln /usr/local/bin/clera /usr/local/bin/claer
sudo ln /usr/local/bin/clera /usr/local/bin/celar
sudo ln /usr/local/bin/clera /usr/local/bin/lcear
sudo chmod +x /usr/local/bin/clera
sudo chmod +x /usr/local/bin/claer
sudo chmod +x /usr/local/bin/celar
sudo chmod +x /usr/local/bin/lcear
