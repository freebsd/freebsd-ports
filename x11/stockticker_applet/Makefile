# Ports collection Makefile for:	stockticker_applet
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stockticker_applet
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_applet//}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp

USE_GNOME=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

pre-patch:
	@${PERL} -pi -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "Makefile.in" -or -name "*.make" \) | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
