#!/usr/bin/env sh

set -e

npm run build
# navigate into the build output directory
cd docs/.vuepress/dist


git init
git add -A
git commit -m 'deploy with vuepress'

git push -f https://github.com/lee20h/TIL.git master:gh-pages

cd -