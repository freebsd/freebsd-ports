# New ports collection makefile for:	gnomecore
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomecore
PORTVERSION=	1.4.0.4
PORTREVISION=	3
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-core
DISTNAME=	gnome-core-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	gtkhtml.21:${PORTSDIR}/www/gtkhtml
RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share \
		--with-gtkhtml=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnome-session.1 gnome-terminal.1 gnome-wm.1 save-session.1
MAN5=		default.session.5

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
