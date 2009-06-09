# New ports collection makefile for:	xkbctrl
# Date created:		9 January 2000
# Whom:			Yoshiro MIHIRA <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	xkbctrl
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	unsupported/test/Xkb/programs
DISTFILES=	Imakefile xkbctrl.c

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Display and manipulate XKB keyboard controls from the commandline

DIST_SUBDIR=	xkbctrl
PLIST_FILES=	bin/xkbctrl
USE_IMAKE=	yes
USE_XORG=	x11 xkbfile
NO_WRKSUBDIR=	yes

do-extract:
		@${RM} -rf ${WRKDIR}
		@${MKDIR} ${WRKDIR}
		@for _file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${_file} ${WRKSRC}; \
		done

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
