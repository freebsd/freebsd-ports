# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	0.12
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.redhat.com/otaylor/pango-mirror/download/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	glib-1.3.1:${PORTSDIR}/devel/glib13 \
		giconv.2:${PORTSDIR}/converters/libiconv \
		fribidi.0:${PORTSDIR}/textproc/fribidi

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-qt=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

pre-patch:
	@find ${WRKSRC} -type f | xargs ${GREP} -l iconv.h | \
		xargs ${PERL} -pi -e "s|iconv\.h|giconv.h|g"

.include <bsd.port.mk>
