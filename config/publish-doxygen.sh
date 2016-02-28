#!/bin/bash -e

openssl aes-256-cbc -K $encrypted_591a2533bcd2_key -iv $encrypted_591a2533bcd2_iv -in config/travisci_rsa.enc -out config/travisci_rsa -d
chmod 0600 config/travisci_rsa
cp config/travisci_rsa ~/.ssh/id_rsa

REPO_PATH=git@github.com:KennyRules/Gutterati.git
HTML_PATH=build/doc/html
COMMIT_USER="Documentation Builder"
COMMIT_EMAIL="drewd@code-phoenix.com"
CHANGESET=$(git rev-parse --verify HEAD)

rm -rf ${HTML_PATH}
mkdir -p ${HTML_PATH}
git clone -b gh-pages "${REPO_PATH}" --single-branch ${HTML_PATH}

cd ${HTML_PATH}
git rm -rf .
cd -

cd config
doxygen Doxyfile
cd -

cd ${HTML_PATH}
git add .
git config user.name "${COMMIT_USER}"
git config user.email "${COMMIT_EMAIL}"
git commit -m "Automated documentation build for changeset ${CHANGESET}."
git push origin gh-pages
cd -