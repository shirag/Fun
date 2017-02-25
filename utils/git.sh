#!/bin/bash -e
git status
commit_message="$1"
git add . -A
git commit -m "$commit_message"
git push
