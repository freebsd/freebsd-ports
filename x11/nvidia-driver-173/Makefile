# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

DISTVERSION=	173.14.35
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	3

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-173

FORBIDDEN=	vulnerable to denial of service or arbitrary code execution (CVE-2014-8298)

.include "${MASTERDIR}/Makefile"
