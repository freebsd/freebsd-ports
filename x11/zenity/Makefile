# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	zenity
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://ftp.acc.umu.se/pub/GNOME/sources/zenity/1.0/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Display GNOME dialogs from the command line

BROKEN=		"Does not compile"

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomecanvas gconf2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@DATADIRNAME@|share|'

.include <bsd.port.mk>
