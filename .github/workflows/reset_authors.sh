#!/bin/sh

git filter-branch --env-filter '
    GIT_AUTHOR_NAME="ImJohnTitor";
    GIT_AUTHOR_EMAIL="<115845162+imjohntitor@users.noreply.github.com>";
    GIT_AUTHOR_NAME="ImJohnTitor";
    GIT_AUTHOR_EMAIL="<115845162+imjohntitor@users.noreply.github.com>";
' -- --all
