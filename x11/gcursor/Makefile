# New ports collection makefile for:	gcursor
# Date created:				08 March 2004
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gcursor
PORTVERSION=	0.05
CATEGORIES=	x11 gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gcursor/

MAINTAINER=	mezz7@cox.net
COMMENT=	A mouse cursor theme selector for GNOME

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xcursor.pc:${PORTSDIR}/x11/XFree86-4-libraries
RUN_DEPENDS=	file-roller:${PORTSDIR}/archivers/fileroller

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/src/gcursor.c
	@${REINPLACE_CMD} -e 's|share/applications|share/gnome/capplets|g' \
			${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
