# New ports collection makefile for:	ude
# Date created:		06 Mar 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	ude
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	udeproject

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast, compact windowmanager

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.gif ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
