#! /usr/bin/awk -f
# $FreeBSD$

BEGIN {
	group_number = 0
	printf "GH_TUPLE="
}

{
	account = "cylgom"
	project = $2
	gsub(".*/", "", project)
	hash = $1
	path = $2
	printf " \\\n\t%s:%s:%s:%s/%s", account, project, hash, project, path
}

END {
	printf "\n"
}
