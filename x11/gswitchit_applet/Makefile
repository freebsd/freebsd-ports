# Ports collection Makefile for:	gswitchit_applet
# Date created:				5 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gswitchit_applet
PORTVERSION=	0.92
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gswitchit

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	xklavier.0:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	${X11BASE}/lib/X11/xkb/rules/xfree86.xml:${PORTSDIR}/x11/xfree86_xkb_xml

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gswitchit_applet.1

pre-patch:
	@${PERL} -pi -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
