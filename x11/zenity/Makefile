# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	zenity
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Display GNOME dialogs from the command line

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomecanvas gconf2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@DATADIRNAME@|share|'

.include <bsd.port.mk>
