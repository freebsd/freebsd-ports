# New ports collection makefile for: kdelibs3-nocups
# Date created:         Tue 25 Jan 2005
# Whom:                 Michael Nottebrock
#
# $FreeBSD$

PORTNAME=		kdelibs3
PKGNAMESUFFIX=		-nocups

MAINTAINER=		kde@FreeBSD.org

MASTERDIR=		${.CURDIR}/../kdelibs3
CONFLICTS+=		kdelibs-[0-9]*

CONFIGURE_ARGS+=	--disable-cups
PLIST=			${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
