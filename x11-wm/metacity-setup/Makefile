# New ports collection makefile for:   metacity-setup
# Date created:        23 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metacity-setup
PORTVERSION=	0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://plastercast.tzo.com/~plastercast/Projects/
DISTNAME=	Metacity-setup-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		gconf-2:${PORTSDIR}/devel/gconf2

WRKSRC=	${WRKDIR}/Metacity-setup

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

pre-configure:
	${RM} -f ${WRKSRC}/install-sh ${WRKSRC}/COPYING ${WRKSRC}/INSTALL \
		${WRKSRC}/mkinstalldirs ${WRKSRC}/missing

.include <bsd.port.mk>
