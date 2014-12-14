# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

DISTVERSION=	96.43.23
# Explicitly set PORTREVISION as it can be overridden by the master port
PORTREVISION=	2

MASTERDIR=	${.CURDIR}/../nvidia-driver
PKGNAMESUFFIX=	-96

FORBIDDEN=	vulnerable to denial of service or arbitrary code execution (CVE-2014-8298)

.include "${MASTERDIR}/Makefile"
