#!/bin/sh
rm -rf clera
curl https://circleci.com/api/v1.1/project/github/Tesserium/clera/latest/artifacts \
  | grep -o -E 'https://([^"]*)' \
  | wget --verbose --input-file -
sudo mv -f clera /usr/local/bin/clera
sudo ln -f /usr/local/bin/clera /usr/local/bin/claer
sudo ln -f /usr/local/bin/clera /usr/local/bin/celar
sudo ln -f /usr/local/bin/clera /usr/local/bin/lcear
sudo ln -f /usr/local/bin/clera /usr/local/bin/cllear
sudo ln -f /usr/local/bin/clera /usr/local/bin/cleear
sudo ln -f /usr/local/bin/clera /usr/local/bin/clleear
sudo ln -f /usr/local/bin/clera /usr/local/bin/cls
sudo chmod +x /usr/local/bin/clera
sudo chmod +x /usr/local/bin/claer
sudo chmod +x /usr/local/bin/celar
sudo chmod +x /usr/local/bin/lcear
sudo chmod +x /usr/local/bin/cllear
sudo chmod +x /usr/local/bin/cleear
sudo chmod +x /usr/local/bin/clleear
sudo chmod +x /usr/local/bin/cls
