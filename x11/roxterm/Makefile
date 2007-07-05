# New ports collection makefile for:	roxterm
# Date created:		19 Jun 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	roxterm
PORTVERSION=	1.5.2
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	GTK+ 2.0 terminal emulator with tabs

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

INSTALLS_ICONS=	yes
USE_GNOME=	vte libglade2
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=install install-doc-local
.endif

.include <bsd.port.mk>
