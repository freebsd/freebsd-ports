# Ports collection Makefile for:	gnomeres_applet
# Date created:				5 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeres_applet
PORTVERSION=	0.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.sci.fi/~syrjala/gnomeres/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
