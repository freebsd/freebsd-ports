# New ports collection makefile for:	gnomecore
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomecore
PORTVERSION=	1.2.4
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-core
DISTNAME=	gnome-core-${PORTVERSION}

MAINTAINER?=	ade@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		bz2.1:${PORTSDIR}/archivers/bzip2
RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/startup.wav:${PORTSDIR}/audio/gnomeaudio

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnome-session.1 gnome-wm.1 save-session.1
MAN5=		default.session.5

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
