# New ports collection makefile for: linux-gnomelibs
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
.if (${MACHINE_ARCH} == "i386")
PORTVERSION=	1.0.40
.elif (${MACHINE_ARCH} == "alpha")
PORTVERSION=	1.0.54
.endif

CATEGORIES=	x11 linux

MAINTAINER=	taoka@FreeBSD.org

RPM_SET=	gnome-libs-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

.if (${MACHINE_ARCH} == "i386")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/i386/RedHat/RPMS/
.elif (${MACHINE_ARCH} == "alpha")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/alpha/RedHat/RPMS/
.endif
