# New ports collection makefile for:	ThemePreview-2
# Date Created:				21 Dec 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-themepreview
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/files/
DISTNAME=	ThemePreview-2-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A small application for preview your theme widgets in one small window

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
WANT_AUTOMAKE_VER=	19

PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/ThemePreview-2

pre-configure:
.for f in COPYING INSTALL depcomp install-sh missing
	@${LN} -fs ${AUTOMAKE_DIR}/${f} ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/themepreview-2 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
