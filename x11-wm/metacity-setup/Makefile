# New ports collection makefile for:   metacity-setup
# Date created:        23 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metacity-setup
PORTVERSION=	0.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://plastercast.tzo.com/~plastercast/Projects/ \
		http://www.marcuscom.com/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcus

MAINTAINER=	marcus@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS= --localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g'

post-patch:
	@${REINPLACE_CMD} -e 's|[%][%]X11BASE[%][%]|${X11BASE}|g' \
		${WRKSRC}/src/callbacks.c

.include <bsd.port.mk>
