# New ports collection makefile for:   vdk
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdk
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdkbuilder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for GTK+ toolkit

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget gtk20
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-opt=no --enable-doc-html=no
INSTALLS_SHLIB=	yes

MAN1=		vdk-config-2.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.for file in vdk/FileDialog.h vdk/gtksourcebuffer.h vdk/gtksourcetag.h
	@${REINPLACE_CMD} -e 's|<regex\.h>|<gnuregex.h>|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
