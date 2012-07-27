# New ports collection makefile for:	libcompizconfig
# Date created:				2007-08-16
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcompizconfig
PORTVERSION=	0.8.4
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative configuration system for Compiz

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	libtool

USE_GNOME=	gnomehack intltool libxml2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	INOTIFY
OPTIONS_DEFAULT=	INOTIFY
INOTIFY_DESC?=	Enable inotify support

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800501) || \
    ((${OSVERSION} >= 900000) && (${OSVERSION} < 900006))
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-compiz.cpp
.endif

.if ${PORT_OPTIONS:MINOTIFY}
LIB_DEPENDS+=	inotify.0:${PORTSDIR}/devel/libinotify
LDFLAGS+=	-linotify
.endif

post-patch:
.if empty(PORT_OPTIONS:MINOTIFY)
	@${REINPLACE_CMD} -e 's|sys/inotify.h||' ${WRKSRC}/configure
.endif
	@echo "OSVERSION=${OSVERSION}"
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/main.c			\
		${WRKSRC}/src/lists.c			\
		${WRKSRC}/src/filewatch.c		\
		${WRKSRC}/src/ini.c			\
		${WRKSRC}/backend/ini.c

.include <bsd.port.post.mk>
