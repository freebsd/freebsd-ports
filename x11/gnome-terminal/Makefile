# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnometerminal
PORTVERSION=	2.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-terminal/2.2
DISTNAME=	gnome-terminal-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui

.if defined(WITH_ZVT)
LIB_DEPENDS+=	zvt-2.0.0:${PORTSDIR}/x11-toolkits/libzvt
.else
LIB_DEPENDS+=	vte.4:${PORTSDIR}/x11-toolkits/vte
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.if defined(WITH_ZVT)
CONFIGURE_ARGS=	--with-widget=zvt
.else
CONFIGURE_ARGS=	--with-widget=vte
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
