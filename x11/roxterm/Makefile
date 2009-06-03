# New ports collection makefile for:	roxterm
# Date created:		19 Jun 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	roxterm
PORTVERSION=	1.14.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	GTK+ 2.0 terminal emulator with tabs

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

INSTALLS_ICONS=	yes
USE_GNOME=	vte libglade2
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=install install-doc-local
.endif

.include <bsd.port.mk>
