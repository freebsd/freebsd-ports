# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	zenity
PORTVERSION=	1.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://ftp.acc.umu.se/pub/GNOME/sources/zenity/1.0/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Display GNOME dialogs from the command line

LIB_DEPEND=	gconf-2:${PORTSDIR}/devel/gconf2 \
		gnomecanvas-2.200:${PORTSDIR}/graphics/libgnomecanvas \
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@DATADIRNAME@|share|'

.include <bsd.port.mk>
