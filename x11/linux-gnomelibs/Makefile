# New ports collection makefile for: linux-gnomelibs
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	x11 linux

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	RPM of gnome-libs

RPM_SET=	gnome-libs-${PORTVERSION}-11.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

.if (${MACHINE_ARCH} == "i386")
MASTER_SITES+= ftp://ftp.redhat.com/pub/redhat/linux/7.1/en/os/i386/RedHat/RPMS/
.elif (${MACHINE_ARCH} == "alpha")
MASTER_SITES+= ftp://ftp.redhat.com/pub/redhat/linux/7.1/en/os/alpha/RedHat/RPMS/
.endif
