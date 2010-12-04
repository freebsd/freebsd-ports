# New ports collection makefile for:	libcompizconfig
# Date created:				2007-08-16
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcompizconfig
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	An alternative configuration system for Compiz

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

USE_GNOME=	gnomehack intltool libxml2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	echo ${OSVERSION}
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/main.c			\
		${WRKSRC}/src/lists.c			\
		${WRKSRC}/src/filewatch.c		\
		${WRKSRC}/src/ini.c			\
		${WRKSRC}/backend/ini.c

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800501) || \
    ((${OSVERSION} >= 900000) && (${OSVERSION} < 900006))
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-compiz.cpp
.endif

.include <bsd.port.post.mk>
