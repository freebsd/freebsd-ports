# New ports collection makefile for: bbpager
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbpager
PORTVERSION=	0.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://halplant.com:88/software/src/
DISTFILES=	${PORTNAME}-${PORTVERSION}-cvs.tar.gz

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A pager for the Blackbox window manager

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack pkgconfig
USE_GCC=	3.3+
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags xft`" \
		LDFLAGS="`pkg-config --libs xft`"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README.bbpager
PLIST_FILES=	bin/bbpager %%DATADIR%%/bbpager.rc
PLIST_DIRS=	%%DATADIR%% %%DOCSDIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bbpager ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/bbpager.rc ${DATADIR}/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
